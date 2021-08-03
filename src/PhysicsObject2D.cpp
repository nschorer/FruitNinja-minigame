#include "PhysicsObject2D.h"

PhysicsObject2D::~PhysicsObject2D()
{
	delete pPhysicsBody;
}

PhysicsObject2D::PhysicsObject2D(GameObjectName::Name name, GraphicsObject_Sprite* pSprite, PhysicsWorld* pWorld, BodyType bodyType, PhysicsFixture* pFixture)
	:GameObject2D(name, pSprite), pPhysicsBody(pWorld->CreateBody(this, bodyType, pFixture)), ignoreRaycast(true)
{
}

void PhysicsObject2D::AddFixture(PhysicsFixture* pFixture)
{
	this->pPhysicsBody->AddFixture(pFixture);
}

void PhysicsObject2D::SetPhysicsActive(bool active)
{
	this->pPhysicsBody->SetActive(active);
}

void PhysicsObject2D::ApplyForce(Vect2D& force)
{
	this->pPhysicsBody->ApplyForce(force);
}

void PhysicsObject2D::ApplyForceToPoint(Vect2D& force, Vect2D& point)
{
	this->pPhysicsBody->ApplyForceToPoint(force, point);
}

void PhysicsObject2D::ApplyImpulse(Vect2D& impulse)
{
	this->pPhysicsBody->ApplyImpulse(impulse);
}

void PhysicsObject2D::ApplyImpulseToPoint(Vect2D& impulse, Vect2D& point)
{
	this->pPhysicsBody->ApplyImpulseToPoint(impulse, point);
}

void PhysicsObject2D::SetAngle(float angle)
{
	this->currAngle = angle;

	this->pPhysicsBody->SetAngle(angle);
}

void PhysicsObject2D::SetPosition(float x, float y)
{
	this->posX = x;
	this->posY = y;

	this->pPhysicsBody->SetPosition(x, y);
}

void PhysicsObject2D::SetCollisionFlags(unsigned int categoryBits, unsigned int maskBits)
{
	this->pPhysicsBody->SetCollisionFlags(categoryBits, maskBits);
}

PhysicsBody* PhysicsObject2D::GetPhysicsBody()
{
	return this->pPhysicsBody;
}

bool PhysicsObject2D::IgnoresRaycast()
{
	return ignoreRaycast;
}
