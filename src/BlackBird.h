#ifndef BLACK_BIRD_H
#define BLACK_BIRD_H

#include "PhysicsObject2D.h"

class BlackBird : public PhysicsObject2D
{
public:

	BlackBird(float x, float y, PhysicsWorld* pWorld);
	void Explode();

private:
	static PhysicsFixture fixture;
	static ImageName::Name image;
	static float width;
	static float height;

};


#endif