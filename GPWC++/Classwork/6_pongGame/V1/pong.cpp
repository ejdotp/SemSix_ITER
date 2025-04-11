// OOPs concept will be used

#include <SFML/Graphics.hpp>
#include "Bat.h" //Bat.cpp bhi pakeihaba
#include "Ball.h"
#include <sstream>
#include <iostream>

using namespace sf;
using namespace std;

int main()
{

	VideoMode vm(960, 540);

	RenderWindow window(vm, "PONG");

	View view(FloatRect(0, 0, 1920, 1080));
	window.setView(view);

	Bat bat(1920 / 2 - 250 / 2, 1080 - 80);

	Ball ball(1920 / 2 - 25, 0);

	Clock clock;

	int score = 0;
	int lives = 3;

	Text hud;
	Font font;
	font.loadFromFile("fonts/DS-DIGI.TTF");
	hud.setFont(font);
	hud.setCharacterSize(60);
	hud.setFillColor(Color::Green);
	hud.setPosition(40, 40);

	Text msg;
	msg.setFont(font);
	msg.setCharacterSize(150);
	msg.setFillColor(Color::Transparent);
	msg.setString("PAUSED");
	FloatRect textRect = msg.getLocalBounds();
	msg.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	msg.setPosition(960, 540);
	
	bool paused = false;

	// Gaming Loop:
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		
		
		if(!paused)
		{
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				paused = true;
				msg.setString("Paused");
				FloatRect textRect = msg.getLocalBounds();
				msg.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
				msg.setPosition(960, 540);
				msg.setFillColor(Color::Green);
			}
			
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				bat.moveRight();
			}
			else
			{
				bat.stopRight();
			}

			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				bat.moveLeft();
			}
			else
			{
				bat.stopLeft();
			}

			if ((ball.getPosition().left < 0) || (ball.getPosition().left + ball.getPosition().width > 1920))
			{
				ball.reboundSides();
			}

			if (ball.getPosition().intersects(bat.getPosition()))
			{
				ball.reboundBatorTop();
			}

			if (ball.getPosition().top < 0)
			{
				ball.reboundBatorTop();
				score++;
			}

			if (ball.getPosition().top + ball.getPosition().height > 1080)
			{
				ball.reboundBottom();
				lives--;
				if (lives < 1)
				{
					msg.setString("GAME OVER");
					FloatRect textRect = msg.getLocalBounds();
					msg.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
					msg.setPosition(960, 540);
					msg.setFillColor(Color::Green);
					paused = true;

					score = 0;
					lives = 3;
				}
			}

			std::stringstream ss;
			ss << "Score: " << score << "\nLives : " << lives;
			hud.setString(ss.str());

			Time dt = clock.restart();
			bat.update(dt);
			ball.update(dt);
		}
		else{
			msg.setFillColor(Color::Green);
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				paused = false;
				msg.setFillColor(Color::Transparent);
				ball.reboundBottom();
			}
		}
		window.clear();

		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.draw(hud);
		window.draw(msg);

		window.display();
	}

	return 0;
}
