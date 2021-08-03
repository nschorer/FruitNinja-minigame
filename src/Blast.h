#ifndef BLAST_H
#define BLAST_H

#include "PhysicsObject2D.h"

class WoodPlatShort;

class Blast : public PhysicsObject2D
{
public:

	Blast(float x, float y, PhysicsWorld* pWorld);

	virtual void Update(float t) override;

	virtual void CollideAccept(PhysicsObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };
	//virtual void CollideVisit(WoodPlatShort& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse);

private:
	static PhysicsFixture fixture;
	static ImageName::Name image;
	static float width;
	static float height;

	int framecount;

};

#endif