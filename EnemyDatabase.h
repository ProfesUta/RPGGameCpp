#pragma once
#include "Enemy.h"
#include <vector>

class EnemyDatabase {
public:
	static Enemy createGoblin();
	static Enemy createSlime();
	static Enemy createOrc();
	static Enemy createWolf();















	static Enemy createRandomEnemy();
};