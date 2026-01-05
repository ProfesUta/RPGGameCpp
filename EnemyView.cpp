#include "EnemyView.h"
#include <iostream>

EnemyView::EnemyView(Enemy& enemy, sf::Font& font)
    : enemy(enemy)
{
    // Load texture
    if (!texture.loadFromFile("Assets/Sprites/slime.png"))
    {
        std::cout << "Failed to load enemy texture\n";
    }
    texture.setSmooth(false);

    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y);
    sprite.setScale(0.125f, 0.125f);

    // HP bar background
    hpBack.setSize({ 60.f, 6.f });
    hpBack.setFillColor(sf::Color(50, 50, 50));

    // HP bar
    hpBar.setSize({ 60.f, 6.f });
    hpBar.setFillColor(sf::Color::Red);

    // Text
    nameText.setFont(font);
    nameText.setCharacterSize(8);
    nameText.setFillColor(sf::Color::White);
}

void EnemyView::setPosition(const sf::Vector2f& pos)
{
    position = pos;
	sprite.setPosition(position);
}

void EnemyView::update()
{
    float hpPercent =
        static_cast<float>(enemy.getHP()) / enemy.getMaxHP();

    hpBar.setSize({ 60.f * hpPercent, 6.f });

    sf::Vector2f hpOffset(0.f, -40.f);

    hpBack.setPosition(position + hpOffset);
    hpBar.setPosition(position + hpOffset);

    nameText.setString(
        enemy.getName() + " " +
        std::to_string(enemy.getHP()) + " / " +
        std::to_string(enemy.getMaxHP())
    );

    nameText.setPosition(position + sf::Vector2f(-30.f, -55.f));
}

void EnemyView::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(hpBack);
    window.draw(hpBar);
    window.draw(nameText);
}
