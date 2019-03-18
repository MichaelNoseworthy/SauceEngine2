#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "AssetManager.h"

class SceneManager
{
public:
	virtual int Run(sf::RenderWindow &App) = 0;
};
