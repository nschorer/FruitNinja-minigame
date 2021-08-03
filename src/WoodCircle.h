#ifndef WOOD_CIRCLE_H
#define WOOD_CIRCLE_H


#include "Block_Base.h"

class WoodCircle : public Block_Base
{
public:

	WoodCircle(float x, float y, PhysicsWorld* pWorld);
	virtual ~WoodCircle() = default;

private:
	static PhysicsFixture fixture;
	static ImageName::Name image;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif