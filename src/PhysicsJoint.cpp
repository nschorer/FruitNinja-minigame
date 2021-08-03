
#include "PhysicsJoint.h"

#include "PhysicsMan.h"

b2RevoluteJoint* PhysicsJoint::Revolute(PhysicsObject2D* pObj1, PhysicsObject2D* pObj2, Vect2D& obj1Offset)
{
	return PhysicsJoint::Revolute(pObj1, pObj2, obj1Offset, 0, 0);
}

b2RevoluteJoint* PhysicsJoint::Revolute(PhysicsObject2D* pObj1, PhysicsObject2D* pObj2, Vect2D& obj1Offset, float speed, float maxTorque)
{
	// Revolute Joint
	b2RevoluteJointDef rjdef;  // https://en.wikipedia.org/wiki/Revolute_joint
	b2Body* pB1 = pObj1->GetPhysicsBody()->GetB2Body();
	b2Body* pB2 = pObj2->GetPhysicsBody()->GetB2Body();
	rjdef.Initialize(
		pB1,
		pB2,
		pB1->GetWorldPoint(b2Vec2(obj1Offset.x, obj1Offset.y))
	);


	rjdef.enableMotor = speed != 0 ? true : false;
	rjdef.motorSpeed = speed;
	rjdef.maxMotorTorque = maxTorque;

	return (b2RevoluteJoint*)PhysicsMan::GetWorld()->CreateJoint(rjdef);
}

b2PrismaticJoint* PhysicsJoint::Prismatic(PhysicsObject2D* pObj1, PhysicsObject2D* pObj2, Vect2D& anchorA, Vect2D& anchorB, Vect2D& axisA)
{
	b2PrismaticJointDef pjdef;

	pjdef.bodyA = pObj1->GetPhysicsBody()->GetB2Body();
	pjdef.bodyB = pObj2->GetPhysicsBody()->GetB2Body();
	pjdef.localAnchorA = b2Vec2(anchorA.x, anchorA.y);
	pjdef.localAnchorB = b2Vec2(anchorB.x, anchorB.y);
	pjdef.localAxisA = b2Vec2(axisA.x, axisA.y);

	return (b2PrismaticJoint*)PhysicsMan::GetWorld()->CreateJoint(pjdef);
}

b2DistanceJoint* PhysicsJoint::Distance(PhysicsObject2D* pObj1, PhysicsObject2D* pObj2, Vect2D& anchorA, Vect2D& anchorB, float len)
{
	b2DistanceJointDef djDef;

	djDef.bodyA = pObj1->GetPhysicsBody()->GetB2Body();
	djDef.bodyB = pObj2->GetPhysicsBody()->GetB2Body();
	djDef.localAnchorA = b2Vec2(anchorA.x, anchorA.y);
	djDef.localAnchorB = b2Vec2(anchorB.x, anchorB.y);
	djDef.length = len;

	return (b2DistanceJoint*)PhysicsMan::GetWorld()->CreateJoint(djDef);
}

b2GearJoint* PhysicsJoint::Gear(PhysicsObject2D* pObj1, PhysicsObject2D* pObj2, b2Joint* pJointA, b2Joint* pJointB, float ratio)
{
	b2GearJointDef gjDef;

	gjDef.bodyA = pObj1->GetPhysicsBody()->GetB2Body();
	gjDef.bodyB = pObj2->GetPhysicsBody()->GetB2Body();
	gjDef.joint1 = pJointA;
	gjDef.joint2 = pJointB;
	gjDef.ratio = ratio;

	return (b2GearJoint*)PhysicsMan::GetWorld()->CreateJoint(gjDef);
}

b2WeldJoint* PhysicsJoint::Weld(PhysicsObject2D* pObj1, PhysicsObject2D* pObj2, Vect2D& anchor)
{
	b2WeldJointDef def;

	def.Initialize(pObj1->GetPhysicsBody()->GetB2Body(), pObj2->GetPhysicsBody()->GetB2Body(), b2Vec2(anchor.x, anchor.y));
	return (b2WeldJoint*)PhysicsMan::GetWorld()->CreateJoint(def);
}

b2WeldJoint* PhysicsJoint::Weld(PhysicsObject2D* pObj1, PhysicsObject2D* pObj2, Vect2D& anchorA, Vect2D& anchorB)
{
	b2WeldJointDef def;

	//def.Initialize(pObj1->GetPhysicsBody()->GetB2Body(), pObj2->GetPhysicsBody()->GetB2Body(), b2Vec2(anchor.x, anchor.y));

	def.bodyA = pObj1->GetPhysicsBody()->GetB2Body();
	def.bodyB = pObj2->GetPhysicsBody()->GetB2Body();
	def.localAnchorA = b2Vec2(anchorA.x, anchorA.y);
	def.localAnchorA = b2Vec2(anchorB.x, anchorB.y);
	def.collideConnected = false;

	return (b2WeldJoint*)PhysicsMan::GetWorld()->CreateJoint(def);
}
