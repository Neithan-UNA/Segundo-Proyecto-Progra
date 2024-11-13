#include "TouristPointNode.h"


TouristPointNode::TouristPointNode(const sf::Vector2f pos, const std::string pointName, const sf::Color pointColor) : position(pos), name(pointName), color(pointColor), next(nullptr), prev(nullptr)
{
    shape.setRadius(7.f);
    shape.setPosition(pos);
    shape.setFillColor(color);
    shape.setOrigin(5.f, 5.f);
}

TouristPointNode::~TouristPointNode() {}

TouristPointNode* TouristPointNode::getNext()
{
    return next;
}

sf::Color TouristPointNode::getColor()
{
    return color;
}

std::string TouristPointNode::getName()
{
    return name;
}

void TouristPointNode::setNext(TouristPointNode* touristP)
{
    next = touristP;
}

void TouristPointNode::setPrev(TouristPointNode* touristP)
{
    prev = touristP;
}

void TouristPointNode::draw(sf::RenderWindow& window)
{
    sf::Text pointText;
    sf::Font font;
    font.loadFromFile("Resources/ComicSans.ttf");
    pointText.setFont(font);
    pointText.setCharacterSize(24);
    pointText.setFillColor(sf::Color::White);
    pointText.setPosition(position);
    pointText.setString(name);

    window.draw(pointText);
    window.draw(shape);
}

sf::Vector2f TouristPointNode::getPosition()
{
    return position;
}

void TouristPointNode::setColor(const sf::Color& newColor)
{
        color = newColor;
        shape.setFillColor(color);
}

