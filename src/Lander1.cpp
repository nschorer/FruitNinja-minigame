#include "Lander1.h"

Lander1::Lander1(PhysicsWorld* pWorld)
	:Lander(pWorld)
{
	pMainThruster = new Thruster(pPhysicsBody, 0, -23, MATH_PI2, 100);
	pLeftThruster = new Thruster(pPhysicsBody, -23, 23, 0, 50);
	pRightThruster = new Thruster(pPhysicsBody, 23, 23, MATH_PI, 50);
}

Lander1::~Lander1()
{
	delete pMainThruster;
	delete pLeftThruster;
	delete pRightThruster;
}

void Lander1::Update(float t)
{
	Lander::Update(t);

	pMainThruster->Update(this);
	pLeftThruster->Update(this);
	pRightThruster->Update(this);
}

void Lander1::FireUp()
{
	pMainThruster->ApplyForce(15);
}

void Lander1::TurnLeft()
{
	pRightThruster->ApplyTorque(5);
}

void Lander1::TurnRight()
{
	pLeftThruster->ApplyTorque(5);
}


