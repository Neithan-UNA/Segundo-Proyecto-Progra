#pragma once
#include "TouristPointNode.h"

class TouristPointList
{
    std::string name;
    TouristPointNode* head;
    TouristPointNode* tail;
    sf::Color routeColor;

    TouristPointList* next;
    TouristPointList* prev;
public:

    TouristPointList(const std::string routeName, const sf::Color color, const sf::Font fontRef);
    TouristPointList();
    ~TouristPointList();
    void addPoint(const sf::Vector2f& pos, const std::string pointName, sf::Color color);
    void drawRoute(sf::RenderWindow& window);
    TouristPointList *getNext();
    void setNext(TouristPointList* list);
    void setPrev(TouristPointList* list);
    TouristPointNode* getHead();
};

