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


	UpdateCar(0);
}



void Car::UpdateCar(float dt)
{
	//Update Physics
	sf::Vector2f oldPos = m_position;
	m_position += m_phys.UpdatePos(dt);
	float varX = (m_position.x - oldPos.x);
	float varY = (m_position.y - oldPos.y);
	
	m_angle = 0;//m_phys.UpdateAng(dt)*180/3.14159;
	

	//m_draw.m_rect.setPosition(m_position);
	//Update Drawable
	m_draw.Update(m_position, m_angle, m_carSize);

	//Get Inputs
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		m_phys.DriveForce(acceleration);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		m_phys.DriveForce(-acceleration);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		m_phys.TurnCar(30);
	}
	else
		m_angle = 0;
}