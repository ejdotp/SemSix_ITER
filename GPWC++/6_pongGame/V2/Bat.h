#include <SFML/Graphics.hpp>

using namespace sf;

class Bat
{
private:
	Vector2f m_Position; //2d vector with floating point coordinates ( store (x, y) position of Bat )
	
	RectangleShape m_Shape; //graphical representation of Bat
	
	float m_Speed = 600.0f; //Controls how fast bat moves
	
	bool m_movingUp = false;   //
	bool m_movingDown = false;  // controls direction
	
public:
	Bat(float startX, float startY); //stores current position of Bat
	
	FloatRect getPosition(); //retrieves current X, Y coordinate of the bat
	
	RectangleShape getShape(); //gives the shape of the bat	
	
	void cheat(float);
	void moveUp();  //
	void moveDown(); // controls movement
	void stopUp();  //
	void stopDown(); //
	
	void update(Time dt); //moves the bat based on time, speed & direction
};
