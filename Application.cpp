#include "Application.h"

Application::Application() : window(sf::VideoMode(1080, 720), "Tourist Route Manager") 
{
    if (!currentTexture.loadFromFile("Resources/Botw_Map.png"))
    {
        throw std::runtime_error("No se encontro la imagen");
    }
    if (!font.loadFromFile("Resources/ComicSans.ttf"))
    {
        throw std::runtime_error("No se encontro el formato de texto");
    }
        
    currentSprite.setTexture(currentTexture);
    currentSprite.setScale(float(window.getSize().x) / float(currentTexture.getSize().x), float(window.getSize().y) / float(currentTexture.getSize().y));

}

void Application::run()
{
    while (window.isOpen())
    {
        render();
        handleEvents();
    }
}
void Application::handleEvents()
{
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                if (currentSprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
                {
                    handleMouseClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                }
            }
        }
    }
}

void Application::handleMouseClick(const sf::Vector2f& clickPos)
{
    sf::Text userInputText;
    userInputText.setFont(font);
    userInputText.setCharacterSize(24);
    userInputText.setFillColor(sf::Color::White);
    userInputText.setPosition(clickPos);

    std::string pointName;

    bool hasPressedEnter = 0;

    while(!hasPressedEnter) 
    {
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::TextEntered) 
            {
                if (event.text.unicode == '\b') 
                {
                    if (!pointName.empty()) {
                        pointName.pop_back();
                    }
                }
                else if (event.text.unicode == '\r' || event.text.unicode == '\n') 
                {
                    hasPressedEnter = 1;
                }
                else if (event.text.unicode < 128) 
                {
                    pointName += static_cast<char>(event.text.unicode);
                }

                userInputText.setString(pointName);
            }

            else if (event.type == sf::Event::Closed) {
                window.close();
                return;
            }
        }

        window.draw(userInputText);
        window.display();
    }


    manager.addPoint(clickPos, pointName);

}

void Application::render()
{
    window.clear();
    window.draw(currentSprite);
    manager.drawRoutes(window);

    window.display();
}