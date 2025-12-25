#include "EnemyDatabase.h"
#include "ItemDatabase.h"

#include <iostream>
#include <cstdlib>

Enemy EnemyDatabase::createGoblin() {
	return Enemy("Goblin", 30, 6, 25);
}

Enemy EnemyDatabase::createSlime() {
	return Enemy("Slime", 20, 4, 15);
}

Enemy EnemyDatabase::createOrc() {
	return Enemy("Orc", 50, 10, 40);
}

Enemy EnemyDatabase::createWolf() {
	return Enemy("Wolf", 35, 10, 40);
}













Enemy EnemyDatabase::createRandomEnemy() {
	int roll = rand() % 4;

	switch(roll) {
		case 0:
			return createSlime();
		case 1:
			return createGoblin();
		case 2:
			return createOrc();
		case 3:
			return createWolf();
		default:
			return createSlime();
	}
}

void EnemyDatabase::dropLoot(const Enemy& enemy, Player& player) {
	int roll = rand() % 100;

	if (enemy.getName() == "Slime")
	{
		if (roll < 25)
		{
			player.addItem(ItemDatabase::createManaPotion());
			std::cout << "The Slime dropped a Mana Potion!\n";
		}
	}
	else if (enemy.getName() == "Orc")
	{
		if (roll < 25)
		{
			player.addItem(ItemDatabase::createHealthPotion());
			std::cout << "The Orc dropped a Health Potion!\n";
		}
	}
}