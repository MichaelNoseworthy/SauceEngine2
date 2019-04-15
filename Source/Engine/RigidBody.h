#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

struct AABB
{
	sf::Vector2f bLeft;
	sf::Vector2f tRight;
};

class RigidBody
{
public:
	RigidBody();
	RigidBody(const sf::Sprite & Object);
	~RigidBody();

	float mass = 1.f;                             // Mass of the RigidBody
	float bounciness = 1;                        // The bounciness factor (value between 0 and 1, 0 being no bounce, and 1 being super bouncy!)
	bool obeysGravity = true;                    // Whether or not this body obeys gravity
	sf::Vector2f gravity = sf::Vector2f(0, -9.8f);     // The gravity vector applied to this body

	sf::Vector2f currentVelocity;                     // The current velocity the body is moving at
	sf::Vector2f maxVelocity = sf::Vector2f(10.f, 10.f); // The maximum allowed velocity for this object
	AABB aabb;
	bool grounded;

	void AddForce(sf::Vector2f force);

	void Stop();
	bool IsGrounded();

	void SetAABB(const sf::Sprite&);
	void Integrate(float dT);

private:
	sf::Vector2f totalForces;
	sf::RectangleShape body;
	sf::Sprite texture;
	//PhysicsEngine engine;


};



