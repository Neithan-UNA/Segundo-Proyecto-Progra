#include "RoundedCornersRectangle.h"

class RoundedCornersRectangle : sf::RectangleShape
{
    void doSomething()
    {
        sf::RenderTexture something;

        sf::RectangleShape rec1(sf::Vector2f(100, 100));
        sf::RectangleShape rec2(sf::Vector2f(100, 100));
        sf::RectangleShape rec3(sf::Vector2f(100, 100));
        sf::RectangleShape rec4(sf::Vector2f(100, 100));
        sf::RectangleShape rec5(sf::Vector2f(100, 100));

        rec1.setOrigin(-100, 0);
        rec2.setOrigin(0, -100);
        rec3.setOrigin(-100, -100);
        rec4.setOrigin(-100, -200);
        rec5.setOrigin(-200, -100);

        sf::CircleShape cir1(100);
        sf::CircleShape cir2(100);
        sf::CircleShape cir3(100);
        sf::CircleShape cir4(100);

        cir1.setOrigin(0, 0);
        cir2.setOrigin(-100, 0);
        cir3.setOrigin(0, -100);
        cir4.setOrigin(-100, -100);

        something.draw(rec1);
        something.draw(rec2);
        something.draw(rec3);
        something.draw(rec4);
        something.draw(rec5);
        something.draw(cir1);
        something.draw(cir2);
        something.draw(cir3);
        something.draw(cir4);

    }
};