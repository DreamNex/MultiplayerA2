#ifndef _APPLICATION_H_
#define _APPLICATION_H_

#include "ship.h"
#include "missile.h"
#include <vector>

class HGE;
class RakPeerInterface;

//! The default angular velocity of the ship when it is in motion
static const float DEFAULT_ANGULAR_VELOCITY = 3.0f; 
//! The default acceleration of the ship when powered
static const float DEFAULT_ACCELERATION = 50.0f;

/**
* The application class is the main body of the program. It will
* create an instance of the graphics engine and execute the
* Update/Render cycle.
*
*/

class Application
{
	HGE* hge_; //!< Instance of the internal graphics engine
	typedef std::vector<Ship*> ShipList;  //!< A list of ships
	ShipList ships_; //!< List of all the ships in the universe
	RakPeerInterface* rakpeer_;
	unsigned int timer_;
	
	// Lab 13 Task 1 : add variables for local missle
	Missile *missile;
	bool have_missile;
	bool keydown_enter;

	// Lab 13 Task 8 : add variables to handle networked missiles
	typedef std::vector<Missile*> MissileList;
	MissileList missiles_;

	bool Init();
	static bool Loop();
	void Shutdown();
	bool checkCollisions(Ship* ship);
	void ProcessWelcomePackage();
	bool SendInitialPosition();

	// Lab 13
	void CreateMissile( float x, float y, float w, int id );
	bool RemoveMissile( float x, float y, float w, int id );

	void SendCollision( Ship* ship );

public:
	Application();
	~Application() throw();

	void Start();
	bool Update();
	void Render();
};

#endif