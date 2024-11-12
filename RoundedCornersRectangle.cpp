#include "RoundedCornersRectangle.h"


float getLinearInterpolationValue(float startValue, float endValue, float ratio)
{
    return startValue + (endValue - startValue) * ratio;
}

sf::Vector2f getLinearInterpolationPoint(sf::Vector2f startPoint, sf::Vector2f endPoint, float ratio)
{
    sf::Vector2f point(getLinearInterpolationValue(startPoint.x, endPoint.x, ratio), getLinearInterpolationValue(startPoint.y, endPoint.y, ratio));
    return point;
}
sf::Vector2f getCuadraticInterpolationPoint(sf::Vector2f startPoint, sf::Vector2f endPoint, float ratio)
{
    sf::Vector2f middlePoint((startPoint.x + endPoint.x) / 2 + 50, (startPoint.y + endPoint.y) / 2 + 50);
    return getLinearInterpolationPoint(getLinearInterpolationPoint(startPoint, middlePoint, (float)ratio / 100), getLinearInterpolationPoint(middlePoint, endPoint, (float)ratio / 100), (float)ratio / 100);
}


sf::RenderTexture* getRoundedCornerRectangle()
{
    sf::RenderTexture renderTexture;
    if (!renderTexture.create(400, 400)) {
        std::cout << "gone";
    }
    renderTexture.clear(sf::Color(50, 50, 50));

    // Create some shapes to draw

    sf::RectangleShape rec1(sf::Vector2f(100, 100));
    sf::RectangleShape rec2(sf::Vector2f(100, 100));
    sf::RectangleShape rec3(sf::Vector2f(100, 100));
    sf::RectangleShape rec4(sf::Vector2f(100, 100));
    sf::RectangleShape rec5(sf::Vector2f(100, 100));

    sf::CircleShape cir1(100);
    sf::CircleShape cir2(100);
    sf::CircleShape cir3(100);
    sf::CircleShape cir4(100);

    rec1.setPosition(-100, 0);
    rec2.setPosition(0, -100);
    rec3.setPosition(-100, -100);
    rec4.setPosition(-100, -200);
    rec5.setPosition(-200, -100);

    cir1.setPosition(0, 0);
    cir2.setPosition(-100, 0);
    cir3.setPosition(0, -100);
    cir4.setPosition(-100, -100);

    rec1.setFillColor(sf::Color::Cyan);
    rec2.setFillColor(sf::Color::Cyan);
    rec3.setFillColor(sf::Color::Cyan);
    rec4.setFillColor(sf::Color::Cyan);
    rec5.setFillColor(sf::Color::Cyan);

    cir1.setFillColor(sf::Color::Cyan);
    cir2.setFillColor(sf::Color::Cyan);
    cir3.setFillColor(sf::Color::Cyan);
    cir4.setFillColor(sf::Color::Cyan);
    /*
    sf::CircleShape circle(50.f);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition(100.f, 100.f);

    sf::RectangleShape rectangle(sf::Vector2f(100.f, 60.f));
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(200.f, 150.f);

    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(0.f, 0.f));
    triangle.setPoint(1, sf::Vector2f(60.f, 0.f));
    triangle.setPoint(2, sf::Vector2f(30.f, 50.f));
    triangle.setFillColor(sf::Color::Blue);
    triangle.setPosition(50.f, 200.f);
    */
    renderTexture.draw(rec1);
    renderTexture.draw(rec2);
    renderTexture.draw(rec3);
    renderTexture.draw(rec4);
    renderTexture.draw(rec5);

    renderTexture.draw(cir1);
    renderTexture.draw(cir2);
    renderTexture.draw(cir3);
    renderTexture.draw(cir4);


    
    renderTexture.display();

    sf::Sprite sprite(renderTexture.getTexture());
    sprite.setPosition(200.f, 150.f);

    /*
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

    rec1.setFillColor(sf::Color::Cyan);
    rec2.setFillColor(sf::Color::Cyan);
    rec3.setFillColor(sf::Color::Cyan);
    rec4.setFillColor(sf::Color::Cyan);
    rec5.setFillColor(sf::Color::Cyan);

    cir1.setFillColor(sf::Color::Cyan);
    cir2.setFillColor(sf::Color::Cyan);
    cir3.setFillColor(sf::Color::Cyan);
    cir4.setFillColor(sf::Color::Cyan);
    
    something.clear(sf::Color::Transparent);

    something.draw(rec1);
    something.draw(rec2);
    something.draw(rec3);
    something.draw(rec4);
    something.draw(rec5);
    
    something.draw(cir1);
    something.draw(cir2);
    something.draw(cir3);
    something.draw(cir4);

    something.display();

    sf::Sprite a;
  
    a.setOrigin(0, 0);
    a.setTexture(something.getTexture());
    */

    sf::RenderWindow window2(sf::VideoMode(1080, 720), "seeing");
    while (window2.isOpen())
    {
        sf::Event event;

        while (window2.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window2.close();
            }
        }

        window2.clear(sf::Color::Black);

        window2.draw(sprite);

        /*
        window2.draw(rec1);
        window2.draw(rec2);
        window2.draw(rec3);
        window2.draw(rec4);
        window2.draw(rec5);
        window2.draw(cir1);
        window2.draw(cir2);
        window2.draw(cir3);
        */

        window2.display();
    }
    return &renderTexture;

}
