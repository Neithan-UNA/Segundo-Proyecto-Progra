#include "TouristRouteManager.h"

TouristRouteManager::TouristRouteManager() : currentColor(sf::Color::Red), head(nullptr), currentRoute(nullptr)
{
}

TouristRouteManager::~TouristRouteManager() {}

void TouristRouteManager::addPoint(const sf::Vector2f& pos, const std::string pointName, sf::Color color)
{
	if(!head)
	{
		TouristPointList *newList = new TouristPointList;
		head = newList;
		currentRoute = newList;
	}

	currentRoute->addPoint(pos, pointName, color);
}

TouristPointList *TouristRouteManager::getHead()
{
	return head;
}

void TouristRouteManager::addRoute()
{
	TouristPointList* newList = new TouristPointList;

	if (!head)
	{
		head = newList;
		currentRoute = newList;
	}
	else
	{
		TouristPointList* temp = head;

		while(temp->getNext())
		{
			temp->getNext();
		}
		temp->setNext(newList);
		newList->setPrev(temp);
	}
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