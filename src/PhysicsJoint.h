#ifndef PHYSICS_JOINT_H
#define PHYSICS_JOINT_H

#include "PhysicsObject2D.h"

class PhysicsJoint
{
public:
	static b2RevoluteJoint* Revolute(PhysicsObject2D* pObj1, PhysicsObject2D* pObj2, Vect2D& obj1Offset);
	static b2RevoluteJoint* Revolute(PhysicsObject2D* pObj1, PhysicsObject2D* pObj2, Vect2D& obj1Offset, float speed, float maxTorque);

	static b2PrismaticJoint* Prismatic(PhysicsObject2D* pObj1, PhysicsObject2D* pObj2, Vect2D& anchorA, Vect2D& anchorB, Vect2D& axisA);

	static b2DistanceJoint* Distance(PhysicsObject2D* pObj1, PhysicsObject2D* pObj2, Vect2D& anchorA, Vect2D& anchorB, float len);

	static b2GearJoint* Gear(PhysicsObject2D* pObj1, PhysicsObject2D* pObj2, b2Joint* pJointA, b2Joint* pJointB, float ratio = 1.0f);

	static b2WeldJoint* Weld(PhysicsObject2D* pObj1, PhysicsObject2D* pObj2, Vect2D& anchor);
	static b2WeldJoint* Weld(PhysicsObject2D* pObj1, PhysicsObject2D* pObj2, Vect2D& anchorA, Vect2D& anchorB);
};

#endif