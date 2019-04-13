/*##############################################################################
#																			   #
# Copyright 2018 Sauce Pig All Rights Reserved.					               #
# Developed by Boris Merlo, Michael Noseworthy and Peter Tu                    #
#                                                                              #
##############################################################################*/
#pragma once
#include "BaseComponent.h"
#include <SFML\Graphics.hpp>

class TransformComponent
{
public:
	TransformComponent();

	void Awake();
	void Start();
	void Update(float deltaTime);
	void FixedUpdate(float deltaTime); 
	//void Draw(sf::RenderWindow& window);

	//sf::RectangleShape body;
	sf::Vector2f velocity;
	float speed;

private:

};

