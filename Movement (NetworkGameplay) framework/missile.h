#ifndef _MISSILE_H_
#define _MISSILE_H_

#include <hge.h>
#include <hgerect.h>
#include <memory>
#include <vector>

class hgeSprite;
class hgeRect;
class Ship;

class Missile
{
	HTEXTURE tex_; //!< Handle to the sprite's texture
	std::auto_ptr<hgeSprite> sprite_; //!< The sprite used to display the ship
	float x_; //!< The x-ordinate of the ship
	float y_; //!< The y-ordinate of the ship
	float w_; //!< The angular position of the ship
	float velocity_x_; //!< The resolved velocity of the ship along the x-axis
	float velocity_y_; //!< The resolved velocity of the ship along the y-axis
	hgeRect collidebox;
	int ownerid;

public:
	float angular_velocity;
	Missile(char* filename, float x, float y, float w, int shipid);
	~Missile();
	bool Update(std::vector<Ship*> &shiplist, float timedelta);
	void Render();
	bool HasCollided( Ship &ship );

	void UpdateLoc( float x, float y, float w )
	{
		x_ = x;
		y_ = y;
		w_ = w;
	}

	int GetOwnerID()
	{
		return ownerid;
	}

	float GetX() const
	{
		return x_;
	}

	float GetY() const
	{
		return y_;
	}

	float GetW() const
	{
		return w_;
	}
	
	float GetVelocityX() { return velocity_x_; }
	float GetVelocityY() { return velocity_y_; }

	void SetVelocityX( float velocity ) { velocity_x_ = velocity; }
	void SetVelocityY( float velocity ) { velocity_y_ = velocity; }

};

#endif