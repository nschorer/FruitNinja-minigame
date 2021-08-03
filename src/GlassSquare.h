#ifndef GLASS_SQUARE_H
#define GLASS_SQUARE_H


#include "Block_Base.h"

class GlassSquare : public Block_Base
{
public:

	GlassSquare(float x, float y, PhysicsWorld* pWorld);
	virtual ~GlassSquare() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif