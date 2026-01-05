#include "PlayerView.h"
#include <iostream>

static constexpr float HP_BAR_WIDTH = 32.f;
static constexpr float HP_BAR_HEIGHT = 4.f;

PlayerView::PlayerView(Player& p, sf::Font& font) : player(p)
{
    texture.setSmooth(false);
    if (!texture.loadFromFile("Assets/Sprites/Reapera.png"))
    {
        std::cout << "Failed to load player sprite\n";
    }

    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y);
    sprite.setScale(0.125f, 0.125f);

    // HP bar background
    hpBack.setSize({ HP_BAR_WIDTH, HP_BAR_HEIGHT });
    hpBack.setFillColor(sf::Color(40, 40, 40));

    // HP bar fill
    hpBar.setSize({ HP_BAR_WIDTH, HP_BAR_HEIGHT });
    hpBar.setFillColor(sf::Color::Green);

    // HP text
    hpText.setFont(font);
    hpText.setCharacterSize(8);
    hpText.setFillColor(sf::Color::White);
}

void PlayerView::setPosition(const sf::Vector2f& pos)
{
    position = pos;
    sprite.setPosition(position);
}

void PlayerView::update()
{
    float hpPercent = static_cast<float>(player.getHp()) / player.getMaxHp();

    hpBar.setSize({ HP_BAR_WIDTH * hpPercent, HP_BAR_HEIGHT });

    // UI offsets relative to player
    sf::Vector2f barOffset(-HP_BAR_WIDTH / 2.f, -50.f);
    sf::Vector2f textOffset(-HP_BAR_WIDTH / 2.f, -60.f);

    hpBack.setPosition(position + barOffset);
    hpBar.setPosition(position + barOffset);

    hpText.setString(player.getName() + " " + std::to_string(player.getHp()) + "/" + std::to_string(player.getMaxHp()));

    hpText.setPosition(position + textOffset);
}

void PlayerView::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
    window.draw(hpBack);
    window.draw(hpBar);
    window.draw(hpText);
}