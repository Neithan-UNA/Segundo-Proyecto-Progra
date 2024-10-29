#pragma once
#include "TouristPointList.h"

class TouristRouteManager
{

    sf::RenderWindow window;
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
    sf::Font font;
    sf::Color currentColor;
    sf::Event event;
    TouristPointList currentRoute;

    bool insertionMode;
    bool lastIsDone;

public:

    TouristRouteManager();
    ~TouristRouteManager();
    void run();
    void handleEvents();
    void handleMouseClick(const sf::Vector2f& clickPos);
    void render();

};