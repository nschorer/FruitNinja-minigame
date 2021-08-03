#ifndef STONE_SQUARE_H
#define STONE_SQUARE_H


#include "Block_Base.h"

class StoneSquare : public Block_Base
{
public:

	StoneSquare(float x, float y, PhysicsWorld* pWorld);
	virtual ~StoneSquare() = default;

private:
	static PhysicsFixture fixture;
	static float width;
	static float height;
	static ImageName::Name imgNames[4];

};

#endif