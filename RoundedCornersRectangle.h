#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

sf::RenderTexture* getRoundedCornerRectangle(const sf::Color fillColor);

float getLinearInterpolationValue(float startValue, float endValue, float ratio);
sf::Vector2f getLinearInterpolationPoint(sf::Vector2f startPoint, sf::Vector2f endPoint, float ratio);
sf::Vector2f getCuadraticInterpolationPoint(sf::Vector2f startPoint, sf::Vector2f endPoint, float ratio);
