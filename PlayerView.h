#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class PlayerView
{
public:
	PlayerView(Player& player, sf::Font& font);

	void setPosition(const sf::Vector2f& position);
	void update();
	void draw(sf::RenderWindow& window);

private:
	Player& player;

	sf::Sprite sprite;
	sf::Texture texture;

	sf::RectangleShape hpBack;
	sf::RectangleShape hpBar;

	sf::Text hpText;
	sf::Vector2f position;
};