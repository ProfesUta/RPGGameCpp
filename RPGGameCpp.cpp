#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Player.h"
#include "Enemy.h"


void showStats(const Player& player, const Enemy& enemy) {

	std::cout << "\n=== BATTLE STATUS ===\n";
	std::cout << player.name << " HP: " << player.hp << "/" << player.maxHp << " | LVL: " << player.level << " | XP: " << player.xp << "/" << player.xpToNextLevel << "\n";
	std::cout << enemy.name << " HP: " << enemy.hp << "\n\n";
}

int randomDamage(int base) {

	return base + (std::rand() % 5);     // Random damage variation
}

void levelUp(Player& player) {

	player.level++;
	player.xp = 0;
	player.xpToNextLevel += 50;

	player.maxHp += 20;
	player.attack += 5;
	player.hp = player.maxHp;

	std::cout << "\n  Level UP!  \n";
	std::cout << "You are now Level " << player.level << "!\n";
	std::cout << "Max HP increased to " << player.maxHp << "\n";
	std::cout << "Attack increased to " << player.attack << "\n\n";
}


int main()
{

	std::srand(static_cast<unsigned int>(std::time(nullptr)));     // Seed for random number generation


	// Create Player with starting stats

	Player player;
	std::cout << "Enter your hero's name: ";
	std::getline(std::cin, player.name);

	player.level = 1;
	player.xp = 0;
	player.xpToNextLevel = 100;
	player.maxHp = 100;
	player.hp = player.maxHp;
	player.attack = 10;

	// creating potion and pushing into players inventory

	Item potion;
	potion.name = "Health Potion";
	potion.type = ItemType::Potion;
	potion.power = 30;

	player.inventory.push_back(potion);

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
		std::cout << "2. Use Item\n";
		std::cout << "3. Run\n";
		std::cout << "> ";

		int choice;
		std::cin >> choice;

		if (choice == 3)
		{
			std::cout << "You ran away!\n";
			return 0;
		}

		bool playerUsedItem = false;

		if (choice == 2)
		{
			if (player.inventory.empty())
			{
				std::cout << "Your inventory is empty!\n";
				continue;
			}

			std::cout << "\nInventory:\n";
			for (size_t i = 0; i < player.inventory.size(); i++)
			{
				std::cout << i + 1 << ". " << player.inventory[i].name << "\n";
			}

			std::cout << "> ";
			size_t itemChoice;
			std::cin >> itemChoice;

			if (itemChoice < 1 || itemChoice > player.inventory.size())
			{
				std::cout << "Invalid Item!\n";
				continue;
			}

			Item item = player.inventory[itemChoice - 1];

			if (item.type == ItemType::Potion)
			{
				player.hp += item.power;
				if (player.hp > player.maxHp)
				{
					player.hp = player.maxHp;
				}

				std::cout << "You used " << item.name << " and recovered " << item.power << " HP!\n";
				player.inventory.erase(player.inventory.begin() + (itemChoice - 1));
				playerUsedItem = true;
			}
			
			// enemy still attacks after item use
		}

		if (!playerUsedItem)
		{
			int playerDamage = randomDamage(player.attack);
			enemy.hp -= playerDamage;
			std::cout << "You hit the " << enemy.name << " for " << playerDamage << " damage!\n";
		}

		if (enemy.hp <= 0)
		{
			std::cout << "\nYou defeated the " << enemy.name << "!\n";

			int gainedXP = 50;
			player.xp += gainedXP;
			std::cout << "You gained " << gainedXP << " XP!\n";

			if (player.xp >= player.xpToNextLevel)
			{
				levelUp(player);
			}

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