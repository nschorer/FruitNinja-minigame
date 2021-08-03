#ifndef STONE_RECT_H
#define STONE_RECT_H


#include "Block_Base.h"

class StoneRect : public Block_Base
{
public:

	StoneRect(float x, float y, PhysicsWorld* pWorld);
	virtual ~StoneRect() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif