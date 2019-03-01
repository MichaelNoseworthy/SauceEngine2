#pragma once
#include <SFML/Graphics.hpp>

class SceneManager
{
public:
	virtual int Run(sf::RenderWindow &App) = 0;
};
