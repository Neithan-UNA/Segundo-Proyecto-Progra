#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>


class TouristPoint
{
    sf::Color color;
    std::string name;
    sf::Vector2f position;
    sf::CircleShape shape;

    TouristPoint* next;
    TouristPoint* prev;

public:

    TouristPoint(const sf::Vector2f pos, const std::string pointName, const sf::Color pointColor) : position(pos), name(pointName), color(pointColor), next(nullptr), prev(nullptr)
    {
        shape.setRadius(7.f);
        shape.setPosition(pos);
        shape.setFillColor(color);
        shape.setOrigin(5.f, 5.f);

        /*
        text.setCharacterSize(12);
        text.setFillColor(color);
        text.setPosition(pos.x + 10, pos.y);
        text.setFillColor(color);
        */
    }
    ~TouristPoint() {}
    TouristPoint* getNext()
    {
        return next;
    }
    void setNext(TouristPoint* touristP)
    {
        next = touristP;
    }
    void setPrev(TouristPoint* touristP)
    {
        prev = touristP;
    }
    void draw(sf::RenderWindow& window)
    {
        window.draw(shape);
    }

    sf::Vector2f getPosition()
    {
        return position;
    }

    void setColor(const sf::Color& newColor)
    {
        color = newColor;
        shape.setFillColor(color);
    }
    
};


class TouristRoute
{

    std::string name;
    TouristPoint* head;
    TouristPoint* tail;
    sf::Color routeColor;


public:



    TouristRoute(const std::string routeName, const sf::Color color, const sf::Font fontRef) : name(routeName), head(nullptr), tail(nullptr), routeColor(color) {}
    TouristRoute() : name("none"), head(nullptr), tail(nullptr), routeColor(sf::Color::Red) {}
    ~TouristRoute() {}

    void addPoint(const sf::Vector2f& pos, const std::string pointName, bool &isNewPointAdded)
    {
        TouristPoint* point = new TouristPoint(pos, pointName, routeColor);

        if (!head)
        {
            head = point;
        }
        else
        {
            TouristPoint* auxiliar = head;

            while (auxiliar->getNext() != NULL)
            {
                auxiliar = auxiliar->getNext();
            }
            auxiliar->setNext(point);
            point->setPrev(auxiliar);
        }
        isNewPointAdded = 1;
    }

    void drawRoute(sf::RenderWindow& window)
    {

        TouristPoint* current = head;

        while (current)
        {
            if (current->getNext())
            {
                float dx = current->getPosition().x - current->getNext()->getPosition().x;
                float dy = current->getPosition().y - current->getNext()->getPosition().y;

                sf::RectangleShape line(sf::Vector2f(sqrt((dx * dx) + (dy * dy)), 2.0f));

                float rotation = ((atan2(dy, dx) * 180.f) / 3.14159f) - 180;

                line.setPosition(current->getPosition());
                line.setRotation(rotation);
                line.setFillColor(sf::Color::White);

                window.draw(line);
            }


            current->draw(window);

            current = current->getNext();
        }
    }

    // son necesarios todos los metodos de una lista??
};


class TouristRouteManager
{

    sf::RenderWindow window;
    sf::Texture mapTexture;
    sf::Sprite mapSprite;
    sf::Font font;
    sf::Color currentColor;
    sf::Event event;
    TouristRoute currentRoute;


    bool insertionMode;
    bool lastIsDone;

public:

    TouristRouteManager() : window(sf::VideoMode(1080, 720), "Tourist Route Manager"), insertionMode(true), lastIsDone(true)
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
    ~TouristRouteManager() {}

    void run()
    {
        
        while (window.isOpen())
        {
            render();
            handleEvents();   
        }
    }

    void handleEvents()
    {
        while(window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    handleMouseClick(sf::Vector2f(event.mouseButton.x, event.mouseButton.y));
                }
            }
        } 
        

    }

    void handleMouseClick(const sf::Vector2f& clickPos)
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

            while(window2.isOpen())
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
                        { // Handle backspace
                            if (!pointName.empty()) {
                                pointName.pop_back();
                            }
                        }
                        else if (event.text.unicode == '\r') 
                        { // Handle Enter key
                            window2.close();
                            // You can add code here to handle what happens when the user presses Enter
                        }
                        else if (event.text.unicode < 128) 
                        { // Filter ASCII characters
                            pointName += static_cast<char>(event.text.unicode);
                        }

                        userInputText.setString(pointName); // Update text display
                    }
                }

                window2.clear(sf::Color::Black);
                window2.draw(userInputText);
                window2.display();
            }

            currentRoute.addPoint(clickPos, pointName,lastIsDone);
        }
        
    }

    void render()
    {
        


        window.clear();
        window.draw(mapSprite);
        currentRoute.drawRoute(window);

        window.display();
    }
};

int main()
{
    TouristRouteManager manager;
    manager.run();

    return 0;
}

/*
#include <SFML/Graphics.hpp>
#include <iostream>

class RotatingSprite : public sf::Sprite
{

    sf::Clock clock;
    bool isRotating;

public:
    RotatingSprite(const sf::Texture& texture) : sf::Sprite(texture), isRotating(false)
    {
        sf::FloatRect bounds = getLocalBounds();
        setOrigin(bounds.width / 2, bounds.height / 2);
    }

    void startRotation()
    {
        if (!isRotating)
        {
            isRotating = true;
            clock.restart();
        }
    }

    void update()
    {
        if (isRotating)
        {
            float elapsedTime = clock.getElapsedTime().asSeconds();
            float rotationSpeed = 60.f; // 90 degrees per second
            float newRotation = elapsedTime * rotationSpeed;

            if (newRotation >= 360.f)
            {
                setRotation(0.f);
                isRotating = false;
            }
            else {
                setRotation(newRotation);
            }
        }
    }

};

#define SizeWidth 800
#define SizeHeight 600

class Application
{
    sf::RenderWindow window;
    sf::Sprite map;

public:

    Application() : window(sf::VideoMode(SizeWidth, SizeHeight), "Black Background")
    {
        render();
    }

    void handleEvents()
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::FloatRect bounds = map.getGlobalBounds();
                if (bounds.contains(mousePos.x, mousePos.y))
                {
                    map.setScale(0.5, 0.5);
                    map.setPosition(mousePos.x, mousePos.y);
                }

            }
        }
    }
    void render()
    {
        sf::Texture texture;
        if (!texture.loadFromFile("C:/Users/neith/Desktop/Botw_MAP.jpeg"))
        {
        }
        std::cout << sf::VideoMode::getDesktopMode().width << ", " << sf::VideoMode::getDesktopMode().height;
        map.setTexture(texture);
        map.setOrigin(0,0);

        //2060, 1159
        map.setScale(float(sf::VideoMode::getDesktopMode().width)/2060, float(sf::VideoMode::getDesktopMode().height)/1159);

        while (window.isOpen())
        {

            handleEvents();

            window.clear(sf::Color::Black);
            window.draw(map);
            window.display();
        }
    }
};

int main()
{
    Application app;



    return 0;
}
*/