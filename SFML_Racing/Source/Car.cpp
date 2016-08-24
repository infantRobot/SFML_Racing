#include "Car.hpp"

#include <iostream>

Car::Car()
{
	//set initial position
	m_position.x = 400;
	m_position.y = 400;
	
	//set Car size
	m_carSize.x = 50;
	m_carSize.y = 30;

	//Car angle
	m_angle = 0;

	//set the car color
	m_draw.m_rect.setFillColor(sf::Color::Blue);
	m_draw.m_rect.setSize(m_carSize);
	m_draw.m_rect.setOrigin(sf::Vector2f(m_carSize.x / 2, m_carSize.y / 2));

	m_phys.SetFric(4);

	UpdateCar(0);
}



void Car::UpdateCar(float dt)
{
	//Update Physics
	sf::Vector2f oldPos = m_position;
	m_position += m_phys.UpdatePos(dt);
	float varX = (m_position.x - oldPos.x);
	float varY = (m_position.y - oldPos.y);
	if (varX == 0)
	{
		//tan not defined for x=0
		m_angle = 0;
	}
	else
	{
		m_angle = tan(varY / varX);
	}

	//m_draw.m_rect.setPosition(m_position);
	//Update Drawable
	m_draw.Update(m_position, m_angle, m_carSize);

	//Get Inputs
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_phys.XForce(acceleration);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_phys.XForce(-acceleration);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_phys.YForce(3);
	}
	else
		m_angle = 0;
}