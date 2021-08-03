#ifndef THRUSTER_H
#define THRUSTER_H

//#include "Box2D.h"
#include "Box2DWrapper.h"
#include "PhysicsObject2D.h"

class Lander;

class Thruster
{
public:

	~Thruster();

	Thruster(PhysicsBody* pBody, float x, float y, float ang, float scale);

	void Update(Lander* pLander);

	void ApplyForce(float force);
	void ApplyTorque(float torque);

private:
	PhysicsBody* pBody;
	float x;
	float y;
	float ang;
	float scale;

	GraphicsObject_Sprite* poSprite;
	GraphicsObject_Sprite* poNullSprite;
	GameObject2D* poBang;

	bool active;

	static ImageName::Name img;
	static float width;
	static float height;
};

#endif