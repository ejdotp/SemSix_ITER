// OOPs concept will be used

#include <SFML/Graphics.hpp>
#include "Bat.h"  //Bat.cpp bhi pakeihaba

using namespace sf;

int main()
{

	VideoMode vm(960, 540);

	RenderWindow window(vm, "PONG");

	View view(FloatRect(0, 0, 1920, 1080));
	window.setView(view);
	
	Bat bat(1920/2-250/2, 1080-80);
	
	Clock clock;
	
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
		
		Time dt = clock.restart();
		bat.update(dt);

		window.clear();			

		window.draw(bat.getShape());

		window.display();
	}

	return 0;
}

