#ifndef PHYSICS_WORLD_H
#define PHYSICS_WORLD_H

#include "PhysicsBody.h"

class PhysicsWorld
{
public:
	PhysicsWorld();
	~PhysicsWorld();
	PhysicsWorld(const PhysicsWorld&) = delete;
	PhysicsWorld& operator=(const PhysicsWorld&) = delete;

	PhysicsWorld(float gravity, float pix_meter);

	void Update();
	
	PhysicsBody* CreateBody(GameObject2D* pGameObj, BodyType bodyType, PhysicsFixture* pFixture);
	void DestroyBody(PhysicsBody* pBody);

	b2Joint* CreateJoint(b2JointDef& def);

	b2World* GetWorld();

private:
	b2World* pWorld;

};

#endif