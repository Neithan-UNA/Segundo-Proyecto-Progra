#include "TouristPointList.h"

TouristPointList::TouristPointList(const std::string routeName, const sf::Color color, const sf::Font fontRef) : name(routeName), head(nullptr), tail(nullptr), next(nullptr), prev(nullptr), routeColor(color) {}
TouristPointList::TouristPointList() : name("No name"), head(nullptr), tail(nullptr), next(nullptr), prev(nullptr), routeColor(sf::Color::Red) {}
TouristPointList::~TouristPointList() {}
TouristPointList *TouristPointList::getNext() 
{
    return next;
}

TouristPointNode *TouristPointList::getHead()
{
    return head;
}
void TouristPointList::addPoint(const sf::Vector2f& pos, const std::string pointName, sf::Color color)
{
    TouristPointNode* point = new TouristPointNode(pos, pointName, color);
    if (!head)
    {
        head = point;
        tail = point;
    }
    else
    {
        tail->setNext(point);
        point->setPrev(tail);
        tail = point;
        
    }

}
void TouristPointList::setNext(TouristPointList* list)
{
    next = list;
}
void TouristPointList::setPrev(TouristPointList* list)
{
    prev = list;
}

void TouristPointList::drawRoute(sf::RenderWindow& window)
{
    TouristPointNode* current = head;

    while (current)
    {

        if (current->getNext())
        {
            sf::VertexArray line(sf::Points, 100);

            for(int i = 0; i < 100; i++)
            {
                line[i] = getCuadraticInterpolationPoint(current->getPosition(), current->getNext()->getPosition(), i);
            }

            window.draw(&line[0], 100, sf::LineStrip);

        }
        current->draw(window);
        current = current->getNext();
    }
}