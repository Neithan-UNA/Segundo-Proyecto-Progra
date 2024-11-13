#include "RoundedCornersRectangle.h"


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
    sf::Vector2f middlePoint((startPoint.x + endPoint.x) / 2 + 100, (startPoint.y + endPoint.y) / 2 + 100);
    return getLinearInterpolationPoint(getLinearInterpolationPoint(startPoint, middlePoint, (float)ratio / 100), getLinearInterpolationPoint(middlePoint, endPoint, (float)ratio / 100), (float)ratio / 100);
}

sf::RenderTexture* getRoundedCornerRectangle(const sf::Color fillColor)
{
    sf::RenderTexture* renderTexture = new sf::RenderTexture();
    if (!renderTexture->create(600, 600))
        return nullptr;

    const float radius = 30.0f;
    const float width = 150.0f;
    const float height = 200.0f;

    sf::RectangleShape mainRectangle(sf::Vector2f(width - 2 * radius, height - 2 * radius));
    mainRectangle.setFillColor(fillColor);
    mainRectangle.setPosition(radius, radius);

    sf::RectangleShape leftRectangle(sf::Vector2f(radius, height - 2 * radius));
    sf::RectangleShape rightRectangle(sf::Vector2f(radius, height - 2 * radius));
    sf::RectangleShape topRectangle(sf::Vector2f(width - 2 * radius, radius));
    sf::RectangleShape bottomRectangle(sf::Vector2f(width - 2 * radius, radius));

    leftRectangle.setFillColor(fillColor);
    rightRectangle.setFillColor(fillColor);
    topRectangle.setFillColor(fillColor);
    bottomRectangle.setFillColor(fillColor);

    leftRectangle.setPosition(0, radius);
    rightRectangle.setPosition(width - radius, radius);
    topRectangle.setPosition(radius, 0);
    bottomRectangle.setPosition(radius, height - radius);

    sf::CircleShape topLeftCorner(radius);
    sf::CircleShape topRightCorner(radius);
    sf::CircleShape bottomLeftCorner(radius);
    sf::CircleShape bottomRightCorner(radius);

    topLeftCorner.setFillColor(fillColor);
    topRightCorner.setFillColor(fillColor);
    bottomLeftCorner.setFillColor(fillColor);
    bottomRightCorner.setFillColor(fillColor);

    topLeftCorner.setPosition(0, 0);
    topRightCorner.setPosition(width - 2 * radius, 0);
    bottomLeftCorner.setPosition(0, height - 2 * radius);
    bottomRightCorner.setPosition(width - 2 * radius, height - 2 * radius);

    renderTexture->clear(sf::Color::Transparent);

    renderTexture->draw(mainRectangle);
    renderTexture->draw(leftRectangle);
    renderTexture->draw(rightRectangle);
    renderTexture->draw(topRectangle);
    renderTexture->draw(bottomRectangle);
    renderTexture->draw(topLeftCorner);
    renderTexture->draw(topRightCorner);
    renderTexture->draw(bottomLeftCorner);
    renderTexture->draw(bottomRightCorner);

    renderTexture->display();

    return renderTexture;
}