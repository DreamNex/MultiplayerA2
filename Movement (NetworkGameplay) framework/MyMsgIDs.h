#ifndef MYSMSGIDS_H_
#define MYSMSGIDS_H_

#include "MessageIdentifiers.h"

enum MyMsgIDs
{
	ID_WELCOME = ID_USER_PACKET_ENUM,
	ID_NEWSHIP,
	ID_LOSTSHIP,
	ID_INITIALPOS,
	ID_MOVEMENT,
	ID_COLLIDE,
	// Lab 13 Task 7 : Add new messages
	ID_NEWMISSILE,
	ID_UPDATEMISSILE,
};

#endif