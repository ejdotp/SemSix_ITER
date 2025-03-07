#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{

	VideoMode vm(960, 540); // OBJECT vm CREATED

	RenderWindow window(vm, "TIMBER MAN"); // Add 3rd field <Style::Fullscreem> to open fullscreen by default

	View view(FloatRect(0, 0, 1920, 1080)); // Claculates the coordinates according to the main resolution
	window.setView(view);					// (left, top, width, height)

	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png"); // creates texture background

	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground); // pastes it on the bg like a sticker
	spriteBackground.setPosition(0, 0);

	Texture textureTree;						   //
	textureTree.loadFromFile("graphics/tree.png"); // adding tree onto bg
	Sprite spriteTree;							   //
	spriteTree.setTexture(textureTree);			   //
	spriteTree.setPosition(810, 0);				   //

	Texture textureBee;							 //
	textureBee.loadFromFile("graphics/bee.png"); // adding bee
	Sprite spriteBee;							 //
	spriteBee.setTexture(textureBee);			 //
	spriteBee.setPosition(0, 800);				 //

	bool beeActive = false; // bee movement flag
	float beeSpeed = 0.0f;	// bee initial speed

	Texture textureCloud;							 //
	textureCloud.loadFromFile("graphics/cloud.png"); // cloud texture
	Sprite spriteCloud1, spriteCloud2, spriteCloud3; // 3 cloud objects using same texture
	spriteCloud1.setTexture(textureCloud);			 //
	spriteCloud1.setPosition(0, 0);					 //
	spriteCloud2.setTexture(textureCloud);			 //
	spriteCloud2.setScale(0.6, 0.6);
	spriteCloud2.setPosition(0, 150);	   //
	spriteCloud3.setTexture(textureCloud); //
	spriteCloud3.setScale(0.89, 0.89);
	spriteCloud3.setPosition(0, 300); //

	bool c1Active = false; // cloud-1 movement flag
	float c1Speed = 0.0f;  // cloud-1 initial speed
	bool c2Active = false; // cloud-2 movement flag
	float c2Speed = 0.0f;  // cloud-2 initial speed
	bool c3Active = false; // cloud-3 movement flag
	float c3Speed = 0.0f;  // cloud-3 initial speed

	Clock clock; // initializes a game clock

	RectangleShape timeBar;											 // Time Bar element
	RectangleShape timeBarOutline;									 // Outline for timebar
																	 //
	float timeBarStartWidth = 400;									 // define time bar initial dimensions
	float timeBarHieght = 60;										 //
																	 //
	timeBar.setFillColor(Color::Red);								 //
	timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHieght));	 // design time bar
	timeBar.setPosition(((1920 / 2) - 200), 980);					 //
																	 //
	timeBarOutline.setFillColor(Color::Black);						 //
	timeBarOutline.setSize(Vector2f(404, 64));						 // design timebar outline
	timeBarOutline.setPosition(((1920 / 2) - 202), 978);			 //
																	 //
	Time gameTimeTotal;												 //
	float timeRemaining = 6.0f;										 //  every second 66.6 pixels reduced.
	float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining; //

	bool paused = true;
	int score = 0;

	while (window.isOpen())
	{

		Event event;						 //
		while (window.pollEvent(event))		 //
		{									 //
			if (event.type == Event::Closed) // ensures window stays open until close button pressed
			{								 //
				window.close();				 //
			} //
		} //

		if (Keyboard::isKeyPressed(Keyboard::Escape)) //
		{											  // exits games on clicking escape
			window.close();							  //
		} //

		if (Keyboard::isKeyPressed(Keyboard::Return)) //
		{											  // exits games on clicking escape
			paused = false;							  //
			score = 0;
		} //

		Time dt = clock.restart(); // clock dependent algos come below this line.

		if (!paused)
		{
			timeRemaining -= dt.asSeconds(); // time decreases.
			timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHieght));
		}

		if (!beeActive)
		{
			srand((int)time(0));
			beeSpeed = (rand() % 200) + 200;	 // ( 0 to 199) + 200 = ( 200 to 399 ) -> sets a random speed for bee
			float height = (rand() % 500) + 300; // sets a random height for bee within 500 to 999
			spriteBee.setPosition(2000, height);
			beeActive = true; // make the bee move by sending to else part
		}
		else
		{
			spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);
			// get current position ie (2000, random height) and decrease the x value with clock time to move bee from right to left
			// dt.asSeconds() provides frame rate independence, otherwise object would move faster with higher framerate.

			if (spriteBee.getPosition().x < -100)
			{
				beeActive = false;
			}
		}

		// moving cloud 1
		if (!c1Active)
		{
			srand((int)time(0) * 10); // multiplicator allows generation to be random even during initial calls.
			c1Speed = (rand() % 120) + 60;
			float height = (rand() % 300);
			spriteCloud1.setPosition(-300, height);
			c1Active = true;
		}
		else
		{
			spriteCloud1.setPosition(spriteCloud1.getPosition().x + (c1Speed * dt.asSeconds()), spriteCloud1.getPosition().y);

			if (spriteCloud1.getPosition().x > 1920)
			{
				c1Active = false;
			}
		}

		// moving cloud 2
		if (!c2Active)
		{
			srand((int)time(0) * 10);
			c2Speed = (rand() % 80) + 20;
			float height = (rand() % 200);
			spriteCloud2.setPosition(-200, height);
			c2Active = true;
		}
		else
		{
			spriteCloud2.setPosition(spriteCloud2.getPosition().x + (c2Speed * dt.asSeconds()), spriteCloud2.getPosition().y);

			if (spriteCloud2.getPosition().x > 1920)
			{
				c2Active = false;
			}
		}

		// moving cloud 3
		if (!c3Active)
		{
			srand((int)time(0) * 10);
			c3Speed = (rand() % 100) + 50;
			float height = (rand() % 300);
			spriteCloud3.setPosition(-250, height);
			c3Active = true;
		}
		else
		{
			spriteCloud3.setPosition(spriteCloud3.getPosition().x + (c3Speed * dt.asSeconds()), spriteCloud3.getPosition().y);

			if (spriteCloud3.getPosition().x > 1920)
			{
				c3Active = false;
			}
		}

		window.clear();				   //
		window.draw(spriteBackground); // Draws bg
		window.draw(spriteCloud2);	   //
		window.draw(spriteCloud3);	   // Draws Clouds
		window.draw(spriteCloud1);	   //
		window.draw(spriteTree);	   // Draws tree
		window.draw(spriteBee);		   // Draws bee
		window.draw(timeBarOutline);
		window.draw(timeBar); // Draws timebar
		window.display();	  //
	}

	return 0;
}
