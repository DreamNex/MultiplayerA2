#include "missile.h"
#include "ship.h"
#include <hge.h>
#include <hgeSprite.h>
#include <math.h>

extern float GetAbsoluteMag( float num );


Missile::Missile(char* filename, float x, float y, float w, int shipid ) :
	angular_velocity(0)
{
	HGE* hge = hgeCreate(HGE_VERSION);
	tex_ = hge->Texture_Load(filename);
	hge->Release();
	sprite_.reset(new hgeSprite(tex_, 0, 0, 40, 20));
	sprite_->SetHotSpot(20,10);
	x_ = x;
	y_ = y;
	w_ = w;
	ownerid = shipid;

	velocity_x_ = 200.0f * cosf(w_);
	velocity_y_ = 200.0f * sinf(w_); 

	x_ += velocity_x_ * 0.5;
	y_ += velocity_y_ * 0.5;

}

Missile::~Missile()
{
	HGE* hge = hgeCreate(HGE_VERSION);
	hge->Texture_Free(tex_);
	hge->Release();
}

bool Missile::Update(std::vector<Ship*> &shiplist, float timedelta)
{
	HGE* hge = hgeCreate(HGE_VERSION);
	float pi = 3.141592654f*2;
	float oldx, oldy;

	w_ += angular_velocity * timedelta;
	if (w_ > pi)
		w_ -= pi;

	if (w_ < 0.0f)
		w_ += pi;

	oldx = x_;
	oldy = y_;
	x_ += velocity_x_ * timedelta;
	y_ += velocity_y_ * timedelta;

	for (std::vector<Ship*>::iterator thisship = shiplist.begin();
		thisship != shiplist.end(); thisship++)
	{
		if( HasCollided( (*(*thisship)) ) )
		{
			return true;
		}
	}

	
	float screenwidth = static_cast<float>(hge->System_GetState(HGE_SCREENWIDTH));
	float screenheight = static_cast<float>(hge->System_GetState(HGE_SCREENHEIGHT));
	float spritewidth = sprite_->GetWidth();
	float spriteheight = sprite_->GetHeight();
	if (x_ < -spritewidth/2)
		x_ += screenwidth + spritewidth;
	else if (x_ > screenwidth + spritewidth/2)
		x_ -= screenwidth + spritewidth;

	if (y_ < -spriteheight/2)
		y_ += screenheight + spriteheight;
	else if (y_ > screenheight + spriteheight/2)
		y_ -= screenheight + spriteheight;

	return false;
}

void Missile::Render()
{
	sprite_->RenderEx(x_, y_, w_);
}

bool Missile::HasCollided( Ship &ship )
{
	sprite_->GetBoundingBox( x_, y_, &collidebox);

	return collidebox.Intersect( ship.GetBoundingBox() );
}