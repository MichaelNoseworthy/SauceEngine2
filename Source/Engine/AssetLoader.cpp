/*##############################################################################
#																			   #
# Copyright 2018 Sauce Pig All Rights Reserved.					               #
# Developed by Boris Merlo, Michael Noseworthy and Peter Tu                    #
#                                                                              #
##############################################################################*/

#include "AssetLoader.h"

bool exitProgram = false;


//This code has been deappreciated but still can be used for music.  We now use AssetManager for most stuff

void loadAssetFromFile(sf::Texture& asset, std::string FileLocation1, std::string FileLocation2)
{

	if(!Collision::CreateTextureAndBitmask(asset, FileLocation1))
		if (!Collision::CreateTextureAndBitmask(asset, FileLocation2))
		{
			std::cerr << "Error loading " << FileLocation2 << std::endl;
			if (exitProgram)
			exit(-1);
		}
}

void loadAssetFromFile(sf::Font& asset, std::string FileLocation1, std::string FileLocation2)
{
	if (!asset.loadFromFile(FileLocation1))
		if (!asset.loadFromFile(FileLocation2))
		{
			std::cerr << "Error loading " << FileLocation2 << std::endl;
			if (exitProgram)
			exit(-1);
		}
}
void loadAssetFromFile(sf::Music& asset, std::string FileLocation1, std::string FileLocation2)
{
	if (!asset.openFromFile(FileLocation1))
		if (!asset.openFromFile(FileLocation2))
		{
			std::cerr << "Error loading " << FileLocation2 << std::endl;
			if (exitProgram)
			exit(-1);
		}
}

void loadAssetFromFile(sf::SoundBuffer& asset, std::string FileLocation1, std::string FileLocation2)
{
	if (!asset.loadFromFile(FileLocation1))
		if (!asset.loadFromFile(FileLocation2))
		{
			std::cerr << "Error loading " << FileLocation2 << std::endl;
			if (exitProgram)
			exit(-1);
		}
}