#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

using namespace sf;

void updateBranches(int seed);
const int NUM_BRANCHES = 6;
Sprite branches[NUM_BRANCHES];

enum class side
{
	LEFT,
	RIGHT,
	NONE
};

side branchPositions[NUM_BRANCHES];

//

const float Axe_Left = 700;
const float Axe_Right = 1075;

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
												 //
	bool beeActive = false;						 // bee movement flag
	float beeSpeed = 0.0f;						 // bee initial speed

	Texture textureCloud;							 //
	textureCloud.loadFromFile("graphics/cloud.png"); // cloud texture
	Sprite spriteCloud1, spriteCloud2, spriteCloud3; // 3 cloud objects using same texture
	spriteCloud1.setTexture(textureCloud);			 //
	spriteCloud1.setPosition(0, 0);					 //
	spriteCloud2.setTexture(textureCloud);			 //
	spriteCloud2.setScale(0.6, 0.6);				 //
	spriteCloud2.setPosition(0, 150);				 //
	spriteCloud3.setTexture(textureCloud);			 //
	spriteCloud3.setScale(0.89, 0.89);				 //
	spriteCloud3.setPosition(0, 300);				 //

	bool c1Active = false; // cloud-1 movement flag
	float c1Speed = 0.0f;  // cloud-1 initial speed
	bool c2Active = false; // cloud-2 movement flag
	float c2Speed = 0.0f;  // cloud-2 initial speed
	bool c3Active = false; // cloud-3 movement flag
	float c3Speed = 0.0f;  // cloud-3 initial speed

	Clock clock; // initializes a game clock

	RectangleShape timeBar;											 // Time Bar element:
	RectangleShape timeBarOutline;									 // 	Outline for timebar
																	 //
	float timeBarStartWidth = 400;									 // 	define time bar initial dimensions
	float timeBarHieght = 60;										 //
																	 //
	timeBar.setFillColor(Color::Red);								 //
	timeBar.setSize(Vector2f(timeBarStartWidth, timeBarHieght));	 // 	design time bar
	timeBar.setPosition(((1920 / 2) - 200), 980);					 //
																	 //
	timeBarOutline.setFillColor(Color::Black);						 //
	timeBarOutline.setSize(Vector2f(404, 64));						 // 	design timebar outline
	timeBarOutline.setPosition(((1920 / 2) - 202), 978);			 //
																	 //
	Time gameTimeTotal;												 //
	float timeRemaining = 6.0f;										 // 	every second 66.6 pixels reduced.
	float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining; //
	float decrementor = 1.0f;										 //

	bool paused = true; // 	for time bar management
	int score = 0;		//
	int level = 1;

	// Text STuff:
	Text messageText;
	Text scoreText;
	Text scoreText0;
	Text levelText;
	Text levelText0;

	Font font;
	font.loadFromFile("font/KOMIKAP_.ttf");
	messageText.setFont(font);
	scoreText.setFont(font);
	scoreText0.setFont(font);
	levelText.setFont(font);
	levelText0.setFont(font);

	messageText.setString("Press Enter to start...");
	scoreText.setString("Score = 0");
	scoreText0.setString("Score = 0");
	levelText.setString("Level 1");
	levelText0.setString("Level 1");

	messageText.setCharacterSize(75);
	scoreText.setCharacterSize(100);
	scoreText0.setCharacterSize(100);
	levelText.setCharacterSize(40);
	levelText0.setCharacterSize(40);

	messageText.setFillColor(Color::White);
	scoreText.setFillColor(Color::White);
	scoreText0.setFillColor(Color::Black);
	levelText.setFillColor(Color::Yellow);
	levelText0.setFillColor(Color::Black);

	FloatRect textRect = messageText.getLocalBounds();
	messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
	// above two lines are required to bring the text to centre
	messageText.setPosition(960, 540);

	scoreText.setPosition(20, 20);
	scoreText0.setPosition(22, 22);
	levelText.setPosition(20, 135);
	levelText0.setPosition(22, 137);

	Texture textureBranch;
	textureBranch.loadFromFile("graphics/branch.png");

	for (int i = 0; i < NUM_BRANCHES; i++)
	{
		branches[i].setTexture(textureBranch);
		branches[i].setPosition(-2000, -2000); //(1110, 200) with origin (0, 0) is the ideal position
		branches[i].setOrigin(220, 20);
	}

	Texture texturePlayer;
	texturePlayer.loadFromFile("graphics/player.png");
	Sprite spritePlayer;
	spritePlayer.setTexture(texturePlayer);
	spritePlayer.setPosition(580, 720);

	side playerSide = side::LEFT;

	Texture textureAxe;
	textureAxe.loadFromFile("graphics/axe.png");
	Sprite spriteAxe;
	spriteAxe.setTexture(textureAxe);
	spriteAxe.setPosition(Axe_Left, 830);

	Texture textureRIP;
	textureRIP.loadFromFile("graphics/rip.png");
	Sprite spriteRIP;
	spriteRIP.setTexture(textureRIP);
	spriteRIP.setPosition(600, 860);

	Texture textureLog;
	textureLog.loadFromFile("graphics/log.png");
	Sprite spriteLog;
	spriteLog.setTexture(textureLog);
	spriteLog.setPosition(810, 720);

	bool logActive = false;
	float logSpeedX = 1000;
	float logSpeedY = -1500;
	bool acceptInput = false;

	// placing branches
	for (int i = 0; i < NUM_BRANCHES; i++)
	{
		updateBranches(i);
	}

	// Gaming Loop:
	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyReleased && !paused)
			{
				acceptInput = true;
				spriteAxe.setPosition(2000, spriteAxe.getPosition().y);
			}

			if (event.type == Event::Closed) // ensures window stays open until close button pressed
			{								 //
				window.close();				 //
			}
		} //

		if (Keyboard::isKeyPressed(Keyboard::Escape)) //
		{											  // exits games on clicking escape
			window.close();							  //
		} //

		if (Keyboard::isKeyPressed(Keyboard::Return)) //
		{											  // decreases remaining time when clicker "enter"
			paused = false;							  //
			score = 0;								  //
			timeRemaining = 6;
			level = 1;
			decrementor = 1;

			for (int i = 1; i < NUM_BRANCHES; i++) // Make all branches disappear
			{
				branchPositions[i] = side::NONE;
			}

			spriteRIP.setColor(sf::Color(0, 0, 0, 0));
			spritePlayer.setColor(sf::Color(255, 255, 255, 255));
			spriteAxe.setColor(sf::Color(255, 255, 255, 255));
			acceptInput = true;

		} //

		if (acceptInput) // make sure we are accepting input
		{
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				playerSide = side::LEFT;
				score++;

				timeRemaining += (2 / score) + .3;
				timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHieght));

				spritePlayer.setPosition(580, 720);
				spriteAxe.setPosition(Axe_Left, 830);
				spriteRIP.setPosition(600, 860);

				updateBranches(score);

				logSpeedX = 6000;
				logActive = true;
				acceptInput = false;
			}

			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				playerSide = side::RIGHT;
				score++;

				timeRemaining += (2 / score) + .3;
				timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHieght));

				spritePlayer.setPosition(1200, 720);
				spriteAxe.setPosition(Axe_Right, 830);
				spriteRIP.setPosition(1170, 860);

				updateBranches(score);

				logSpeedX = -6000;
				logActive = true;
				acceptInput = false;
			}
		}

		Time dt = clock.restart(); // clock dependent algos come below this line.

		if (!paused)
		{
			timeRemaining -= decrementor * dt.asSeconds(); // time decreases.
			timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHieght));

			if (timeRemaining <= 0.0f)
			{
				paused = true;
				messageText.setString("GAME OVER!!!");
				messageText.setFillColor(Color::Red);
				messageText.setCharacterSize(130);
				FloatRect textRect = messageText.getLocalBounds();
				messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
				messageText.setPosition(960, 540);
				spriteRIP.setColor(sf::Color(255, 255, 255, 255));
				spritePlayer.setColor(sf::Color(0, 0, 0, 0));
				// spriteAxe.setColor(sf::Color(0, 0, 0, 0));
			}

			if (branchPositions[5] == playerSide) // death
			{
				paused = true;
				messageText.setString("GAME OVER!!!");
				messageText.setFillColor(Color::Red);
				messageText.setCharacterSize(130);
				FloatRect textRect = messageText.getLocalBounds();
				messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
				messageText.setPosition(960, 540);

				timeRemaining = 0.0f;

				spriteRIP.setColor(sf::Color(255, 255, 255, 255));
				spritePlayer.setColor(sf::Color(0, 0, 0, 0));
				spriteAxe.setColor(sf::Color(0, 0, 0, 0)); // book re player position window baharuku jauchi, not this way

				acceptInput = false;
			}

			if (timeRemaining >= 6.1f)
			{
				timeRemaining = 4.5f;
				decrementor += 0.1f;
				level++;
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

			std::stringstream ss;
			ss << "Score = " << score;
			scoreText.setString(ss.str());
			scoreText0.setString(ss.str());

			std::stringstream ls;
			ls << "Level " << level;
			levelText.setString(ls.str());
			levelText0.setString(ls.str());

			for (int i = 0; i < NUM_BRANCHES; i++)
			{

				float height = i * 150;

				if (branchPositions[i] == side::LEFT)
				{

					branches[i].setPosition(610, height);
					branches[i].setOrigin(220, 40);
					branches[i].setRotation(180);
				}
				else if (branchPositions[i] == side::RIGHT)
				{

					branches[i].setPosition(1330, height);
					branches[i].setOrigin(220, 40);
					branches[i].setRotation(0);
				}
				else
				{
					// Hide the branch
					branches[i].setPosition(3000, height);
				}
			}

			// log phinga phingi
			if (logActive)
			{
				spriteLog.setPosition(spriteLog.getPosition().x + (logSpeedX * dt.asSeconds()), spriteLog.getPosition().y + (logSpeedY * dt.asSeconds()));

				if (spriteLog.getPosition().x < -2000 || spriteLog.getPosition().x > 2000)
				{
					logActive = false;
					spriteLog.setPosition(810, 720);
				}
			}

		} // end of if(!paused)

		window.clear();				   // Blank Canvas
		window.draw(spriteBackground); // Draws bg
		window.draw(spriteCloud2);	   //
		window.draw(spriteCloud3);	   // Draws Clouds
		window.draw(spriteCloud1);	   //

		window.draw(spritePlayer);

		for (int i = 0; i < NUM_BRANCHES; i++)
		{
			window.draw(branches[i]);
		}

		window.draw(spriteTree); // Draws tree
		window.draw(spriteLog);

		window.draw(spriteRIP);
		window.draw(spriteAxe);

		window.draw(spriteBee);		 // Draws bee
		window.draw(timeBarOutline); // Draws timebar outline
		window.draw(timeBar);		 // Draws timebar

		if (paused)
		{
			window.draw(messageText);
		}

		window.draw(scoreText0);
		window.draw(scoreText);
		window.draw(levelText0);
		window.draw(levelText);
		window.display(); //
	}

	return 0;
}

void updateBranches(int seed)
{

	// Shift all branches down
	for (int i = NUM_BRANCHES - 1; i > 0; i--)
	{
		branchPositions[i] = branchPositions[i - 1];
	}

	// New branch at zeroth position (Top of tree)
	srand((int)time(0) + seed);
	int r = (rand() % 5);
	switch (r)
	{
	case 0:
		branchPositions[0] = side::LEFT;
		break;

	case 1:
		branchPositions[0] = side::RIGHT;
		break;

	default:
		branchPositions[0] = side::NONE;
		break;
	}
}