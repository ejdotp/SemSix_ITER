/* Construct SFML C++ statements to draw a red filled rectangle of size (X, Y) on the centre of screen 1920 x 1080.*/

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

using namespace sf; 
using namespace std;

int main()
{

	VideoMode vm(960, 540); 

	RenderWindow window(vm, "Moving Rectangle");
	 
	View view(FloatRect(0, 0, 1920, 1080));
	window.setView(view);					

	RectangleShape rectji;	
	float X = 400, Y = 300; //xpos = ((1920 / 2) - (X / 2));								
	rectji.setFillColor(Color::Red);								 
	rectji.setSize(Vector2f(X, Y));		
	rectji.setPosition(((1920 / 2) - (X / 2)), ((1080 / 2) - (Y / 2)));		
	
	float x = 0, y = 0;	
	
	bool rActive = false;		
				
	Clock clock;						
	
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
			x=1, y=0;						 
		} 

		if (Keyboard::isKeyPressed(Keyboard::Left)) 
		{								
			x=-1, y=0;						 
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Up)) 
		{		
			x=0, y=-1;						 
		} 

		if (Keyboard::isKeyPressed(Keyboard::Down)) 
		{								
			x=0, y=1;						 
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Space)) 
		{								
			x=0, y=0;						 
		}
		
		Time dt = clock.restart();
		
		//rectji.move(x, y);
		
		if (!rActive)
		{
a:			x = (rand() % 2);
			y = (rand() % 2);
			if(x == 0 && y == 0){ goto a; }
			rectji.setPosition(((1920 / 2) - (X / 2)), ((1080 / 2) - (Y / 2)));	
			rActive = true;
		}
		else
		{
			rectji.move(x, y);

			if (rectji.getPosition().x > 1920 || rectji.getPosition().x < 0 || rectji.getPosition().y > 1080 || rectji.getPosition().y < 0)
			{
				rActive = false;
			}
		}

		window.clear();
				 
		window.draw(rectji);

		window.display(); 
	}

	return 0;
}

