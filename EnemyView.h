#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"

class EnemyView
{
private:
    Enemy& enemy;

    sf::Sprite sprite;
    sf::Texture texture;

    sf::RectangleShape hpBack;
    sf::RectangleShape hpBar;

    sf::Text nameText;

    sf::Vector2f position;

public:
    EnemyView(Enemy& enemy, sf::Font& font);

    void setPosition(const sf::Vector2f& pos);
    void update();
    void draw(sf::RenderWindow& window);
};