#pragma once
#include "FileManager.h"

class Application
{
    sf::RenderWindow window;

    sf::Texture currentTexture;
    sf::Sprite currentSprite; //can be loading screen too

    sf::Sprite menu; // a circle that goes into a rectangle and shows the routes scrolling

    sf::Texture settingsTexture;
    sf::Sprite settings;
    sf::RectangleShape nextButton; 

    sf::Font font;
    sf::Event event;
    sf::Color color;

    FileManager fileManager;
    TouristRouteManager manager;

    bool isLoadingScreenOn;
    bool isSettingsOn;

public:

    Application();
    void run();
    void handleEvents();
    void handleMouseClick(const sf::Vector2f& clickPos);
    void changeSettings();
    void render();

};