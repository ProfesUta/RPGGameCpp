#pragma once
#include <string>
#include <vector>
#include "Item.h"

struct Player
{
	std::string name;
	int hp;
	int maxHp;
	int attack;
	int level;
	int xp;
	int xpToNextLevel;

	std::vector<Item> inventory;
};