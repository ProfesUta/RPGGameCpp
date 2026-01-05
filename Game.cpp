#include "Game.h"


Game::Game() : window(sf::VideoMode(1280, 720), "RPG Game", sf::Style::Close)
{
	window.setFramerateLimit(60);
	
	view = sf::View(sf::FloatRect(0.f, 0.f, 320.f, 180.f));
	window.setView(view);
}

void Game::run()
{
	// Main loop
	while (window.isOpen())
	{
		processEvents();
		update();
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) {
			window.close();
		}
	}
}

void Game::update()
{
	// Update game logic here
}

void Game::render()
{
	window.clear(sf::Color(30, 30, 30));
	// Draw game objects here
	window.display();
}