#pragma once
#include "FileManager.h"

class Application
{
    sf::RenderWindow window;

    sf::Texture currentTexture;
    sf::Sprite currentSprite;

    sf::Sprite menu;

    sf::Font font;
    sf::Event event;

    FileManager fileManager;
    TouristRouteManager manager;
    bool isLoadingScreenOn;
public:

    Application();
    void run();
    void handleEvents();
    void handleMouseClick(const sf::Vector2f& clickPos);
    void render();

};