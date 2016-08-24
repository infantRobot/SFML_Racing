#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>

#include "Car.hpp"
#include "Drawable.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800,800), "Racing Game");
	window.setFramerateLimit(60);
	Car player;
	sf::Clock clock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.KeyPressed == sf::Keyboard::Escape)
				window.close();
		}
		player.UpdateCar(clock.restart().asSeconds());

		window.clear();
		window.draw(player.m_draw);
		window.display();
	}

	return 0;
}