/*Write a SFML C++ code to fly the image soa.jpeg across the screen from top centre to bottom of screen. You can make use of sprite class method setscale to set the scale factors of the sprite object.*/

#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    VideoMode vm(960, 540);

    RenderWindow window(vm, "SOA");

    View view(FloatRect(0, 0, 1920, 1080));
    window.setView(view);

    Texture SOA;
    SOA.loadFromFile("SOA.png");
    Sprite soa;
    soa.setTexture(SOA);
    soa.setScale(0.2, 0.2);
    FloatRect logo = soa.getLocalBounds();
    soa.setOrigin(logo.left + logo.width / 2.0f, logo.top + logo.height / 2.0f);
    soa.setPosition(940, 0);

    bool yes = true;

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
        if (yes)
        {
            soa.move(0, 2);
            if (soa.getPosition().y > 1080)
            {
                yes = false;
            }
        }
        else
        {
            soa.move(0, -2);
            if (soa.getPosition().y < 0)
            {
                yes = true;
            }
        }

        window.clear();
        window.draw(soa);
        window.display();
    }

    return 0;
}