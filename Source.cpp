#include <stdlib.h>
#include <iostream>
#include <string>
#include "Hero.h"
#include "Room.h"

using namespace std;
string GetInput();
Hero CreateHero();
Room CreateRooms();

// When we have a return type that has an &
// it means we're making something in that fucntion
// that's going to last for as long as the program

int main()
{
	string command;
	Hero JimTheKnight;
	JimTheKnight = CreateHero();
	Room CurrentRoom;
	CurrentRoom = CreateRooms();
	cout << CurrentRoom.EnterRoom(&CurrentRoom) << endl;
	command = GetInput();
	while (command != "Exit Dungeon") 
	{
		if (command == "Pickup" || command == CurrentRoom.RoomItem)
		{
			JimTheKnight.AddToInventory(CurrentRoom.RoomItem);
			cout << "You got the " + CurrentRoom.RoomItem << endl;
		}
		if (command == "East")
		{
			if (CurrentRoom.EastExit->RequiredItemOrStat.first == "Item" || CurrentRoom.EastExit->RequiredItemOrStat.first == "Stat")
			{
				for(int i = 0; i < JimTheKnight.inventory.size(); i++)
				{
					if (JimTheKnight.inventory[i] == CurrentRoom.EastExit->RequiredItemOrStat.second)
					{
						cout << CurrentRoom.EnterRoom(CurrentRoom.EastExit) << endl;
						CurrentRoom = *CurrentRoom.EastExit;
					}
					else
						cout << "You don't have the right item or stat to enter" << endl;
				}
				if (JimTheKnight.inventory.size() == 0)
					cout << "You don't have the right item or stat to enter" << endl;
			}
			else
			{
				cout << CurrentRoom.EnterRoom(CurrentRoom.EastExit) << endl;
				CurrentRoom = *CurrentRoom.EastExit;
			}
		}
		if (command == "West")
		{
			if (CurrentRoom.WestExit->RequiredItemOrStat.first == "Item" || CurrentRoom.WestExit->RequiredItemOrStat.first == "Stat")
			{
				for (int i = 0; i < JimTheKnight.inventory.size(); i++)
				{
					if (JimTheKnight.inventory[i] == CurrentRoom.WestExit->RequiredItemOrStat.second)
					{
						cout << CurrentRoom.EnterRoom(CurrentRoom.WestExit) << endl;
						CurrentRoom = *CurrentRoom.WestExit;
					}
					else
						cout << "You don't have the right item or stat to enter" << endl;
				}
				if (JimTheKnight.inventory.size() == 0)
					cout << "You don't have the right item or stat to enter" << endl;
			}
			else
			{
				cout << CurrentRoom.EnterRoom(CurrentRoom.WestExit) << endl;
				CurrentRoom = *CurrentRoom.WestExit;
			}
		}
		if (command == "North")
		{
			if (CurrentRoom.NorthExit->RequiredItemOrStat.first == "Item" || CurrentRoom.NorthExit->RequiredItemOrStat.first == "Stat")
			{
				for (int i = 0; i < JimTheKnight.inventory.size(); i++)
				{
					if (JimTheKnight.inventory[i] == CurrentRoom.NorthExit->RequiredItemOrStat.second)
					{
						cout << CurrentRoom.EnterRoom(CurrentRoom.NorthExit) << endl;
						CurrentRoom = *CurrentRoom.NorthExit;
					}
					else
						cout << "You don't have the right item or stat to enter" << endl;
				}
				if (JimTheKnight.inventory.size() == 0)
					cout << "You don't have the right item or stat to enter" << endl;
			}
			else
			{
				cout << CurrentRoom.EnterRoom(CurrentRoom.NorthExit) << endl;
				CurrentRoom = *CurrentRoom.NorthExit;
			}
		}
		if (command == "South")
		{
			if (CurrentRoom.SouthExit->RequiredItemOrStat.first == "Item" || CurrentRoom.SouthExit->RequiredItemOrStat.first == "Stat")
			{
				for (int i = 0; i < JimTheKnight.inventory.size(); i++)
				{
					if (JimTheKnight.inventory[i] == CurrentRoom.SouthExit->RequiredItemOrStat.second)
					{
						cout << CurrentRoom.EnterRoom(CurrentRoom.SouthExit) << endl;
						CurrentRoom = *CurrentRoom.SouthExit;
					}
					else
						cout << "You don't have the right item or stat to enter" << endl;
				}
				if (JimTheKnight.inventory.size() == 0)
					cout << "You don't have the right item or stat to enter" << endl;
			}
			else
			{
				cout << CurrentRoom.EnterRoom(CurrentRoom.SouthExit) << endl;
				CurrentRoom = *CurrentRoom.SouthExit;
			}
		}
		command = GetInput();
	}
	

	cout << "We've Exited the Dungeon." << endl;
	return 0;
}


string GetInput()
{
	string command;
	char s[1000];
		// chars are the old way of making strings, some functions still require chars instead of strings
		if (!cin.fail())
		{
			// While - conditional loop - whats inside the ()s is the conditon
			// this means, that while the condition is true the code inside the {}s will still run

			// ! - not - we can use like != - not equals - !true - not true - !false - not false

			// cin.fail - C code inout - we are recieving input from the user making sure that they didnt innput anything that will break the code
			// like not putting in anything at all or too many inputs

			// while (this is true) { run this code; }
			cin.getline(s, 1000);
			// C input get line - reading in one whole line from the user up to 1000 characters
			if (!cin.fail())
			{

				// if - conditionals - they only check the conditional one time
				// per frame
				// if (this is true { run this code;}


				//cin.fail becase we want to make sure we didnt break cin
				command = s;
				//this is setting our new stringto our old string
			}
		}

	return command;
}

Hero CreateHero()
{
	// TODO: insert return statement here
	Hero MyHero;
	MyHero.Attack = 5;
	MyHero.Block = 6;
	MyHero.Health = 100;
	MyHero.Jump = 10;
	MyHero.Level = 1;
	MyHero.Skillpoints = 10;
	MyHero.Speed = 10;
	MyHero.Stealth = 20;

	return MyHero;

}

Room CreateRooms()
{
	// TODO: insert return statement here

	Room *FirstRoom = new Room();
	FirstRoom->DisplayText = " Welcome to the first room. \nThere are 4 exits. \nOne to the North, East, South and West. \nChoose wisely.";
	FirstRoom->RoomItem = "Corpse";


	// EAST ROOM
	Room *FirstRoomEast = new Room();
	FirstRoomEast->DisplayText = "Here is the East Room. Pretty Lame is it not?";
	FirstRoomEast->RequiredItemOrStat = make_pair("Item", "Corpse");
	FirstRoomEast->WestExit = FirstRoom;
	FirstRoom->EastExit = FirstRoomEast;
	
	// WEST ROOM
	Room *FirstRoomWest = new Room();
	FirstRoomWest->DisplayText = "This room is useless. Even more useless than you.";
	FirstRoomWest->EastExit = FirstRoom;
	FirstRoom->WestExit = FirstRoomWest;

	// SOUTH ROOM
	Room *FirstRoomSouth = new Room();
	FirstRoomSouth->DisplayText = "Oh no! There be a ninja here. Kill it!!";
	FirstRoomSouth->NorthExit = FirstRoom;
	FirstRoom->SouthExit = FirstRoomSouth;



	// North ROOM
	Room *FirstRoomNorth = new Room();
	FirstRoomNorth->DisplayText = "There is a fountain in this room. Just a fountain. Nothing special.";
	FirstRoomNorth->SouthExit = FirstRoom;
	FirstRoom->NorthExit = FirstRoomNorth;


	return *FirstRoom;
}
