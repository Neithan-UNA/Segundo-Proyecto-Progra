#pragma once
#include "TouristPointList.h"

class TouristRouteManager
{

    TouristPointList currentRoute;
    sf::Color currentColor;
    bool lastIsDone;

public:

    TouristRouteManager();
    ~TouristRouteManager();

};