#include "TouristRouteManager.h"

TouristRouteManager::TouristRouteManager() : currentColor(sf::Color::Red), lastIsDone(true)
{
}

TouristRouteManager::~TouristRouteManager() {}

void TouristRouteManager::addPoint(const sf::Vector2f& pos, const std::string pointName)
{
	currentRoute.addPoint(pos, pointName);
}

void TouristRouteManager::drawRoutes(sf::RenderWindow &window)
{
	currentRoute.drawRoute(window);
}