#pragma once
#include "TouristPointNode.h"

class TouristPointList
{

    std::string name;
    TouristPointNode* head;
    TouristPointNode* tail;
    sf::Color routeColor;

public:

    TouristPointList(const std::string routeName, const sf::Color color, const sf::Font fontRef);
    TouristPointList();
    ~TouristPointList();
    void addPoint(const sf::Vector2f& pos, const std::string pointName, bool& isNewPointAdded);
    void drawRoute(sf::RenderWindow& window);

};
