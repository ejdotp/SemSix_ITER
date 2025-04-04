#include "Ball.h" //importing them member declarations

Ball::Ball(float startX, float startY)
{
	m_Position.x = startX; // set the horizontal position
	m_Position.y = startY; // set the vertical position     //x y Vector2f ru asila

	m_Shape.setRadius(25);			 // Define ball radius
	m_Shape.setPosition(m_Position); // set position on screen
	m_Shape.setFillColor(sf::Color::Green);
}

FloatRect Ball::getPosition()
{
	return m_Shape.getGlobalBounds(); // returns 4 coordinates but global is used instead of local because of external dependencies. Global also adjusts for scale and position ( helpful for moving objects )
}

CircleShape Ball::getShape()
{
	return m_Shape; // returns the object itself. To draw the object (bat) to the screen
}

void Ball::reboundSides()
{
	m_DirectionX = -m_DirectionX;
}

void Ball::reboundBatorTop()
{
	m_DirectionY = -m_DirectionY;
}

void Ball::reboundBottom()
{
	m_Position.x = 1920 / 2 - 25;
	m_Position.y = 0;

	// m_DirectionY = -m_DirectionY;
}

void Ball::update(Time dt)
{
	m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
	m_Position.y += m_DirectionY * m_Speed * dt.asSeconds();

	m_Shape.setPosition(m_Position); // updates ball's position
}
