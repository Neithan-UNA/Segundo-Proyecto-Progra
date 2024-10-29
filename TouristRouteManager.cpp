#include "TouristRouteManager.h"

TouristRouteManager::TouristRouteManager() : window(sf::VideoMode(1080, 720), "Tourist Route Manager"), insertionMode(true), lastIsDone(true)
{
    if (!mapTexture.loadFromFile("C:/Users/neith/Desktop/Botw_MAP.jpeg"))
    {
        throw std::runtime_error("No se encontro la imagen");
    }
    if (!font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        throw std::runtime_error("No se encontro el formato de texto");
    }

    mapSprite.setTexture(mapTexture);
    mapSprite.setScale(float(window.getSize().x) / float(mapTexture.getSize().x), float(window.getSize().y) / float(mapTexture.getSize().y));
    currentColor = sf::Color::Red;
}
TouristRouteManager::~TouristRouteManager() {}

void TouristRouteManager::run()
{
    while (window.isOpen())
    {
        render();
        handleEvents();
    }
}

void TouristRouteManager::handleEvents()
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                sf::FloatRect bounds = mapSprite.getGlobalBounds();
                bounds.width -= 100;
                if(bounds.contains(sf::Vector2f(event.mouseButton.x,event.mouseButton.y)))
                {
                    handleMouseClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                }
            }
        }
    }
}

void TouristRouteManager::handleMouseClick(const sf::Vector2f& clickPos)
{
    sf::Text userInputText;
    userInputText.setFont(font);
    userInputText.setCharacterSize(24);
    userInputText.setFillColor(sf::Color::White);
    userInputText.setPosition(0, 0);
    std::string pointName = " ";

    if (insertionMode && lastIsDone)
    {
        lastIsDone = false;
        sf::RenderWindow window2(sf::VideoMode(360, 240), "Tourist Route Manager");

        while (window2.isOpen())
        {
            sf::Event event;
            while (window2.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                {
                    window2.close();
                }
                else if (event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode == '\b')
                    {
                        if (!pointName.empty()) {
                            pointName.pop_back();
                        }
                    }
                    else if (event.text.unicode == '\r')
                    {
                        window2.close();

                    }
                    else if (event.text.unicode < 128)
                    {
                        pointName += static_cast<char>(event.text.unicode);
                    }

                    userInputText.setString(pointName);
                }
            }

            window2.clear(sf::Color::Black);
            window2.draw(userInputText);
            window2.display();
        }
        currentRoute.addPoint(clickPos, pointName, lastIsDone);
    }
}

void TouristRouteManager::render()
{
    window.clear();
    window.draw(mapSprite);
    currentRoute.drawRoute(window);

    window.display();
}
