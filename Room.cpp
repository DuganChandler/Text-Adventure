#include "Room.h"



Room::Room()
{
}


Room::~Room()
{
}

string Room::EnterRoom(Room * next)
{
	return next->DisplayText;
}
