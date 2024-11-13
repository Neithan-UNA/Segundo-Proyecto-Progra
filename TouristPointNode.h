#pragma once
#include "RoundedCornersRectangle.h"

class TouristPointNode
{
    sf::Color color;
    std::string name;
    sf::Vector2f position;
    sf::CircleShape shape;
    TouristPointNode* next;
    TouristPointNode* prev;

public:

    TouristPointNode(const sf::Vector2f pos, const std::string pointName, const sf::Color pointColor);
    ~TouristPointNode();
    TouristPointNode* getNext();
    void setNext(TouristPointNode* touristP);
    void setPrev(TouristPointNode* touristP);
    void draw(sf::RenderWindow& window);
    sf::Vector2f getPosition();
    void setColor(const sf::Color& newColor);
    sf::Color getColor();
    std::string getName();

};
