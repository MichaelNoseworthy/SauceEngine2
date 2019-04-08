/*##############################################################################
#																			   #
# Copyright 2018 Sauce Pig All Rights Reserved.					               #
# Developed by Boris Merlo, Michael Noseworthy and Peter Tu                    #
#                                                                              #
##############################################################################*/

#include "Projectile.h"


Projectile::Projectile(sf::Texture* Texture, sf::Vector2u imageCount, float switchTime, float speed)
{

	switchTime = 0.5;
	this->speed = speed;	
	row = 0;	
	sf::Vector2u TextureSize = Texture->getSize();
	TextureSize.x / 3; //not being used
	body.setSize(sf::Vector2f(4.0f, 5.0f));
	body.setOrigin(body.getSize() / 2.0f);	
	body.setTexture(Texture);
}


Projectile::~Projectile()
{
}

void Projectile::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);

	velocity.x += speed * deltaTime;

	if (useGravity == true)
		velocity.y += 98.1f * deltaTime;
	
	body.move(velocity * deltaTime);
}

void Projectile::Draw(sf::RenderWindow & window)
{
	window.draw(body);
}
/*
void Projectile::OnCollision(sf::Vector2f direction)
{
	if (direction.x < 0.0f)
	{
		//Collision on the left
		velocity.x = 0.0f;
	}
	else if (direction.x > 0.0f)
	{
		//Collision on the right
		velocity.x = 0.0f;
	}
	if (direction.y < 0.0f)
	{
		//Collision under
		velocity.y = 0.0f;		
	}
	else if (direction.y > 0.0f)
	{
		velocity.y = 0.0f;
	}
}*/

void Projectile::SetPos(sf::Vector2f newPos)
{
	body.setPosition(newPos);
}
