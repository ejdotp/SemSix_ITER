# SFML Extra Questions and Solutions

## Q1. Clock and Movement Calculation

**Question:** The `Clock clock; clock.restart()` function restarts the clock. The clock is restarted in every frame to know how long each and every frame takes. In addition, `clock.restart()` returns the amount of time that has elapsed since the last time we restarted the clock. Compute the distance a `spriteBee` object will cover in a frame assuming the speed of the `spriteBee` is `beeSpeed` pixels/second.

**Solution:**

```cpp
Clock clock;
float beeSpeed = 200.0f;

while (window.isOpen())
{
    float dt = clock.restart().asSeconds();  // Time elapsed in seconds
    float distance = beeSpeed * dt;          // Distance covered in this frame
    spriteBee.move(distance, 0);             // Move bee horizontally
}
```

## Q2. Drawing a Centered Rectangle

**Question:** Construct SFML-C++ statements to draw a red filled rectangle shape of width X and height Y on the screen 1920 × 1080 at the center of the screen.

**Solution:**

```cpp
#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    VideoMode vm(1920, 1080);
    RenderWindow window(vm, "Rectangle");

    float X = 300, Y = 200;  // Dimensions of the rectangle

    RectangleShape rect(Vector2f(X, Y));
    rect.setFillColor(Color::Red);
    rect.setPosition((1920 - X) / 2, (1080 - Y) / 2);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(rect);
        window.display();
    }
}
```

## Q3. Drawing Multiple Circles

**Question:** Construct SFML-C++ statements to draw FOUR green filled circle shapes of radius X on the screen 1920 × 1080 close to 4 corners of the screen. Additionally one center stretched circle with red filled of the same radius using `sf::CircleShape` Class Reference.

**Solution:**

```cpp
VideoMode vm(1920, 1080);
RenderWindow window(vm, "Circles");

float radius = 50;

CircleShape circles[4];

for (int i = 0; i < 4; i++)
{
    circles[i].setRadius(radius);
    circles[i].setFillColor(Color::Green);
}

circles[0].setPosition(0, 0);                    // Top-left
circles[1].setPosition(1920 - 2 * radius, 0);    // Top-right
circles[2].setPosition(0, 1080 - 2 * radius);    // Bottom-left
circles[3].setPosition(1920 - 2 * radius, 1080 - 2 * radius); // Bottom-right

CircleShape centerCircle(radius);
centerCircle.setScale(2.f, 1.f);
centerCircle.setFillColor(Color::Red);
centerCircle.setPosition(960 - radius, 540 - radius / 2);

while (window.isOpen())
{
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            window.close();
    }

    window.clear();
    for (int i = 0; i < 4; i++)
        window.draw(circles[i]);
    window.draw(centerCircle);
    window.display();
}
```

## Q4. Array Shifting

**Question:** Create a program to generate a random 1-D array of size 10. Additionally shift each of the array elements 2 positions to right and filled the beginning two places with random elements from the range 20 to 30. Finally display both the arrays.

**Solution:**

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int A[10], B[10];

    // Generate random array
    for (int i = 0; i < 10; i++) {
        A[i] = rand() % 100;
        cout << A[i] << " ";
    }

    // Shift right by 2 and fill with [20, 30]
    B[0] = 20 + rand() % 11;
    B[1] = 20 + rand() % 11;

    for (int i = 2; i < 10; i++)
    {
        B[i] = A[i - 2];
    }

    for (int i = 0; i < 10; i++) {
        cout << B[i] << " ";
    }
}
```

## Q5. Class Destructor

**Question:** Consider the following C++ code snippet:

```cpp
class A
{
private:
    int x, y;

public:
    void setXY(int x1, int y1)
    {
        x = x1;
        y = y1;
    }

    void getXY()
    {
        cout << x << " " << y << endl;
    }
    ~A()
    {
        cout << "END" << endl;
    }
};

int main()
{
    A a1, a2;
    a1.setXY(10, 20);
    a2.setXY(40, 50);
    a1.getXY();
    return 0;
}
```

**Output:**

```
10 20
END
END
```

## Q6. Enum Values

**Question:** Consider the following C++ code snippet:

```cpp
enum colour
{
    blue, red, yellow
};

int main()
{
    enum colour c;
    c = yellow;
    cout << c << endl;
}
```

**Output:** `2`
**Explanation:** yellow is the third value in the enum, its value is 2.

## Q7. Enum Sequence

**Question:** Consider the following C++ code snippet:

```cpp
enum hello
{
    a, b = 99, c, d = -1
};

int main()
{
    enum hello m;
    cout << a << " " << b << " " << c << " " << d << endl;
    return 0;
}
```

**Output:** `0 99 100 -1`

**Explanation:**

- a = 0 (default)
- b = 99 (explicit)
- c = 100 (next in sequence)
- d = -1 (explicit)

## Q8. SFML Sound Setup

**Question:** SFML plays sound effect using two different classes; SoundBuffer and Sound. Write the code snippet to set up the sound effect that would be played on the Timber game event player runs out of time.

**Solution:**

```cpp
SoundBuffer buffer;
buffer.loadFromFile("timeout.wav");

Sound sound;
sound.setBuffer(buffer);
sound.play();
```

## Q9. SFML Object Creation

**Question:** Write the code snippet to create two objects for each of the given classes; Text, Font, SoundBuffer, Clock, RectangleShape and FloatRect respectively.

**Solution:**

```cpp
Text text1, text2;
Font font1, font2;
SoundBuffer buffer1, buffer2;
Clock clock1, clock2;
RectangleShape rect1, rect2;
FloatRect floatRect1, floatRect2;
```

## Q10. Keyboard Input Detection

**Question:** Write the code snippet to detect the Keyboard input, enter key, from the user using Keyboard class and also display a message, "Enter Pressed" on the output stream, if enter key is pressed.

**Solution:**

```cpp
if (Keyboard::isKeyPressed(Keyboard::Return))
{
    cout << "Enter Pressed" << endl;
}
```

## Q11. Texture and Sprite Setup

**Question:** Fill out the places marked with the symbol, ?, in the following code snippet:

```cpp
Texture ?;
?.loadFromFile("sample.png");
Sprite ?;
?.setTexture(?);
?.?(960,540);
```

**Solution:**

```cpp
Texture texture;
texture.loadFromFile("sample.png");
Sprite sprite;
sprite.setTexture(texture);
sprite.setPosition(960, 540);
```

## Q12. Centered Text Display

**Question:** Write SFML-C++ statements to display and set the center of the a message text "SOA UNIVERSITY" to the center of the screen of size 1920×1080. Additionally set the character size 100, text color Red and font family KONIKAP.ttf.

**Solution:**

```cpp
VideoMode vm(1920, 1080);
RenderWindow window(vm, "Text Example");

Font font;
font.loadFromFile("KONIKAP.ttf");

Text text("SOA UNIVERSITY", font, 100);
text.setFillColor(Color::Red);

text.setPosition((1920 - text.getGlobalBounds().width) / 2,
                 (1080 - text.getGlobalBounds().height) / 2);

while (window.isOpen())
{
    Event event;
    while (window.pollEvent(event))
    {
        if (event.type == Event::Closed)
            window.close();
    }

    window.clear();
    window.draw(text);
    window.display();
}
```
