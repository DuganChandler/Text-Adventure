#include "Hero.h"



Hero::Hero()
{
}


Hero::~Hero()
{
}

void Hero::AddToInventory(string item)
{
	inventory.push_back(item);
	// what push back is doing is pushing the item to the back of the list
}

void Hero::RemoveFromInventory(string item, bool all)
{
	if (all == true) 
		// ( 6 == 3) < this isn't true - checking
		// ( 6 = 3) < this will be true - assigning/setting
	{	
		inventory.clear();
	}
	else 
	{
		for (int i = 0 /* this is the starting point */; /* this is the starting point */ i < inventory.size();/* this is how we continue */  i++)
		{
			if (inventory[i] == item)
			{
				inventory[i] = "";
			}
		}
	}
}
