#include <SFML/Graphics.hpp>
#include <iostream>

#include "Player.h"
#include "PlayerView.h"
#include "EnemyView.h"
#include "EnemyDatabase.h"

int main()
{
    const int BASE_WIDTH = 320;
	const int BASE_HEIGHT = 180;
	const int SCALE = 4;

    sf::RenderWindow window(sf::VideoMode(BASE_WIDTH * SCALE, BASE_HEIGHT * SCALE), "RPG Game", sf::Style::Close);

    window.setFramerateLimit(60);

    sf::View view(sf::FloatRect(0.f, 0.f, BASE_WIDTH, BASE_HEIGHT));
    window.setView(view);

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
    // Game Objects
    // ======================

    Player player("Hero");

    PlayerView playerView(player, font);
    playerView.setPosition({ 80.f, 140.f });



    Enemy enemy = EnemyDatabase::createSlime();
    EnemyView enemyView(enemy, font);
    enemyView.setPosition({ 240.f, 140.f });



    // ======================
    // Main loop
    // ======================

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }


        playerView.update();
        enemyView.update();
        window.clear(sf::Color(30, 30, 30));

        playerView.draw(window);
        enemyView.draw(window);
        window.display();
    }

    return 0;
}