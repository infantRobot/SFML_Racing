#pragma once

#include <SFML\Graphics.hpp>

#include "Drawable.hpp"
#include "Physics.hpp"

class Car
{
public:
	Car();

	sf::Vector2f m_position;
	float m_angle;
	
	Drawable m_draw;
	Physics m_phys;

	void UpdateCar(float dt);


private:
	sf::Vector2f m_carSize;
	float acceleration = 20;
};

