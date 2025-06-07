// Q1
// The Clock clock; clock.restart() function restart the clock. The clock is restarted in every frame to know how long each and every frame takes. In addition, however, clock.restart(); returns the amount of time that has elapsed since the last time we restarted the clock. So, compute the distance a spriteBee object will cover in a frame assuming the speed of the spriteBee is beeSpeed pixels/second.
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    Clock clock;
    distance = beeSpeed * elapsedTime;

    float beeSpeed = 200.0f;

    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        float distance = beeSpeed * dt;
        spriteBee.move(distance, 0);
    }
}

/*
The time elapsed between frames can be obtained using clock.restart().asSeconds().

speed = distance / time

The distance covered by the spriteBee in a frame is calculated as -

distance = beeSpeed × elapsedTime
*/
