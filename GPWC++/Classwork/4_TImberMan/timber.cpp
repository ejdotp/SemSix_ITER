#include <SFML/Graphics.hpp>
using namespace sf;

int main(){
	
	VideoMode vm(960, 540);                                      // OBJECT vm CREATED
	
	RenderWindow window(vm, "TIMBER MAN");						 // Add 3rd field <Style::Fullscreem> to open fullscreen by default
	
	View view(FloatRect(0,0,1920, 1080));                        // Claculates the coordinates according to the main resolution
	window.setView(view);                                        //(left, top, width, height)
	
	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png");   // creates texture background
	
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);              //pastes it on the bg like a sticker
	spriteBackground.setPosition(0,0);
	
	while(window.isOpen())
	{
	
		Event event;                                             //
		while(window.pollEvent(event))                           //
		{                                                        //
			if(event.type == Event::Closed)                      // ensures window stays open until close button pressed
			{                                                    //
				window.close();                                  //
			}                                                    //
		}                                                        //
		
		if(Keyboard::isKeyPressed(Keyboard::Escape))             //
		{                                                        // exits games on clicking escape
			window.close();                                      //
		}                                                        //
		
		window.clear();                                          //
	    window.draw(spriteBackground);                           // Draws Everything
		window.display();                                        //
	}
	
	return 0;	
	
}
