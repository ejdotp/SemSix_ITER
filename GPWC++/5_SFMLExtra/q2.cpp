/*to diplay and set centre of the message text soa university to center of screen size 1920x1080. character size = 100 color red, font konikap.ttf*/

#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{

    VideoMode vm(960, 540);

    RenderWindow window(vm, "Text Example");

    View view(FloatRect(0, 0, 1920, 1080));
    window.setView(view);

    Font font;
    font.loadFromFile("KOMIKAP_.ttf");

    // Text message;
    // message.setString("SOA University");
    // message.setCharacterSize(100);
    // message.setFont(font);
    // can be written as:

    Text message("SOA University", font, 100);

    message.setFillColor(Color::Red);

    // FloatRect textRect = messageText.getLocalBounds();
    // messageText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    // messageText.setPosition(960, 540);
    // can be done directly like:

    message.setPosition((1920 - message.getGlobalBounds().width) / 2.0, (1080 - message.getGlobalBounds().height) / 2.0);

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

        window.draw(message);

        window.display();
    }

    return 0;
}
