#include "BattleScene.h"
#include "EnemyDatabase.h"

BattleScene::BattleScene() : player("Hero"), enemy(EnemyDatabase::createRandomEnemy()), BattleOver(false) {}

void BattleScene::update()
{
	if (!enemy.isAlive())
	{
		player.gainXp(enemy.getXPReward());
		BattleOver = true;
		return;
	}

	// temporary auto-attack logic (for demonstration)
	enemy.takeDamage(player.attack());

	if (enemy.isAlive())
	{
		player.takeDamage(enemy.getAttack());
	}
}

bool BattleScene::isFinished() const
{
	return BattleOver || player.getHp() <= 0;
}