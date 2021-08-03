#ifndef BIG_PIG_H
#define BIG_PIG_H

#include "Pig_Base.h"

class BigPig : public Pig_Base
{
public:

	BigPig(float x, float y, PhysicsWorld* pWorld);
	virtual ~BigPig() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[2];
	static float maxHealth;
};


#endif 