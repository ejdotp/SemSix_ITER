#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{

    VideoMode vm(960, 540); // OBJECT vm CREATED

    RenderWindow window(vm, "TIMBER MAN"); // Add 3rd field <Style::Fullscreem> to open fullscreen by default

    while (window.isOpen())
    {

        Event event;                         //
        while (window.pollEvent(event))      //
        {                                    //
            if (event.type == Event::Closed) // ensures window stays open until close button pressed
            {                                //
                window.close();              //
            } //
        } //

        if (Keyboard::isKeyPressed(Keyboard::Escape)) //
        {                                             // exits games on clicking escape
            window.close();                           //
        } //

        window.clear();

        window.display();
    }

    return 0;
}