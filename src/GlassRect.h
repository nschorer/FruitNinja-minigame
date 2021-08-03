#ifndef GLASS_RECT_H
#define GLASS_RECT_H


#include "Block_Base.h"

class GlassRect : public Block_Base
{
public:

	GlassRect(float x, float y, PhysicsWorld* pWorld);
	virtual ~GlassRect() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif