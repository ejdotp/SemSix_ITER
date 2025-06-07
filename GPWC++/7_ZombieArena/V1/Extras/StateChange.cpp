#include <SFML/Graphics.hpp>
using namespace sf;

enum class GameState{GameOver, LvlUp, Playing, Paused};

int main()
{
	Vector2f res;
	res.x = VideoMode::getDesktopMode().width;
	res.y = VideoMode::getDesktopMode().height;
	
	RenderWindow window(VideoMode(res.x, res.y), "Zombie Maker");

	View mainView(FloatRect(0, 0, res.x, res.y));
	window.setView(mainView);

	GameState state = GameState::GameOver;

	Text Paused;
	Text Lvling;
	Text GameOver;
	Text Playing;

	Font font;
	font.loadFromFile("../fonts/gomarice_zombie_shooting.ttf");
	Paused.setFont(font);
	Lvling.setFont(font);
	GameOver.setFont(font);
	Playing.setFont(font);

	Paused.setString("Paused");
	Lvling.setString("Leveling Up");
	GameOver.setString("Game Over");
	Playing.setString("Playing");

	Paused.setCharacterSize(100);
	Lvling.setCharacterSize(100);
	GameOver.setCharacterSize(100);
	Playing.setCharacterSize(100);

	Paused.setFillColor(Color::Yellow);
	Lvling.setFillColor(Color::Yellow);
	GameOver.setFillColor(Color::Yellow);
	Playing.setFillColor(Color::Yellow);

	FloatRect t1 = Paused.getLocalBounds();
	Paused.setOrigin(t1.left + t1.width / 2.0f, t1.top + t1.height / 2.0f);
	Paused.setPosition(res.x/2, res.y/2);

	FloatRect t2 = Lvling.getLocalBounds();
	Lvling.setOrigin(t2.left + t2.width / 2.0f, t2.top + t2.height / 2.0f);
	Lvling.setPosition(res.x/2, res.y/2);

	FloatRect t3 = GameOver.getLocalBounds();
	GameOver.setOrigin(t3.left + t3.width / 2.0f, t3.top + t3.height / 2.0f);
	GameOver.setPosition(res.x/2, res.y/2);

	FloatRect t4 = Playing.getLocalBounds();
	Playing.setOrigin(t4.left + t4.width / 2.0f, t4.top + t4.height / 2.0f);
	Playing.setPosition(res.x/2, res.y/2);

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

		if(event.KeyPressed == true){
			if(event.key.code = Keyboard::Return){
				if(state == GameState::GameOver)
					state = GameState::LvlUp;
				if(state == GameState::Playing)
					state = GameState::Paused;
				if(state == GameState::Paused)
					state = GameState::Playing;
			}
			if(event.key.code == Keyboard::Num1 || event.key.code == Keyboard::Num2 || event.key.code == Keyboard::Num3 || event.key.code == Keyboard::Num4 || event.key.code == Keyboard::Num5 || event.key.code == Keyboard::Num6){
				state = GameState::Playing;
			}
		}
			
		
		window.clear();
        if(state == GameState::Playing)
            window.draw(Playing);
		if(state == GameState::Paused)
            window.draw(Paused);
		if(state == GameState::LvlUp)
            window.draw(Lvling);
		if(state == GameState::GameOver)
            window.draw(GameOver);
		window.display();
	}
	
	return 0;
}
