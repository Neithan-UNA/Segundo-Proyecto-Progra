#pragma once
#include <SFML/Graphics.hpp>

sf::RenderTexture* getRoundedCornerRectangle();


float getLinearInterpolationValue(float startValue, float endValue, float ratio);
sf::Vector2f getLinearInterpolationPoint(sf::Vector2f startPoint, sf::Vector2f endPoint, float ratio);
sf::Vector2f getCuadraticInterpolationPoint(sf::Vector2f startPoint, sf::Vector2f endPoint, float ratio);
