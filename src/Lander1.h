#ifndef LANDER_1_H
#define LANDER_1_H

#include "Lander.h"

class Lander1 : public Lander
{
public:
	virtual ~Lander1();

	Lander1(PhysicsWorld * pWorld);
	virtual void Update(float t) override;

	virtual void FireUp();
	virtual void TurnLeft();
	virtual void TurnRight();

private:
	Thruster* pMainThruster;
	Thruster* pLeftThruster;
	Thruster* pRightThruster;
};

#endif