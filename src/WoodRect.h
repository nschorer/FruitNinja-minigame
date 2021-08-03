#ifndef WOOD_RECT_H
#define WOOD_RECT_H


#include "Block_Base.h"

class WoodRect : public Block_Base
{
public:

	WoodRect(float x, float y, PhysicsWorld* pWorld);
	virtual ~WoodRect() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif