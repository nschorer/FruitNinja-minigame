#ifndef WOOD_SQUARE_H
#define WOOD_SQUARE_H


#include "Block_Base.h"

class WoodSquare : public Block_Base
{
public:

	WoodSquare(float x, float y, PhysicsWorld* pWorld);
	virtual ~WoodSquare() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif