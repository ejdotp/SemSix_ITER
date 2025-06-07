#include "Bat.h" //importing them member declarations

Bat::Bat(float startX, float startY)
{
	m_Position.x = startX; //set the horizontal position
	m_Position.y = startY; //set the vertical position     //x y Vector2f ru asila
	
	m_Shape.setSize(sf::Vector2f(50, 250)); // Define bat size (50 x 5)
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

void Bat::moveUp()
{
	m_movingUp = true;
}

void Bat::cheat(float t)
{
	m_Position.y = t - 125.0;
}

void Bat::moveDown()
{
	m_movingDown = true;
}

void Bat::stopUp()
{
	m_movingUp = false;
}

void Bat::stopDown()
{
	m_movingDown = false;
}

void Bat::update(Time dt)
{
	if(m_movingUp && (m_Position.y > 0))
	{
		m_Position.y -= m_Speed * dt.asSeconds(); //moves left
	}
	
	if(m_movingDown && ((m_Position.y + 250) < 1080))
	{
		m_Position.y += m_Speed * dt.asSeconds(); //moves right
	}
	
	m_Shape.setPosition(m_Position); // updates bat's position
}
