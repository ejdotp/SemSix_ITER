#include "Player.h"
#include <cmath>
using namespace sf;

Player::Player()
{
	//Load Texture:
	m_Texture.loadFromFile("graphics/player.png");
	m_Sprite.setTexture(m_Texture);
	
	//Centre sprite origin:
	m_Sprite.setOrigin(25, 25); //image is of 50x50
}

void Player::spawn(Vector2f res)
{
	//place player at the centre of screen:
	m_Pos.x = res.x / 2;
	m_Pos.y = res.y / 2;
	m_Sprite.setPosition(m_Pos);
}

Sprite Player::getSprite()
{
	//return the sprite object
	return m_Sprite;
}

//movement functions:
void Player::moveLeft(){ m_Left = true; }
void Player::moveRight(){ m_Right = true; }
void Player::moveUp(){ m_Up = true;} 
void Player::moveDown(){ m_Down = true; }
void Player::stopLeft(){ m_Left = false; }
void Player::stopRight(){ m_Right = false;} 
void Player::stopUp(){ m_Up = false; }
void Player::stopDown(){ m_Down = false; }
void Player::update(float elapsedTime, Vector2i mousePos) //vector2f for floats and vector2i for integers
{
	if(m_Left)
		m_Pos.x -= m_Speed * elapsedTime;
	
	if(m_Right)
		m_Pos.x += m_Speed * elapsedTime; 
	
	if(m_Up)
		m_Pos.y -= m_Speed * elapsedTime;
	
	if(m_Down)
		m_Pos.y += m_Speed * elapsedTime; 

	m_Sprite.setPosition(m_Pos);

	// Get the direction from the player to the mouse
    float dx = mousePos.x - m_Pos.x; // horizontal distance
    float dy = mousePos.y - m_Pos.y; // vertical distance

    // Calculate the angle in radians, then convert to degrees
    float angle = atan2(dy, dx) * 180.0f / 3.14159265359f;

    // Rotate the sprite to face the mouse pointer
    m_Sprite.setRotation(angle);
}


