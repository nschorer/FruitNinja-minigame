#ifndef PHYSICS_BODY_H
#define PHYSICS_BODY_H

//#include "Box2D.h"
#include "Box2DWrapper.h"
#include "PixelToMeter.h"
#include "GameObject2D.h"
#include "PhysicsFixture.h"

class PhysicsWorld;

// these values map directly to b2BodyType
enum class BodyType
{
	Static,    // 0
	Kinematic, // 1
	Dynamic	   // 2
};


class PhysicsBody
{

public:
	PhysicsBody(GameObject2D* pGameObj, PhysicsWorld* pWorld, b2Body* pBody, PhysicsFixture* pFixture);
	~PhysicsBody();
	
	void DestroyBody(b2World* pB2World);

	void AddFixture(PhysicsFixture* pFixture);
	void AddFixture(PhysicsFixture* pFixture, float xOff, float yOff, float rotation);

	void SetActive(bool active);

	float GetAngle();

	void SetPosition(float x, float y);
	void SetAngle(float angle);

	void ApplyForce(Vect2D& force);
	void ApplyForceToPoint(Vect2D& force, Vect2D& point);

	void ApplyImpulse(Vect2D& impulse);
	void ApplyImpulseToPoint(Vect2D& impulse, Vect2D& point);

	void SetCollisionFlags(unsigned int categoryBits, unsigned int maskBits);

	PhysicsWorld* GetWorld();

	b2Body* GetB2Body();

private:
	GameObject2D* pGameObj;
	b2Body* pB2Body;
	PhysicsWorld* pWorld;

};

#endif