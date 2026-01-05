#pragma once
#include "Player.h"
#include "Enemy.h"

class BattleScene
{
public:
	BattleScene();

	void update();
	bool isFinished() const;

private:
	Player player;
	Enemy enemy;
	bool BattleOver;
};