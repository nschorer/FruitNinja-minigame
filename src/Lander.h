#ifndef LANDER_H
#define LANDER_H

#include "Thruster.h"
#include "PhysicsObject2D.h"

class Lander : public PhysicsObject2D
{
public:

	virtual ~Lander() = default;

	Lander(PhysicsWorld* pWorld);
	virtual void Update(float t) override;

	virtual void FireUp() = 0;
	virtual void TurnLeft() = 0;
	virtual void TurnRight() = 0;



protected:
	static PhysicsFixture fixture;
};

#endif