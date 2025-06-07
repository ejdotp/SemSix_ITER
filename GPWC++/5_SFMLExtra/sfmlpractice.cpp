/* Construct SFML C++ statements to draw FOUR green filled circle shapes of radius X on the screen 1920 x 1080 close to four corners of the screen. Additionally one center stretched circle with red filled of same radius using sf::CircleShape Class Reference*/

#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

using namespace sf; 
using namespace std;

int main()
{

	VideoMode vm(960, 540); 

	RenderWindow window(vm, "Cricles");
	 
	View view(FloatRect(0, 0, 1920, 1080));
	window.setView(view);					

	float Radius = 50.0f;
	
	CircleShape circles[5];
	
	for(int i = 0; i < 4; i++)
	{
		circles[i].setRadius(Radius);
		circles[i].setFillColor(Color::Green);
		
	}
	circles[4].setRadius(Radius);
	circles[4].setFillColor(Color::Red);
	
	circles[0].setPosition(0, 0);
	circles[1].setPosition((1920 - (Radius * 2)), 0);
	circles[2].setPosition(0, 980 - ((Radius * 2)));
	circles[3].setPosition((1920 - (Radius * 2)), (980 - (Radius * 2)));
	circles[4].setPosition(((1920/2) - Radius), ((1080/2) - Radius));  //(910, 490)
	
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


		window.clear();
		
		for ( int i = 0; i < 5; i++)
		{		 
			window.draw(circles[i]);
		}

		window.display(); 
	}

	return 0;
}

