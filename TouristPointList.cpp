#include "TouristPointList.h"

TouristPointList::TouristPointList(const std::string routeName, const sf::Color color, const sf::Font fontRef) : name(routeName), head(nullptr), tail(nullptr), routeColor(color) {}
TouristPointList::TouristPointList() : name("No name"), head(nullptr), tail(nullptr), routeColor(sf::Color::Red) {}
TouristPointList::~TouristPointList() {}

void TouristPointList::addPoint(const sf::Vector2f& pos, const std::string pointName)
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

}
/*

float getLinearInterpolationValue(float startValue, float endValue, float ratio)
{
    return startValue + (endValue - startValue) * ratio;
}

sf::Vector2f getLinearInterpolationPoint(sf::Vector2f startPoint, sf::Vector2f endPoint, float ratio)
{
    sf::Vector2f point(getLinearInterpolationValue(startPoint.x, endPoint.x, ratio), getLinearInterpolationValue(startPoint.y, endPoint.y, ratio));
    return point;
}
sf::Vector2f getCuadraticInterpolationPoint(sf::Vector2f startPoint, sf::Vector2f endPoint, float ratio)
{
    sf::Vector2f middlePoint((startPoint.x + endPoint.x) / 2 + 50, (startPoint.y + endPoint.y) / 2 + 50);
    return getLinearInterpolationPoint(getLinearInterpolationPoint(startPoint, middlePoint, (float)ratio / 100), getLinearInterpolationPoint(middlePoint, endPoint, (float)ratio / 100), (float)ratio / 100);
}

*/

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

            /*float dx = current->getPosition().x - current->getNext()->getPosition().x;
            float dy = current->getPosition().y - current->getNext()->getPosition().y;
            sf::RectangleShape line(sf::Vector2f(sqrt((dx * dx) + (dy * dy)), 2.0f));
            float rotation = ((atan2(dy, dx) * 180.f) / 3.14159f) - 180;
            line.setPosition(current->getPosition());
            line.setRotation(rotation);
            line.setFillColor(sf::Color::White);*/


            window.draw(&line[0], 100, sf::LineStrip);

        }
        current->draw(window);
        current = current->getNext();
    }
}