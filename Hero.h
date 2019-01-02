#pragma once
#include <vector>
#include <string>
// vectors are a Data structure type 
// Data structures are objects of code that are like lsits

using namespace std;
class Hero
{
public:
	Hero();
	~Hero();
	// TODO: Add to my inventory
	void AddToInventory(string item);
	// Remove from my inventory
	void RemoveFromInventory(string item, bool all);
	// setting a paremeter in the definition
	// that means we don't have to set it when calling a funtion
	// RemoveFromInventory(key); removes only key
	// RemoveFromInvetnory(key, true); removes key AND everything else

	int Jump = 1;
	int Stealth = 1;
	int Level = 1;
	int Block = 1;
	int Health = 1;
	int Skillpoints = 10;
	int Speed = 1;
	int Attack = 1;

	vector<string> inventory;

};