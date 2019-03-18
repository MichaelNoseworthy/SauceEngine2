/*##############################################################################
#																			   #
# Copyright 2018 Sauce Pig All Rights Reserved.					               #
# Developed by Boris Merlo, Michael Noseworthy and Peter Tu                    #
#                                                                              #
##############################################################################*/

#include "Platform.h"



Platform::Platform(sf::Texture* texture, sf::Vector2f _size, sf::Vector2f position)
{
	body.setSize(_size);
	body.setOrigin(_size / 2.0f);
	body.setTexture(texture);
	body.setPosition(position);
}

Platform::~Platform()
{
	//dtor
}

void Platform::Draw(sf::RenderWindow& window)
{
	window.draw(body);
}
