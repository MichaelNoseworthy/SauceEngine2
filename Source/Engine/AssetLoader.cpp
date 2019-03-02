#include "AssetLoader.h"


void loadAssetFromFile(sf::Texture& asset, std::string FileLocation1, std::string FileLocation2)
{
	if(!asset.loadFromFile(FileLocation1))
		if (!asset.loadFromFile(FileLocation2))
		{
			std::cerr << "Error loading " << FileLocation2 << std::endl;
			exit(-1);
		}
}

void loadAssetFromFile(sf::Font& asset, std::string FileLocation1, std::string FileLocation2)
{
	if (!asset.loadFromFile(FileLocation1))
		if (!asset.loadFromFile(FileLocation2))
		{
			std::cerr << "Error loading " << FileLocation2 << std::endl;
			exit(-1);
		}
}
void loadAssetFromFile(sf::Music& asset, std::string FileLocation1, std::string FileLocation2)
{
	if (!asset.openFromFile(FileLocation1))
		if (!asset.openFromFile(FileLocation2))
		{
			std::cerr << "Error loading " << FileLocation2 << std::endl;
			exit(-1);
		}
}

void loadAssetFromFile(sf::SoundBuffer& asset, std::string FileLocation1, std::string FileLocation2)
{
	if (!asset.loadFromFile(FileLocation1))
		if (!asset.loadFromFile(FileLocation2))
		{
			std::cerr << "Error loading " << FileLocation2 << std::endl;
			exit(-1);
		}
}