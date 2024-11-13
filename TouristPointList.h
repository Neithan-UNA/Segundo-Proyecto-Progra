#pragma once
#include "TouristPointNode.h"

class TouristPointList
{
    std::string name;
    TouristPointNode* head;
    TouristPointNode* tail;
    sf::Color routeColor;

    TouristPointNode* Next;
    TouristPointNode* Prev;
public:

    TouristPointList(const std::string routeName, const sf::Color color, const sf::Font fontRef);
    TouristPointList();
    ~TouristPointList();
    void addPoint(const sf::Vector2f& pos, const std::string pointName);
    void drawRoute(sf::RenderWindow& window);
};

