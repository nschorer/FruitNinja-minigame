#ifndef MEDIUM_PIG_H
#define MEDIUM_PIG_H

#include "Pig_Base.h"

class MediumPig : public Pig_Base
{
public:

	MediumPig(float x, float y, PhysicsWorld* pWorld);
	virtual ~MediumPig() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[2];
	static float maxHealth;
};


#endif