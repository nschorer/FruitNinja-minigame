#ifndef PHYSICS_MAN_H
#define PHYSICS_MAN_H

#include "PhysicsWorld.h"

class PhysicsMan
{
public:
	static void Create();
	static void Update();
	static void Terminate();

	static void AddWorld(PhysicsWorld* pWorld);

	static PhysicsWorld* GetWorld(); // not permanent

private:
	PhysicsMan();

private:
	static PhysicsMan* privGetInstance();

	PhysicsWorld* pWorld;
};

#endif // !PHYSICS_MAN_H