#pragma once
#include "TouristRouteManager.h"
	
class FileManager
{
	std::string maps[2];
	int currentMap;
	std::string loadingScreens[2];
	int currentLoading;
	std::string fonts[3];
	int currentFont;
	std::string songs[4];
	int currentSong;

public:

	FileManager();
	/*
	void setNextMap();
	void setNextLoading();

	void setNextMap();
	void setPrevMap();
	void setPrevLoading();
	void setNextLoading();

	void saveToFile;
	void loadFromFile;
	*/
};