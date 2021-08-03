#ifndef RED_BIRD_H
#define RED_BIRD_H

#include "PhysicsObject2D.h"

class Block_Base;

class Pig_Base;

class RedBird : public PhysicsObject2D
{
public:

	RedBird(float x, float y, PhysicsWorld* pWorld);

	virtual void CollideAccept(PhysicsObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };

	virtual void CollideVisit(Block_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse) override;

	virtual void CollideVisit(Pig_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse) override;


private:
	static PhysicsFixture fixture;
	static ImageName::Name image;
	static float width;
	static float height;

};


#endif
