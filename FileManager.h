#pragma once
#include "TouristRouteManager.h"
	
class FileManager
{
	std::string saveFile;
	std::string maps[2];
	std::string loadingScreens[2];
	std::string fonts[3];
	std::string songs[4];

	int currentMap;
	int currentLoading;
	int currentFont;
	int currentSong;

public:

	FileManager();
	~FileManager();
	/*
	void setNextMap();
	void setNextLoading();

	void setNextMap();
	void setPrevMap();
	void setPrevLoading();
	void setNextLoading();

	*/

	void saveToFile(TouristRouteManager& manager);
	void loadFromFile(TouristRouteManager &manager);
};