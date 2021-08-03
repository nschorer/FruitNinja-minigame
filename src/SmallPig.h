#ifndef SMALL_PIG_H
#define SMALL_PIG_H

#include "Pig_Base.h"

class SmallPig : public Pig_Base
{
public:

	SmallPig(float x, float y, PhysicsWorld* pWorld);
	virtual ~SmallPig() = default;

	void DestroyJoint();

	b2Joint* pJoint;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[2];
	static float maxHealth;
};


#endif