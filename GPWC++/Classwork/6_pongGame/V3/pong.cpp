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
	Clock messageClock;
	Time messageDisplayTime = seconds(2);
	bool displayMessage = false;

	Font font;
	font.loadFromFile("fonts/DS-DIGI.TTF");

	Text msg;
	msg.setFont(font);
	msg.setCharacterSize(150);
	msg.setFillColor(Color::Transparent);
	msg.setString("");
	FloatRect textRect = msg.getLocalBounds();
	msg.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	msg.setPosition(960, 200);

	// HUDs
	int score1 = 0, score2 = 0;
	int lives1 = 3, lives2 = 3;
	Text hud1, hud2;

	hud1.setFont(font);
	hud1.setCharacterSize(60);
	hud1.setFillColor(Color::Green);
	hud1.setPosition(40, 40);

	hud2.setFont(font);
	hud2.setCharacterSize(60);
	hud2.setFillColor(Color::Green);
	hud2.setPosition(1500, 40);

	// Instructions screen
	bool startScreen = true;
	Text instructions;
	instructions.setFont(font);
	instructions.setCharacterSize(60);
	instructions.setFillColor(Color::Green);
	instructions.setString("Player 1:\nW/S - Move\nC - Auto Hit\n\nPlayer 2:\nUp/Down - Move\nC - Auto Hit\n\nPress SPACE to Start");
	instructions.setPosition(300, 200);

	bool paused = false;
	bool gameOver = false;
	bool flashToggle = false;
	Clock flashClock;

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

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Escape))
			window.close();

		if (startScreen)
		{
			if (Keyboard::isKeyPressed(Keyboard::Space))
			{
				startScreen = false;
				paused = false;
				msg.setFillColor(Color::Transparent);
				ball.reboundBottom();
			}
		}
		else if (!paused && !gameOver)
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

			if (Keyboard::isKeyPressed(Keyboard::W))
				bat.moveUp();
			else
				bat.stopUp();

			if (Keyboard::isKeyPressed(Keyboard::S))
				bat.moveDown();
			else
				bat.stopDown();

			if (Keyboard::isKeyPressed(Keyboard::Up))
				batt.moveUp();
			else
				batt.stopUp();

			if (Keyboard::isKeyPressed(Keyboard::Down))
				batt.moveDown();
			else
				batt.stopDown();

			if (Keyboard::isKeyPressed(Keyboard::C))
			{
				if (ball.getPosition().left < (1920 / 2))
					bat.cheat(ball.getPosition().top);
				else
					batt.cheat(ball.getPosition().top);
			}

			if ((ball.getPosition().top < 0) || (ball.getPosition().top + ball.getPosition().height > 1080))
				ball.reboundSides();

			if (ball.getPosition().intersects(bat.getPosition()) || ball.getPosition().intersects(batt.getPosition()))
			{
				ball.reboundBatorTop();
				msg.setFillColor(Color::Green);
				msg.setString("Paddle Hit!");
				FloatRect textRect = msg.getLocalBounds();
				msg.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
				msg.setPosition(960, 540);
				displayMessage = true;
				messageClock.restart();
			}

			if (ball.getPosition().left < 0)
			{
				ball.reboundBottom();
				ball.reboundBatorTop();
				lives1--;
				if (lives1 <= 0)
					gameOver = true;
			}
			else if ((ball.getPosition().left + ball.getPosition().width) > 1920)
			{
				ball.reboundBottom();
				ball.reboundBatorTop();
				lives2--;
				if (lives2 <= 0)
					gameOver = true;
			}

			stringstream ss1, ss2;
			ss1 << "P1\nScore: " << score1 << "\nLives: " << lives1;
			ss2 << "P2\nScore: " << score2 << "\nLives: " << lives2;
			hud1.setString(ss1.str());
			hud2.setString(ss2.str());

			Time dt = clock.restart();
			bat.update(dt);
			batt.update(dt);
			ball.update(dt);
		}
		else if (paused && !gameOver)
		{
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
		for (const auto &dot : dottedLine)
			window.draw(dot);

		if (startScreen)
		{
			window.draw(instructions);
		}
		else if (!gameOver)
		{
			window.draw(hud1);
			window.draw(hud2);
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
		}
		else
		{
			msg.setString("GAME OVER");
			FloatRect textRect = msg.getLocalBounds();
			msg.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
			msg.setPosition(960, 200);
			msg.setFillColor(Color::Green);
			window.draw(msg);

			Text scoreDisplay;
			scoreDisplay.setFont(font);
			scoreDisplay.setCharacterSize(70);
			scoreDisplay.setFillColor(Color::White);
			scoreDisplay.setString("P1 Score: " + to_string(score1) + "\nP2 Score: " + to_string(score2));
			scoreDisplay.setPosition(760, 400);
			window.draw(scoreDisplay);

			if (flashClock.getElapsedTime().asMilliseconds() > 500)
			{
				flashToggle = !flashToggle;
				flashClock.restart();
			}

			if (flashToggle)
			{
				Text winnerText;
				winnerText.setFont(font);
				winnerText.setCharacterSize(80);
				winnerText.setFillColor(Color::Green);
				if (lives1 <= 0)
				{
					winnerText.setString("P2 WINS!");
					winnerText.setPosition(1400, 700);
				}
				else
				{
					winnerText.setString("P1 WINS!");
					winnerText.setPosition(400, 700);
				}
				window.draw(winnerText);
			}
		}

		window.display();
	}
	return 0;
}