#include "Physics.h"

Physics::Physics()
{
}


Physics::~Physics()
{
}

void Physics::Update(float deltaTime)
{
	IntegrateBodies(deltaTime);
}

void Physics::AddRigidBody(RigidBody rigidBody)
{

	rigidBodies.push_back(rigidBody);
}

bool Physics::IsGrounded(RigidBody rigidBody)
{
	std::list<RigidBody>::iterator it;
	for (it = rigidBodies.begin(); it != rigidBodies.end(); ++it) {
		//if (it-> != rigidBody) {
		if (rigidBody.aabb.bLeft.x < it->aabb.tRight.x
			&& rigidBody.aabb.tRight.x > it->aabb.bLeft.x
			&& abs(rigidBody.aabb.bLeft.y - it->aabb.tRight.y) <= groundedTol) {
			if (abs(rigidBody.currentVelocity.y) < groundedTol)
				return true;
		}
		//}
	}
	return false;
}

void Physics::IntegrateBodies(float dT)
{
	std::list<RigidBody>::iterator it;
	for (it = rigidBodies.begin(); it != rigidBodies.end(); ++it) {
		it->Integrate(dT);
	}
}

void Physics::CheckCollisions()
{
	std::list<RigidBody>::iterator it;
	std::list<RigidBody>::iterator it2;

	for (it = rigidBodies.begin(); it != rigidBodies.end(); ++it) {
		for (it2 = rigidBodies.begin(); it2 != rigidBodies.end(); ++it2) {
			if (it != it2) {
				CollisionPair pair = CollisionPair();
				CollisionInfo colInfo = CollisionInfo();
				pair.rigidBodyA = *it;
				pair.rigidBodyB = *it2;

				//	sf::Vector2f distance = it2->transform.position - it->transform.position;

				sf::Vector2f halfSizeA = (it->aabb.tRight - it->aabb.bLeft) / 2.f;
				sf::Vector2f halfSizeB = (it2->aabb.tRight - it2->aabb.bLeft) / 2.f;

				//	sf::Vector2f gap = sf::Vector2f(abs(distance.x), abs(distance.y)) - (halfSizeA + halfSizeB);

					// Seperating Axis Theorem test
				/*	if (gap.x < 0 && gap.y < 0) {
						Debug.Log("Collided!!!");

						if (collisions.ContainsKey(pair)) {
							collisions.Remove(pair);
						}

						if (gap.x > gap.y) {
							if (distance.x > 0) {
								colInfo.collisionNormal = new Vector2(1, 0);
							}
							else {
								colInfo.collisionNormal = new Vector2(-1, 0);
							}
							colInfo.penetration = gap.x;
						}
						else {
							if (distance.y > 0) {
								colInfo.collisionNormal = new Vector2(0, 1);
							}
							else {
								// ... Update collision normal
								colInfo.collisionNormal = new Vector2(0, -1);
							}
							colInfo.penetration = gap.y;
						}
						collisions.Add(pair, colInfo);
					}
					else if (collisions.ContainsKey(pair)) {
						Debug.Log("removed");
						collisions.Remove(pair);
					}*/

			}
		}
	}
}

void ResolveCollisions() {
	/*
	for (auto const&[collisions.key, val] : collisions)
	{

	}*/
	/*
	foreach(CollisionPair pair in collisions.Keys) {
		float minBounce = Mathf.Min(pair.rigidBodyA.bounciness, pair.rigidBodyB.bounciness);
		float velAlongNormal = Vector2.Dot(pair.rigidBodyB.currentVelocity - pair.rigidBodyA.currentVelocity, collisions[pair].collisionNormal);
		if (velAlongNormal > 0) continue;

		float j = -(1 + minBounce) * velAlongNormal;

		float invMassA, invMassB;

		if (pair.rigidBodyA.mass == 0)
			invMassA = 0;
		else
			invMassA = 1 / pair.rigidBodyA.mass;

		if (pair.rigidBodyB.mass == 0)
			invMassB = 0;
		else
			invMassB = 1 / pair.rigidBodyB.mass;

		j /= invMassA + invMassB;

		Vector2 impulse = j * collisions[pair].collisionNormal;

		// ... update velocities
		pair.rigidBodyA.AddForce(-impulse / Time.deltaTime);
		pair.rigidBodyB.AddForce(impulse / Time.deltaTime);

		if (Mathf.Abs(collisions[pair].penetration) > 0.01f) {
			PositionalCorrection(pair);
		}
	}*/
}

