#ifndef		WHITE_BIRD_H
#define		WHITE_BIRD_H

#include "PhysicsObject2D.h"

class WhiteBird : public PhysicsObject2D
{
public:

	WhiteBird(float x, float y, PhysicsWorld* pWorld);

private:
	static PhysicsFixture fixture;
	static ImageName::Name image;
	static float width;
	static float height;

};


#endif