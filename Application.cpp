#include "Application.h"

Application::Application() : window(sf::VideoMode(1080, 720), "Tourist Route Manager"), isSettingsOn(true), color(sf::Color::Red)
{
    if (!currentTexture.loadFromFile("Resources/Botw_Map.png"))
    {
        throw std::runtime_error("No se encontro la imagen");
    }
    if (!settingsTexture.loadFromFile("Resources/Settings.png"))
    {
        throw std::runtime_error("No se encontro la imagen");
    }
    if (!font.loadFromFile("Resources/ComicSans.ttf"))
    {
        throw std::runtime_error("No se encontro el formato de texto");
    }
    
    currentSprite.setTexture(currentTexture);
    currentSprite.setScale(float(window.getSize().x) / float(currentTexture.getSize().x), float(window.getSize().y) / float(currentTexture.getSize().y));

    changeSettings();
}

void Application::run()
{
   
    fileManager.loadFromFile(manager);

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
        {     
            window.close();
        }
        else if (event.type == sf::Event::TextEntered)
        {
            if (event.text.unicode == 27)
            {
                changeSettings();
            }
        }
        else if (event.type == sf::Event::MouseButtonPressed)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {   
                if(settings.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x,event.mouseButton.y)) && !isSettingsOn)
                {
                    changeSettings();
                }
                else if (currentSprite.getGlobalBounds().contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)) && !isSettingsOn)
                {
                    handleMouseClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                }
                
            }
        }
    }
}
void Application::changeSettings()
{
    if(!isSettingsOn)
    {
        isSettingsOn = true;
        settings.setTexture(getRoundedCornerRectangle(sf::Color::White)->getTexture());
        settings.setScale(4, 3);
        settings.setPosition(window.getSize().x *0.2, window.getSize().y *0.1);
    }
    else
    {
        isSettingsOn = false;
        settings.setTexture(settingsTexture);
        settings.setScale(float(window.getSize().x) / (float(currentTexture.getSize().x) * 10), float(window.getSize().y) / (float(currentTexture.getSize().y) * 10));
        settings.setPosition(window.getSize().x - 100, window.getSize().y - 100);
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


    manager.addPoint(clickPos, pointName,color);
    fileManager.saveToFile(manager);
}

void Application::render()
{
    window.clear();

    window.draw(currentSprite);
    manager.drawRoutes(window);
    window.draw(settings);
    

    window.display();
}

//modo insercion
//seleccionar puntos turisticos, resaltar ruta turistica cuando pasa
//crear rutas turisticas
//hacerle un cuadro de dialogo a la vara
//hacer las settings y menu