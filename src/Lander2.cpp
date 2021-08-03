#include "Lander2.h"

Lander2::Lander2(PhysicsWorld* pWorld)
	:Lander(pWorld)
{
	pLeftThruster = new Thruster(pPhysicsBody, -15, -23, MATH_PI2, 80);
	pRightThruster = new Thruster(pPhysicsBody, 15, -23, MATH_PI2, 80);
}

Lander2::~Lander2()
{
	delete pLeftThruster;
	delete pRightThruster;
}

void Lander2::Update(float t)
{
	Lander::Update(t);

	pLeftThruster->Update(this);
	pRightThruster->Update(this);
}

void Lander2::FireUp()
{
	// Nothing!
}

void Lander2::TurnLeft()
{
	pRightThruster->ApplyTorque(10);
}

void Lander2::TurnRight()
{
	pLeftThruster->ApplyTorque(10);
}


