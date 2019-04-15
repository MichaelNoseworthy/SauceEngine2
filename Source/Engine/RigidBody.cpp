#include "RigidBody.h"


RigidBody::RigidBody()
{
}

RigidBody::RigidBody(const sf::Sprite& Object)
{
	SetAABB(Object);
	//engine = GameObject.FindWithTag("PhysicsEngine").GetComponent<PhysicsEngine>();

	//engine.AddRigidBody(this);
}


RigidBody::~RigidBody()
{
}

void RigidBody::AddForce(sf::Vector2f force)
{
	totalForces += force;
}

void RigidBody::Stop()
{
	currentVelocity = sf::Vector2f(0, .0f); ;
	totalForces = sf::Vector2f(0, 0.f);
}

bool RigidBody::IsGrounded()
{
	//grounded = engine.IsGrounded(this);
	return grounded;
}

sf::Vector2f GetSpriteSize(const sf::Sprite& Object)
{
	sf::IntRect OriginalSize = Object.getTextureRect();
	sf::Vector2f Scale = Object.getScale();
	return sf::Vector2f(OriginalSize.width*Scale.x, OriginalSize.height*Scale.y);
}

sf::Vector2f GetSpriteCenter(const sf::Sprite& Object)
{
	sf::FloatRect AABB = Object.getGlobalBounds();
	return sf::Vector2f(AABB.left + AABB.width / 2.f, AABB.top + AABB.height / 2.f);
}

void RigidBody::SetAABB(const sf::Sprite& Object)
{
	sf::Vector2f size = GetSpriteCenter(Object);
	sf::Vector2f center = GetSpriteCenter(Object);
	//Renderer renderer = GetComponent<Renderer>();
	/*
	if (renderer)
	{
		bound = renderer.bounds;
	}*/

	aabb.bLeft = sf::Vector2f(center.x - size.x, center.y - size.y);
	aabb.tRight = sf::Vector2f(center.x + size.x, center.y + size.y);
}

void RigidBody::Integrate(float dT)
{
	sf::Vector2f acceleration = sf::Vector2f();

	if (obeysGravity && !IsGrounded()) {
		AddForce(gravity);
		//acceleration = gravity;
	}
	else {
		if (abs(currentVelocity.y) < 0.05f)
			currentVelocity.y = 0;
	}
}
