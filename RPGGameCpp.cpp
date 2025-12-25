#include <iostream>
#include <ctime>

#include "Player.h"
#include "Enemy.h"
#include "EnemyDatabase.h"
#include "ItemDatabase.h"

int main()
{
	srand(static_cast<unsigned>(time(nullptr)));

	Player player("Hero");
	player.addItem(ItemDatabase::createHealthPotion());

	bool playing = true;

	while (playing && player.getHp() > 0)
	{
		Enemy enemy = EnemyDatabase::createRandomEnemy();
		bool enemyDefeated = false;
		bool playerRanAway = false;
		std::cout << "\nA wild " << enemy.getName() << " appears!\n";

		while (player.getHp() > 0 && enemy.isAlive())
		{
			std::cout << "\n=== BATTLE STATUS ===\n";
			std::cout << player.getName() << " HP: " << player.getHp()
				<< "/" << player.getMaxHp()
				<< " | LVL: " << player.getLevel()
				<< " | XP: " << player.getXp()
				<< "/" << player.getXpToNext() << "\n";
			std::cout << enemy.getName() << " HP: " << enemy.getHP() << "\n";

			std::cout << "\nChoose your action:\n";
			std::cout << "1. Attack\n2. Use Item\n3. Run\n> ";

			int choice;
			std::cin >> choice;

			if (choice == 1)
			{
				int dmg = player.attack();
				enemy.takeDamage(dmg);
				std::cout << "You hit the " << enemy.getName() << " for " << dmg << " damage!\n";
			}
			else if (choice == 2)
			{
				std::cout << "\nInventory:\n";
				player.showInventory();

				if (player.getInventorySize() == 0) {
					std::cout << "You have no items! Choose another action.\n";
					continue;
				}

				std::cout << "> ";
				int item;
				std::cin >> item;
				player.useItem(item - 1);
			}
			else if (choice == 3)
			{
				//std::cout << "You ran away!\n";
				playerRanAway = true;
				break;
			}

			if (enemy.isAlive())
			{
				int dmg = enemy.getAttack();
				player.takeDamage(dmg);
				std::cout << "The " << enemy.getName() << " hits you for " << dmg << " damage!\n";
			}
			else {
				enemyDefeated = true;
				break;
			}
		}

		if (enemyDefeated)
		{
			std::cout << "\nYou defeated the " << enemy.getName() << "\n";
			player.gainXp(enemy.getXPReward());
		}
		else if (playerRanAway)
		{
			std::cout << "You ran away!\n";
		}
		else if (player.getHp() <= 0)
		{
			std::cout << "\nYou were defeated...\n";
			break;
		}

		std::cout << "\nWhat do you want to do next?\n";
		std::cout << "1. Fight another enemy\n";
		std::cout << "2. Quit game\n> ";
		int next;
		std::cin >> next;
		if (next != 1)
		{
			playing = false;
		}

	}



	


	

	return 0;
}