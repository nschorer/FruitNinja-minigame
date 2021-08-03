#ifndef SEESAW_H
#define SEESAW_H

class PhysicsWorld;
class PhysicsObject2D;

class Seesaw
{
public:
	Seesaw(float x, float y, PhysicsWorld* pWorld);
	virtual ~Seesaw() = default;

	void Demolish();

private:
	PhysicsObject2D* pObjects[6];
};

#endif