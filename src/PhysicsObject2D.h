#ifndef PHYSICS_OBJECT_2D_H
#define PHYSICS_OBJECT_2D_H

#include "GameObject2D.h"
//#include "Box2D.h"
#include "Box2DWrapper.h"
#include "PhysicsMan.h"

class Blast;

class RedBird;

class Block_Base;
class Pig_Base;

class BigPig;
class MediumPig;
class SmallPig;

class Floor;
class WoodPlatform;

class PhysicsObject2D : public GameObject2D
{
public:

public:
	PhysicsObject2D() = delete;
	virtual ~PhysicsObject2D();
	PhysicsObject2D(const PhysicsObject2D&) = delete;
	PhysicsObject2D& operator=(const PhysicsObject2D&) = delete;

	PhysicsObject2D(GameObjectName::Name name, GraphicsObject_Sprite* pSprite, PhysicsWorld* pWorld, BodyType bodyType, PhysicsFixture* pFixture);

	void AddFixture(PhysicsFixture* pFixture);

	void SetPhysicsActive(bool active);

	void ApplyForce(Vect2D& force);
	void ApplyForceToPoint(Vect2D& force, Vect2D& point);

	void ApplyImpulse(Vect2D& impulse);
	void ApplyImpulseToPoint(Vect2D& impulse, Vect2D& point);

	void SetAngle(float angle);
	void SetPosition(float x, float y);

	void SetCollisionFlags(unsigned int categoryBits, unsigned int maskBits);

	PhysicsBody* GetPhysicsBody();

	bool IgnoresRaycast();

protected:
	PhysicsBody* pPhysicsBody;

	bool ignoreRaycast;

public:

	virtual void CollideAccept(PhysicsObject2D&, b2Contact*, const b2ContactImpulse*) {};
	virtual void CollideVisit(Blast&, b2Contact*, const b2ContactImpulse*) { DebugMsg::out("GameObject2D hit Blast\n"); };
	virtual void CollideVisit(Floor&, b2Contact*, const b2ContactImpulse*) {  };

	virtual void CollideVisit(RedBird&, b2Contact*, const b2ContactImpulse*) { DebugMsg::out("GameObject2D hit RedBird\n"); };

	virtual void CollideVisit(Block_Base&, b2Contact*, const b2ContactImpulse*) { DebugMsg::out("GameObject2D hit Block_Base\n"); };
	virtual void CollideVisit(Pig_Base&, b2Contact*, const b2ContactImpulse*) { DebugMsg::out("GameObject2D hit Pig_Base\n"); };

	virtual void CollideVisit(BigPig&, b2Contact*, const b2ContactImpulse*) { DebugMsg::out("GameObject2D hit StoneRect\n"); };
	virtual void CollideVisit(MediumPig&, b2Contact*, const b2ContactImpulse*) { DebugMsg::out("GameObject2D hit StoneRect\n"); };
	virtual void CollideVisit(SmallPig&, b2Contact*, const b2ContactImpulse*) { DebugMsg::out("GameObject2D hit StoneRect\n"); };

	virtual void CollideVisit(WoodPlatform&, b2Contact*, const b2ContactImpulse*) { DebugMsg::out("GameObject2D hit WoodPlatform\n"); };
};

#endif