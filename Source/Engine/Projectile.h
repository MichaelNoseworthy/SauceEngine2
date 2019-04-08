/*##############################################################################
#																			   #
# Copyright 2018 Sauce Pig All Rights Reserved.					               #
# Developed by Boris Merlo, Michael Noseworthy and Peter Tu                    #
#                                                                              #
##############################################################################*/

#include <SFML\Graphics.hpp>
#include "Components/GameObject.h"
#include "Collider.h"

#pragma once
class Projectile
{
public:
	Projectile(sf::Texture* Texture, sf::Vector2u imageCount, float switchTime, float speed);
	~Projectile();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& window);
	//void OnCollision(sf::Vector2f direction);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	void SetPos(sf::Vector2f newPos);
	Collider GetCollider() { return Collider(body); }

private:
	sf::RectangleShape body;
	//Animation animation;
	unsigned int row;
	float speed;
	
	sf::Vector2f velocity;
	bool useGravity = false;
};

