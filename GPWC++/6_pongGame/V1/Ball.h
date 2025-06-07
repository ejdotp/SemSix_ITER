#include <SFML/Graphics.hpp>

using namespace sf;

class Ball
{
private:
	Vector2f m_Position; // 2d vector with floating point coordinates ( store (x, y) position of Ball )

	CircleShape m_Shape; // graphical representation of Ball

	float m_Speed = 300.0f; // Controls how fast ball moves

	float m_DirectionX = 1.0f; // ball moves to the right
	float m_DirectionY = 1.0f; // ball move down
							   // together ball moves bottom-right diagonally

public:
	Ball(float startX, float startY); // stores current position of Ball

	FloatRect getPosition(); // retrieves current X, Y coordinate of the ball

	CircleShape getShape(); // gives the shape of the bat

	void reboundSides(); // called when ball hits either sides ( change horizontal direction )

	void reboundBatorTop(); // called when ball hits the top or the bat ( change vertical direction )

	void reboundBottom(); // ball misses the bat -> reset ball position

	void update(Time dt); // upadte ball's position
};
