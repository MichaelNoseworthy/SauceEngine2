#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include "RigidBody.h"
#include <map> 
#include <list>
#include <iterator>

struct CollisionPair {
	RigidBody rigidBodyA;
	RigidBody rigidBodyB;
};

struct CollisionInfo {
	sf::Vector2f collisionNormal;
	float penetration;
};

class Physics
{
public:
	Physics();
	~Physics();

	void Update(float deltaTime);

	void AddRigidBody(RigidBody rigidBody);
	bool IsGrounded(RigidBody rigidBody);

private:
	float groundedTol = 0.1f;
	std::map<CollisionPair, CollisionInfo> collisions = std::map<CollisionPair, CollisionInfo>();
	std::list<RigidBody> rigidBodies = std::list<RigidBody>();

	void IntegrateBodies(float dT);
	void CheckCollisions();
	void ResolveCollisions();

};

