#pragma once

#include <SFML\Graphics.hpp>
#include "Components/GameObject.h"
#include "Components/TransformComponent.h"
//#include "Collider.h"
#include "Animation.h"
#include "Projectile.h"

class Player : public GameObject, public TransformComponent
{
public:
	//Player();
	Player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, float jumpHeight);
	//Player(sf::Texture* Texture, sf::Vector2u imageCoun, float speed, float switchTime, float jumpHeight);
	~Player();
	TransformComponent transComp;

	void Update(float deltaTime, sf::Texture* texture);
	void Draw(sf::RenderWindow& window);
	void OnCollision(sf::Vector2f direction);
	/*sf::Vector2f GetPosition() { return transComp.body.getPosition(); }
	Collider GetCollider() { return Collider(transComp.body); }*/
private:
	//sf::RectangleShape body;
	Animation animation;
	unsigned int row;
	
	bool faceRight;

};

