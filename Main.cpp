#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>

#include "Player.h"
#include "Enemy.h"
#include "EnemyDatabase.h"
#include "ItemDatabase.h"
#include "SaveSystem.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "RPG Game");
    window.setFramerateLimit(60);


    // ======================
    // Load font
    // ======================

    sf::Font font;
    if (!font.loadFromFile("Assets/Fonts/JetBrainsMono-Regular.ttf"))
    {
        std::cout << "Failed to load font\n";
        return 1;
    }


    // ======================
    // Load player sprite
    // ======================

    sf::Texture playerTexture;
    if (!playerTexture.loadFromFile("Assets/Sprites/Reapera.png"))
    {
        std::cout << "Failed to load player texture\n";
        return 1;
    }

    sf::Sprite playerSprite(playerTexture);
    playerSprite.setPosition(100.f, 300.f);

    sf::Vector2u textureSize = playerTexture.getSize();
    float desiredSize = 128.f;

    float scaleX = desiredSize / textureSize.x;
    float scaleY = desiredSize / textureSize.y;

    playerSprite.setScale(scaleX, scaleY);
    //playerSprite.setScale(2.f, 2.f);


    // ======================
    // Load enemy sprite
    // ======================

    sf::Texture enemyTexture;
    if (!enemyTexture.loadFromFile("Assets/Sprites/slime.png"))
    {
        std::cout << "Failed to load enemy texture\n";
        return 1;
    }

    sf::Sprite enemySprite(enemyTexture);
    enemySprite.setPosition(500.f, 300.f);

    sf::Vector2u enemyTexSize = enemyTexture.getSize();
    float enemySize = 128.f;

    enemySprite.setScale(enemySize / enemyTexSize.x, enemySize / enemyTexSize.y);
    //enemySprite.setScale(2.f, 2.f);


    // ======================
    // Player HP bar
    // ======================

    float playerMaxHp = 100.f;
    float playerHp = 78.f;

    sf::RectangleShape playerHpBack({ 200.f, 20.f });
    playerHpBack.setFillColor(sf::Color(80, 80, 80));
    playerHpBack.setPosition(100.f, 260.f);

    sf::RectangleShape playerHpBar({ 200.f, 20.f });
    playerHpBar.setFillColor(sf::Color::Green);
    playerHpBar.setPosition(100.f, 260.f);


    // ======================
    // Enemy HP bar
    // ======================

    float enemyMaxHp = 50.f;
    float enemyHp = 24.f;

    sf::RectangleShape enemyHpBack({ 200.f, 20.f });
    enemyHpBack.setFillColor(sf::Color(80, 80, 80));
    enemyHpBack.setPosition(500.f, 260.f);

    sf::RectangleShape enemyHpBar({ 200.f, 20.f });
    enemyHpBar.setFillColor(sf::Color::Red);
    enemyHpBar.setPosition(500.f, 260.f);


    // ======================
    // Text
    // ======================

    sf::Text playerText("Hero 78 / 100", font, 16);
    playerText.setPosition(100.f, 235.f);

    sf::Text enemyText("Slime 24 / 50", font, 16);
    enemyText.setPosition(500.f, 235.f);


    // ======================
    // Main loop
    // ======================

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update HP bars
        playerHpBar.setSize({200.f * (playerHp / playerMaxHp), 20.f});

        enemyHpBar.setSize({200.f * (enemyHp / enemyMaxHp), 20.f});

        window.clear(sf::Color(30, 30, 30));

        window.draw(playerSprite);
        window.draw(enemySprite);

        window.draw(playerHpBack);
        window.draw(playerHpBar);
        window.draw(enemyHpBack);
        window.draw(enemyHpBar);

        window.draw(playerText);
        window.draw(enemyText);

        window.display();
    }

    return 0;
}




//
//int main()
//{
//	srand(static_cast<unsigned>(time(nullptr)));
//
//	Player player("Hero");
//
//	std::cout << "1.New Game\n2. Load Game\n> ";
//	int startChoice;
//	std::cin >> startChoice;
//	if (startChoice == 2)
//	{
//		if (!SaveSystem::load(player, "save.txt"))
//		{
//			std::cout << "Starting New Game.\n";
//		}
//	}
//
//	bool playing = true;
//
//	while (playing && player.getHp() > 0)
//	{
//		Enemy enemy = EnemyDatabase::createRandomEnemy();
//		bool enemyDefeated = false;
//		bool playerRanAway = false;
//		std::cout << "\nA wild " << enemy.getName() << " appears!\n";
//
//		while (player.getHp() > 0 && enemy.isAlive())
//		{
//			std::cout << "\n=== BATTLE STATUS ===\n";
//			std::cout << player.getName() << " HP: " << player.getHp()
//				<< "/" << player.getMaxHp()
//				<< " | LVL: " << player.getLevel()
//				<< " | XP: " << player.getXp()
//				<< "/" << player.getXpToNext() << "\n";
//			std::cout << enemy.getName() << " HP: " << enemy.getHP() << "\n";
//
//			std::cout << "\nChoose your action:\n";
//			std::cout << "1. Attack\n2. Use Item\n3. Run\n> ";
//
//			int choice;
//			std::cin >> choice;
//
//			if (choice == 1)
//			{
//				int dmg = player.attack();
//				enemy.takeDamage(dmg);
//				std::cout << "You hit the " << enemy.getName() << " for " << dmg << " damage!\n";
//			}
//			else if (choice == 2)
//			{
//				std::cout << "\nInventory:\n";
//				player.showInventory();
//
//				if (player.getInventorySize() == 0) {
//					std::cout << "You have no items! Choose another action.\n";
//					continue;
//				}
//
//				std::cout << "> ";
//				int item;
//				std::cin >> item;
//				player.useItem(item - 1);
//			}
//			else if (choice == 3)
//			{
//				playerRanAway = true;
//				break;
//			}
//
//			if (enemy.isAlive())
//			{
//				int dmg = enemy.getAttack();
//				player.takeDamage(dmg);
//				std::cout << "The " << enemy.getName() << " hits you for " << dmg << " damage!\n";
//			}
//			else {
//				enemyDefeated = true;
//				break;
//			}
//		}
//
//		if (enemyDefeated)
//		{
//			std::cout << "\nYou defeated the " << enemy.getName() << "\n";
//			player.gainXp(enemy.getXPReward());
//			EnemyDatabase::dropLoot(enemy, player);
//			SaveSystem::save(player, "save.txt");
//		}
//		else if (playerRanAway)
//		{
//			std::cout << "You ran away!\n";
//		}
//		else if (player.getHp() <= 0)
//		{
//			std::cout << "\nYou were defeated...\n";
//			break;
//		}
//
//		std::cout << "\nWhat do you want to do next?\n";
//		std::cout << "1. Fight another enemy\n";
//		std::cout << "2. Quit game\n> ";
//		int next;
//		std::cin >> next;
//		if (next != 1)
//		{
//			playing = false;
//			SaveSystem::save(player, "save.txt");
//		}
//
//	}
//
//
//
//	
//
//
//	
//
//	return 0;
//}