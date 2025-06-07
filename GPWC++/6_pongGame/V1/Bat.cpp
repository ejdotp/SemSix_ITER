#include "Bat.h" //importing them member declarations

Bat::Bat(float startX, float startY)
{
	m_Position.x = startX; //set the horizontal position
	m_Position.y = startY; //set the vertical position     //x y Vector2f ru asila
	
	m_Shape.setSize(sf::Vector2f(250, 50)); // Define bat size (50 x 5)
	m_Shape.setPosition(m_Position); //set position on screen
	m_Shape.setFillColor(sf::Color::Green);
}
	
FloatRect Bat::getPosition()
{
	return m_Shape.getGlobalBounds(); //returns 4 coordinates but global is used instead of local because of external dependencies.
}
	
RectangleShape Bat::getShape()
{
	return m_Shape;  //returns the object itself. To draw the object (bat) to the screen
}

void Bat::moveLeft()
{
	m_movingLeft = true;
}

void Bat::moveRight()
{
	m_movingRight = true;
}

void Bat::stopLeft()
{
	m_movingLeft = false;
}

void Bat::stopRight()
{
	m_movingRight = false;
}

void Bat::update(Time dt)
{
	if(m_movingLeft && (m_Position.x > 0))
	{
		m_Position.x -= m_Speed * dt.asSeconds(); //moves left
	}
	
	if(m_movingRight && ((m_Position.x + 250) < 1920))
	{
		m_Position.x += m_Speed * dt.asSeconds(); //moves right
	}
	
	m_Shape.setPosition(m_Position); // updates bat's position
}
