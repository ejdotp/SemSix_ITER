#include <SFML/Graphics.hpp>
#include<cmath>
using namespace sf;

class Bullet
{
private:
	Vector2f m_Position;
	RectangleShape m_BulletShape;
	bool m_InFlight = false;
	float m_BulletSpeed = 1000;
	float m_BulletDistanceX;
	float m_BulletDistanceY;
	float m_XTarget;
	float m_YTarget;
	float m_MaxX;
	float m_MinX;
	float m_MaxY;
	float m_MinY;
public:
	Bullet();
	void stop();
	bool isInFlight();
	void shoot(float startX, float startY,float xTarget, float yTarget);
	FloatRect getPosition();
	RectangleShape getShape();
	void update(float elapsedTime);

};
Bullet::Bullet()
{
	m_BulletShape.setSize(sf::Vector2f(20, 20));
}
void Bullet::shoot(float startX, float startY,float targetX, float targetY)
{
	m_InFlight = true;
	m_Position.x = startX;
	m_Position.y = startY;
	float gradient = (startX - targetX) / (startY - targetY);

	if (gradient < 0)
	{
		gradient *= -1;
	}
	m_BulletDistanceY=m_BulletSpeed/(1+gradient);
	m_BulletDistanceX=m_BulletSpeed*(gradient/(1+gradient));
	//float ratioXY = m_BulletSpeed / (1 + gradient);

//	m_BulletDistanceY = m_BulletSpeed*(1/1+;m_BulletDistanceX = ratioXY * gradient;
	if (targetX < startX)
	{
		m_BulletDistanceX *= -1;
	}

	if (targetY < startY)
	{
		m_BulletDistanceY *= -1;
	}
	
	/*float delX = targetX - startX;
	float delY = targetY - startY;
	float dist = sqrt(delX*delX + delY*delY);
	m_BulletDistanceY = m_BulletSpeed*delY/dist;
	m_BulletDistanceX = m_BulletSpeed*delX/dist; 
	*/

	// Finally, assign the results to the
	// member variables
	//m_XTarget = targetX;
	//m_YTarget = targetY;

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



