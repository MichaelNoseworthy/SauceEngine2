#pragma once
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <windows.h>
#include "Collision.h"

void loadAssetFromFile(sf::Texture& asset, std::string FileLocation1, std::string FileLocation2);
void loadAssetFromFile(sf::Font& asset, std::string FileLocation1, std::string FileLocation2); 
void loadAssetFromFile(sf::Music& asset, std::string FileLocation1, std::string FileLocation2);
void loadAssetFromFile(sf::SoundBuffer& asset, std::string FileLocation1, std::string FileLocation2);