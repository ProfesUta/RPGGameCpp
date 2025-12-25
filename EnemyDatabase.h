#pragma once
#include "Enemy.h"
#include "Player.h" // Add this include to resolve Player type
#include <vector>

class EnemyDatabase {
public:
	static Enemy createGoblin();
	static Enemy createSlime();
	static Enemy createOrc();
	static Enemy createWolf();




	static void dropLoot(const Enemy& enemy, Player& player);

	static Enemy createRandomEnemy();
};