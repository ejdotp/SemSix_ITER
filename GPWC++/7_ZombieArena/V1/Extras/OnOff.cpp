#include <SFML/Graphics.hpp>
using namespace sf;

enum class GameState{ON, OFF};

int main()
{
	Vector2f res;
	res.x = VideoMode::getDesktopMode().width;
	res.y = VideoMode::getDesktopMode().height;
	
	RenderWindow window(VideoMode(res.x, res.y), "Zombie Maker");

	View mainView(FloatRect(0, 0, res.x, res.y));
	window.setView(mainView);

    Texture player;
    player.loadFromFile("../graphics/player.png");
    Sprite Player;
	Player.setTexture(player);
    Player.setPosition(res.x/2, res.y/2);

    Texture bloater;
    bloater.loadFromFile("../graphics/bloater.png");
    Sprite Bloater;
	Bloater.setTexture(bloater);
    Bloater.setPosition(res.x/2, res.y/2);

	GameState state = GameState::ON;
	while(window.isOpen())
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

		
		if(Keyboard::isKeyPressed(Keyboard::Return)){
            if(state == GameState::ON)
                state = GameState::OFF;
            else
                state = GameState::ON;
        }
			
		
		window.clear();
        if(state == GameState::ON)
            window.draw(Player);
        else
            window.draw(Bloater);
		window.display();
	}
	
	return 0;
}
