#pragma once
#include "TouristPointList.h"

class TouristRouteManager
{

    TouristPointList *currentRoute;
    TouristPointList *head;

    sf::Color currentColor;

public:

    TouristRouteManager();
    ~TouristRouteManager();
    void addPoint(const sf::Vector2f& pos, const std::string pointName);
    void drawRoutes(sf::RenderWindow &window);
    //void pushToNextRoute();
};