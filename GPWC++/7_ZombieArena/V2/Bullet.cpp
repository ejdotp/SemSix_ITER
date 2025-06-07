#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bullet
{
private:
	// Where is the bullet?
	Vector2f m_Position;

	// What each bullet looks like
	RectangleShape m_BulletShape;

	// Is this bullet currently whizzing through the air
	bool m_InFlight = false;

	// How fast does a bullet travel?
	float m_BulletSpeed = 1000;

	// What fraction of 1 pixel does the bullet travel, 
	// Horizontally and vertically each frame?
	// These values will be derived from m_BulletSpeed
	float m_BulletDistanceX;
	float m_BulletDistanceY;

	// Where is this bullet headed to?
	float m_XTarget;
	float m_YTarget;

	// Some boundaries so the bullet doesn't fly forever
	float m_MaxX;
	float m_MinX;
	float m_MaxY;
	float m_MinY;

// Public function prototypes go here
public:
	// The constructor
	Bullet();

	// Stop the bullet
	void stop();

	// Returns the value of m_InFlight
	bool isInFlight();

	// Launch a new bullet
	void shoot(float startX, float startY,
		float xTarget, float yTarget);

	// Tell the calling code where the bullet is in the world
	FloatRect getPosition();

	// Return the actual shape (for drawing)
	RectangleShape getShape();

	// Update the bullet each frame
	void update(float elapsedTime);

};

// The constructor
Bullet::Bullet()
{
	m_BulletShape.setSize(sf::Vector2f(5, 5));  //*********modified:(2,2)
}

void Bullet::shoot(float startX, float startY,
	float targetX, float targetY)
{
	// Keep track of the bullet
	m_InFlight = true;
	m_Position.x = startX;
	m_Position.y = startY;

	// Calculate the gradient of the flight path
	//float gradient = (startX - targetX) / (startY - targetY);
	float gradient = (startY - targetY)/(startX - targetX);

	// Any gradient less than zero needs to be negative
	if (gradient < 0)
	{
		gradient *= -1;
	}

	// Calculate the ratio between x and t
	/*float ratioXY = m_BulletSpeed / (1 + gradient);

	// Set the "speed" horizontally and vertically
	m_BulletDistanceY = ratioXY;
	m_BulletDistanceX = ratioXY * gradient;
	*/

	//Fraction of 1 px the bullet travels vertically in each frame
	//m_BulletDistanceY=(1/(1+gradient))*m_BulletSpeed;  //y = s * sin A
	m_BulletDistanceY=(gradient/(1+gradient))*m_BulletSpeed; //y = s * sin A

	
	//Fraction of 1 px the bullet travels horizontally in each frame
	//m_BulletDistanceX=(gradient/(1+gradient))*m_BulletSpeed; //x = s * cos A	
	m_BulletDistanceX=(1/(1+gradient))*m_BulletSpeed;  //x = s * cos A
	
	// Point the bullet in the right direction
	if (targetX < startX)
	{
		m_BulletDistanceX *= -1;
	}

	if (targetY < startY)
	{
		m_BulletDistanceY *= -1;
	}

	// Finally, assign the results to the
	// member variables
	m_XTarget = targetX;
	m_YTarget = targetY;

	// Set a max range of 1000 pixels
	float range = 1000;
	m_MinX = startX - range;
	m_MaxX = startX + range;
	m_MinY = startY - range;
	m_MaxY = startY + range;
	
	// Position the bullet ready to be drawn
	m_BulletShape.setPosition(m_Position);
}

void Bullet::stop()
{
	m_InFlight = false;
}

bool Bullet::isInFlight()
{
	return m_InFlight;
}

FloatRect Bullet::getPosition()
{
	return m_BulletShape.getGlobalBounds();
}

RectangleShape Bullet::getShape()
{
	return m_BulletShape;
}


void Bullet::update(float elapsedTime)
{
	// Update the bullet position variables
	m_Position.x += m_BulletDistanceX * elapsedTime;
	m_Position.y += m_BulletDistanceY * elapsedTime;

	// Move the bullet
	m_BulletShape.setPosition(m_Position);

	// Has the bullet gone out of range?
	if (m_Position.x < m_MinX || m_Position.x > m_MaxX ||
		m_Position.y < m_MinY || m_Position.y > m_MaxY)
	{
		m_InFlight = false;
	}

}
