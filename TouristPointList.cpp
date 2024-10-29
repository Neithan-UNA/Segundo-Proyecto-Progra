#include "TouristPointList.h"

TouristPointList::TouristPointList(const std::string routeName, const sf::Color color, const sf::Font fontRef) : name(routeName), head(nullptr), tail(nullptr), routeColor(color) {}
TouristPointList::TouristPointList() : name("No name"), head(nullptr), tail(nullptr), routeColor(sf::Color::Red) {}
TouristPointList::~TouristPointList(){}

void TouristPointList::addPoint(const sf::Vector2f& pos, const std::string pointName, bool& isNewPointAdded)
{
    TouristPointNode* point = new TouristPointNode(pos, pointName, routeColor);

    if (!head)
    {
        head = point;
    }
    else
    {
        TouristPointNode* auxiliar = head;

        while (auxiliar->getNext() != NULL)
        {
            auxiliar = auxiliar->getNext();
        }
        auxiliar->setNext(point);
        point->setPrev(auxiliar);
    }
    isNewPointAdded = 1;
}

void TouristPointList::drawRoute(sf::RenderWindow& window)
{

    TouristPointNode* current = head;

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

