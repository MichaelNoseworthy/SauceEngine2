/*##############################################################################
#                                                                              #
# Copyright 2018 Sauce Pig All Rights Reserved.                                #
# Developed by Boris Merlo, Michael Noseworthy and Peter Tu                    #
#                                                                              #
##############################################################################*/
#include <SFML\Graphics.hpp>
#include "Components/GameObject.h"

class Animation
{
public:
	Animation(sf::Texture* texture, sf::Vector2u imageCount, float switchTime);
	~Animation();
	
	void Update(int row, float deltaTime);


	//variables
	sf::IntRect uvRect;
private: 
	//functions
	
	//variables
	sf::Vector2u imageCount;
	sf::Vector2u currentImage;

	float totalTime;
	float switchTime;
};

