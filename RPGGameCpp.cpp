#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Player.h"
#include "Enemy.h"


void showStats(const Player& player, const Enemy& enemy) {

	std::cout << "\n=== BATTLE STATUS ===\n";
	std::cout << player.name << " HP: " << player.hp << "\n";
	std::cout << enemy.name << " HP: " << enemy.hp << "\n\n";
}

int randomDamage(int base) {

	return base + (std::rand() % 5);     // Random damage variation
}


int main()
{

	std::srand(static_cast<unsigned int>(std::time(nullptr)));     // Seed for random number generation


	// Create Player with starting stats

	Player player;
	std::cout << "Enter your hero's name: ";
	std::getline(std::cin, player.name);

	player.level = 1;
	player.maxHp = 100;
	player.hp = player.maxHp;
	player.attack = 10;

	// Create Enemy with starting stats

	Enemy enemy;
	enemy.name = "Goblin";
	enemy.hp = 50;
	enemy.attack = 8;

	std::cout << "\nA wild " << enemy.name << " appears!\n";

	// Battle loop

	while (player.hp > 0 && enemy.hp > 0)
	{
		showStats(player, enemy);

		std::cout << "Choose your action:\n";
		std::cout << "1. Attack\n";
		std::cout << "2. Run\n";
		std::cout << "> ";

		int choice;
		std::cin >> choice;

		if (choice == 2)
		{
			std::cout << "You ran away!\n";
			return 0;
		}

		int playerDamage = randomDamage(player.attack);
		enemy.hp -= playerDamage;
		std::cout << "You hit the " << enemy.name << " for " << playerDamage << " damage!\n";

		if (enemy.hp <= 0)
		{
			std::cout << "\nYou defeated the " << enemy.name << "!\n";
			break;
		}

		int enemyDamage = randomDamage(enemy.attack);
		player.hp -= enemyDamage;
		std::cout << "The " << enemy.name << " hits you for " << enemyDamage << " damage!\n";

		if (player.hp <= 0)
		{
			std::cout << "\nYou were defeated...\n";
			break;
		}
	}

	std::cout << "\n=== GAME OVER ===\n";



	return 0;
}