#include <SFML/Graphics.hpp>
using namespace sf;

class Zombie
{
private:
	Vector2f m_Pos;
	Sprite m_Sprite;
	Texture m_Texture;
	
	Vector2f m_Res;

	//for movement:
	bool m_Up;
	bool m_Down;
	bool m_Right;
	bool m_Left;

	float m_Speed = 200; //pixels per second
	
public:
	Zombie(); //Constructor
	
	void spawn(Vector2f res); //Spawn player in centre of the screen
	
	Sprite getSprite(); //Return sprite to draw

	//movement functions:
	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();
	void stopLeft();
	void stopRight();
	void stopUp();
	void stopDown();
	void update(float elapsedTime, Vector2i mousePos);
};
