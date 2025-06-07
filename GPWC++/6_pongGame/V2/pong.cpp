#include <SFML/Graphics.hpp>
#include "Bat.h"
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

	Bat bat(50, 1080 / 2 - 250 / 2);
	Bat batt(1820, 1080 / 2 - 250 / 2);

	Ball ball(1920 / 2 - 25, 0);

	Clock clock;
	
	//
	Clock messageClock;
	Time messageDisplayTime = seconds(2);
	bool displayMessage = false;
	//

	Font font;
	font.loadFromFile("fonts/DS-DIGI.TTF");
	Text msg;
	msg.setFont(font);
	msg.setCharacterSize(150);
	msg.setFillColor(Color::Transparent);
	msg.setString("");
	FloatRect textRect = msg.getLocalBounds();
	msg.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	msg.setPosition(960, 540);

	bool paused = false;
	
	vector<RectangleShape> dottedLine;
	float dotSpacing = 30.0f;
	float dotHeight = 20.0f;
	float middleX = 1920 / 2.0f;

	for (float y = dotSpacing / 2.0f; y < 1080; y += dotSpacing)
	{
		RectangleShape dot(Vector2f(5, dotHeight));
		dot.setFillColor(Color::Green);
		dot.setPosition(middleX - 2.5f, y - dotHeight / 2.0f);
		dottedLine.push_back(dot);
	}

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

			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				bat.moveDown();
			}
			else
			{
				bat.stopDown();
			}

			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				bat.moveUp();
			}
			else
			{
				bat.stopUp();
			}
			
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				batt.moveDown();
			}
			else
			{
				batt.stopDown();
			}

			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				batt.moveUp();
			}
			else
			{
				batt.stopUp();
			}

			if (Keyboard::isKeyPressed(Keyboard::C) && (ball.getPosition().left < (1920/2)))
			{
				bat.cheat(ball.getPosition().top);
			}
			
			if (Keyboard::isKeyPressed(Keyboard::C) && (ball.getPosition().left > (1920/2)))
			{
				batt.cheat(ball.getPosition().top);
			}

			if ((ball.getPosition().top < 0) || (ball.getPosition().top + ball.getPosition().height > 1080))
			{
				ball.reboundSides();
			}

			if (ball.getPosition().intersects(bat.getPosition()) || ball.getPosition().intersects(batt.getPosition()))
			{
				ball.reboundBatorTop();
				msg.setFillColor(Color::Green);
				msg.setString("Paddle Hit!");
				FloatRect textRect = msg.getLocalBounds();
				msg.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
				msg.setPosition(960, 540);
				
				//
				displayMessage = true;
				messageClock.restart();
				//
			}

			if (ball.getPosition().left < 0 || (ball.getPosition().left + ball.getPosition().width) > 1920)
			{
				ball.reboundBottom();
				ball.reboundBatorTop();
				msg.setFillColor(Color::Green);
				msg.setString("Missed!");
				FloatRect textRect = msg.getLocalBounds();
				msg.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
				msg.setPosition(960, 540);
				
				//
				displayMessage = true;
				messageClock.restart();
				//
			}

			Time dt = clock.restart();
			bat.update(dt);
			batt.update(dt);
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
		window.draw(batt.getShape());
		window.draw(ball.getShape());
		for (const auto& dot : dottedLine)
		{
			window.draw(dot);
		}
		
		//
		if (displayMessage)
		{
			window.draw(msg);
			if (messageClock.getElapsedTime() >= messageDisplayTime)
			{
				displayMessage = false;
				msg.setFillColor(Color::Transparent);
				msg.setString("");
			}
		}
		//

		window.display();
	}

	return 0;
}
