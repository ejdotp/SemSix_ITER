#include <SFML/Graphics.hpp>
#include "Player.h"
using namespace sf;

int main()
{
	//Get Screen Resolution:
	Vector2f res;
	res.x = VideoMode::getDesktopMode().width;
	res.y = VideoMode::getDesktopMode().height;
	
	//Create a full-screen window:
	RenderWindow window(VideoMode(res.x, res.y), "Zombie Arena");
	
	//view to follow the player:
	View mainView(FloatRect(0, 0, res.x, res.y));
	window.setView(mainView);
	
	//creating player object:
	Player player;
	player.spawn(res);

	//CLock to measure elapsed time:
	Clock clock;
	
	//Game loop ( runs while window is open ):
	while(window.isOpen())
	{
		//Handle closing:
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

		//Handle WASD input:
		if(Keyboard::isKeyPressed(Keyboard::W))
			player.moveUp();
		else
			player.stopUp();
		
		if(Keyboard::isKeyPressed(Keyboard::S))
			player.moveDown();
		else
			player.stopDown();

		if(Keyboard::isKeyPressed(Keyboard::A))
			player.moveLeft();
		else
			player.stopLeft();

		if(Keyboard::isKeyPressed(Keyboard::D))
			player.moveRight();
		else
			player.stopRight();
		
		//update elapsed time & mouse position:
		Time dt = clock.restart();
		Vector2i mousePos = Mouse::getPosition();
		player.update(dt.asSeconds(), mousePos);

		//Clear the window and show it ( blank screen ):
		window.clear();
		window.draw(player.getSprite());
		window.display();
	}
	
	return 0;
}
