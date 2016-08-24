#pragma once

#include <SFML/Graphics.hpp>

//physics works on a local axis
//x is forward of the object
//y is side to side
class Physics
{
public:
	void XForce(float var) { xAcc += var; }
	void YForce(float var) { yAcc += var; }

	void SetFric(float fric) { friction = fric; }

	sf::Vector2f UpdatePos(float dt)
	{
		if (xAcc > 0)
			xAcc -= friction;
		if (xAcc < 0)
			xAcc += friction;

		xSpd = xAcc * dt;
		ySpd = yAcc * dt;
		sf::Vector2f vec(xSpd, ySpd);
		return vec;
	}
	sf::Vector2f UpdateAng(float dt)
	{

	}
private:

	float xAcc = 0;
	float yAcc = 0;
	float xSpd = 0;
	float ySpd = 0;

	float friction = 2;
};
