// OOPs concept will be used

#include <SFML/Graphics.hpp>
#include "Bat.h"  //Bat.cpp bhi pakeihaba
#include "Ball.h"
#include <sstream>

using namespace sf;

int main()
{

	VideoMode vm(960, 540);

	RenderWindow window(vm, "PONG");

	View view(FloatRect(0, 0, 1920, 1080));
	window.setView(view);
	
	Bat bat(1920/2-250/2, 1080-80);

	Ball ball(1920/2 - 25, 0);
	
	Clock clock;

	int score = 0;
	int lives = 3;

	Text hud;
	Font font;
	font.loadFromFile("fonts/DS-DIGI.TTF");
	hud.setFont(font);
	hud.setCharacterSize(60);
	hud.setFillColor(sf::Color::Green);
	hud.setPosition(40, 40);
	
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
		
		if (Keyboard::isKeyPressed(Keyboard::Right)) 
		{											 
			bat.moveRight();  
		}else{
			bat.stopRight();
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Left)) 
		{											 
			bat.moveLeft();
		}else{
			bat.stopLeft();
		}	

		std::stringstream ss;
		ss << "Score: " << score << "\nLives : " << lives;
		hud.setString(ss.str());
 
		Time dt = clock.restart();
		bat.update(dt);
		ball.update(dt);

		window.clear();			

		window.draw(bat.getShape());
		window.draw(ball.getShape());
		window.draw(hud);

		window.display();
	}

	return 0;
}

