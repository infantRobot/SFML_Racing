#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

class Drawable: public sf::Drawable, public sf::Transformable
{
public:
	sf::Color m_color;
	sf::RectangleShape m_rect;
	
	
	void Update(sf::Vector2f pos, float ang, sf::Vector2f size)
	{
		m_rect.rotate(ang);
		//adjust postion
		//sf::Vector2f newPos(pos.x - size.x/ 2, pos.y - size.y / 2);
		m_rect.setPosition(pos);
	}

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override
	{
		// apply the transform
		states.transform *= getTransform();

		// no texture used
		states.texture = NULL;

		// draw the rectangle
		target.draw(m_rect, states);
	}

private:

};
