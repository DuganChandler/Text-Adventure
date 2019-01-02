#pragma once
#include <string>
#include <utility>
#include <iostream>
#include <stdlib.h>


using namespace std;
class Room
{
public:
	Room();
	~Room();
	string EnterRoom(Room* next);
	Room* NorthExit;
	Room* SouthExit;
	Room* EastExit;
	Room* WestExit;



	string DisplayText; // this will be the text that shows when you enter a room
	
	pair<string, string> RequiredItemOrStat;
	// Pairs can hold two items
	// RequiredItemOrStat.first
	// RequiredItemOrStat.second
	// What's inside the <>s determines what the pair holds
	// a pair can be made up of any two data types
	string RoomItem;
};

