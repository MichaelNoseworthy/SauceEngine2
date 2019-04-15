/*##############################################################################
#																			   #
# Copyright 2018 Sauce Pig All Rights Reserved.					               #
# Developed by Boris Merlo, Michael Noseworthy and Peter Tu                    #
#                                                                              #
##############################################################################*/
#pragma once
#include "BaseComponent.h"
#include <SFML\Graphics.hpp>
#include "../Collider.h"

class TransformComponent
{
public:
	TransformComponent();/*: position(), rotation(), scale(1, 1) {}*/

	void Awake();
	void Start();
	void Update(float deltaTime);
	void FixedUpdate(); 

	sf::Vector2f position;
	sf::Vector2f rotation;
	sf::Vector2f scale;

	sf::Transform ObjectPos;


	void OnCollision(sf::Vector2f direction);
	sf::RectangleShape body;
	sf::Vector2f GetPosition() { return body.getPosition(); }
	Collider GetCollider() { return Collider(body); }

	float speed;
	float jumpHeight;
	//void Move(sf::Vector2f position, sf::Vector2f rotation, sf::Vector2f scale);
	bool changing;
	bool canJump;
private:
	bool useGravity = true;
};

