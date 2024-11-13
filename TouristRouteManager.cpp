#include "TouristRouteManager.h"

TouristRouteManager::TouristRouteManager() : currentColor(sf::Color::Red), head(nullptr), currentRoute(nullptr)
{
}

TouristRouteManager::~TouristRouteManager() {}

void TouristRouteManager::addPoint(const sf::Vector2f& pos, const std::string pointName)
{
	
	if(!head)
	{
		TouristPointList *newList = new TouristPointList;
		head = newList;
		currentRoute = newList;
	}

	currentRoute->addPoint(pos, pointName);
}

void TouristRouteManager::drawRoutes(sf::RenderWindow &window)
{
	TouristPointList* temp = head;
	if(temp)
	{
		currentRoute->drawRoute(window);
		//temp = temp->getNext();
	}
}