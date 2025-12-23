#pragma once
#include <string>

struct Player
{
	std::string name;
	int hp;
	int maxHp;
	int attack;
	int level;
	int xp;
	int xpToNextLevel;
};