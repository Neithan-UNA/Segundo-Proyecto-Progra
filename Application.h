#pragma once
#include "FileManager.h"

class Application
{
    sf::RenderWindow window;
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
    sf::Sprite menu;
    sf::Font font;
    sf::Event event;
    FileManager fileManager;

public:

    Application();
    void run();
    void handleEvents();
    void handleMouseClick(const sf::Vector2f& clickPos);
    void render();
};