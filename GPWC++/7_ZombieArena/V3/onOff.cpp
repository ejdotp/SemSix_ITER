#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "ON/OFF State Example");

    // Load textures and sprites
    Texture playerTexture, bloaterTexture;
    playerTexture.loadFromFile("ZombieArena_Final/graphics/player.png");
    bloaterTexture.loadFromFile("ZombieArena_Final/graphics/bloater.png");
    Sprite playerSprite(playerTexture);
    Sprite bloaterSprite(bloaterTexture);

    // Center sprites
    playerSprite.setOrigin(playerTexture.getSize().x / 2, playerTexture.getSize().y / 2);
    bloaterSprite.setOrigin(bloaterTexture.getSize().x / 2, bloaterTexture.getSize().y / 2);
    playerSprite.setPosition(400, 300);
    bloaterSprite.setPosition(400, 300);

    FloatRect rect(100.f, 200.f, 300.f, 200.f);

    // Game state
    enum class State
    {
        ON,
        OFF
    };
    State state = State::ON;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Return)
            {
                // Toggle state
                state = (state == State::ON) ? State::OFF : State::ON;
            }
        }

        window.clear(Color::Red);

        if (state == State::ON)
            window.draw(playerSprite);
        else
            window.draw(bloaterSprite);

        window.display();
    }
    return 0;
}