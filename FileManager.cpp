#include "FileManager.h"

FileManager::FileManager() : currentMap(0), currentLoading(0), currentFont(0), currentSong(0)
{

	saveFile = "SaveFiles/routes.txt";

	maps[0] = "Resources/Botw_Map.png";
	maps[1] = "Resources/Botw_Map.png";

	loadingScreens[0] = "Resources/Botw_Map.png";
	loadingScreens[1] = "Resources/Botw_Map.png";

	fonts[0] = "Resources/Botw_Map.png";
	fonts[1] = "Resources/Botw_Map.png";
	fonts[2] = "Resources/Botw_Map.png";


	songs[0] = "Resources/Botw_Map.png";
	songs[1] = "Resources/Botw_Map.png";
	songs[2] = "Resources/Botw_Map.png";
	songs[3] = "Resources/Botw_Map.png";
}

FileManager::~FileManager()
{

}

void FileManager::saveToFile(TouristRouteManager& manager)
{

	std::ofstream file(saveFile);

	if(file)
	{
		TouristPointList *temp = manager.getHead();

		while(temp)
		{
			file << "Ruta\n";
			TouristPointNode *actual = temp->getHead();
			while(actual)
			{
				file << actual->getPosition().x << "," << actual->getPosition().y << ",";
				file << (int)actual->getColor().r << "," << (int)actual->getColor().g << "," << (int)actual->getColor().b << ",";
				file << actual->getName() << '\n';
				actual = actual->getNext();
			}

			temp = temp->getNext();
		}
	}

	file.close();
}
void FileManager::loadFromFile(TouristRouteManager& manager) 
{
	std::ifstream file(saveFile);
	
	if (!file.is_open())
	{
		return;
	}


	std::string line;
	while (std::getline(file, line)) 
	{
		if (line == "Ruta") 
		{
			manager.addRoute();

		}
		else
		{
			int pos = 0;
			std::string elements[6];

			for (int i = 0; i < 5; i++)
			{
				pos = line.find(',');
				if (pos == std::string::npos)
				{
					return;
				}

				elements[i] = line.substr(0, pos);
				line.erase(0, pos + 1);
			}

			elements[5] = line;

			
				sf::Vector2f position(std::stof(elements[0]), std::stof(elements[1]));
				sf::Color color(sf::Uint8(std::stoi(elements[2])), sf::Uint8(std::stoi(elements[3])), sf::Uint8(std::stoi(elements[4])));
				std::string name = elements[5];

				manager.addPoint(position, name, color);
			
		}
	
		
	}

	file.close();
}
/*
void FileManager::loadFromFile(TouristRouteManager& manager)
{
	std::ifstream file(saveFile);

	if (!file) {
		
	}
	else
	{
		std::string line;

		while(std::getline(file,line))
		{
			if(line.find("Ruta"))
			{
				manager.addRoute();
			}
			else
			{
				sf::Color color;
				int red = 0, green = 0, blue = 0;
				std::string name;
				sf::Vector2f position;

				int pos = line.find(",");
				position.x = stoi(line.substr(0, pos));
				line.erase(0,pos+1);

				pos = line.find(",");
				position.y = stoi(line.substr(0, pos));
				line.erase(0, pos + 1);

				pos = line.find(",");
				red = stoi(line.substr(0, pos));
				line.erase(0, pos + 1);

				pos = line.find(",");
				green = stoi(line.substr(0, pos));
				line.erase(0, pos + 1);

				pos = line.find(",");
				blue = stoi(line.substr(0, pos));
				line.erase(0, pos + 1);

				color = sf::Color(red, green, blue);
				name = line;

				manager.addPoint(position, name, color);

			}
		}
	}

	file.close();
}*/