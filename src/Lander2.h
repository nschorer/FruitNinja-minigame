#ifndef LANDER_2_H
#define LANDER_2_H

#include "Lander.h"

class Lander2 : public Lander
{
public:
	virtual ~Lander2();

	Lander2(PhysicsWorld* pWorld);
	virtual void Update(float t) override;

	virtual void FireUp();
	virtual void TurnLeft();
	virtual void TurnRight();

private:
	Thruster* pLeftThruster;
	Thruster* pRightThruster;
};

#endif