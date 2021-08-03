#include "PhysicsBody.h"
#include "PhysicsWorld.h"

PhysicsBody::PhysicsBody(GameObject2D* _pGameObj, PhysicsWorld* _pWorld, b2Body* _pB2Body, PhysicsFixture* pFixture)
	:pGameObj(_pGameObj), pWorld(_pWorld), pB2Body(_pB2Body)
{
	b2FixtureDef& def = pFixture->fixDef;

	def.userData = pGameObj;

	b2PolygonShape boxShape;
	b2CircleShape  circleShape;

	float globalOffset = 2.0f;

	switch (pFixture->shape)
	{
	case Shape::Rectangle:
		boxShape.SetAsBox(PixelToMeter(pGameObj->origWidth * 0.5f-globalOffset), PixelToMeter(pGameObj->origHeight * 0.5f - globalOffset));
		def.shape = &boxShape;
		break;
	case Shape::Circle:
		circleShape.m_p.Set(0, 0);
		circleShape.m_radius = PixelToMeter(pGameObj->origWidth * 0.5f - globalOffset);
		def.shape = &circleShape;
		break;
	case Shape::Triangle:
		assert("Shape not implemented" && false);
		break;
	default:
		assert("Shape not implemented" && false);
		break;
	}

	// Other parameters should have been set before being passed in
	this->pB2Body->CreateFixture(&def);
}

PhysicsBody::~PhysicsBody()
{
	this->pWorld->DestroyBody(this);
}

void PhysicsBody::DestroyBody(b2World* pB2World)
{
	pB2World->DestroyBody(this->pB2Body);
}

void PhysicsBody::AddFixture(PhysicsFixture* pFixture)
{
	AddFixture(pFixture, 0, 0, 0);
}

void PhysicsBody::AddFixture(PhysicsFixture* pFixture, float xOff, float yOff, float rotation)
{
	b2FixtureDef& def = pFixture->fixDef;

	def.userData = pGameObj;

	b2PolygonShape boxShape;
	b2CircleShape  circleShape;

	switch (pFixture->shape)
	{
	case Shape::Rectangle:
		boxShape.SetAsBox(PixelToMeter(pGameObj->origWidth * 0.5f), 
			PixelToMeter(pGameObj->origHeight * 0.5f),
			b2Vec2(PixelToMeter(xOff), PixelToMeter(yOff)),
			pGameObj->origAngle + rotation);

		def.shape = &boxShape;
		break;
	case Shape::Circle:
		circleShape.m_p.Set(xOff, yOff);
		circleShape.m_radius = PixelToMeter(pGameObj->origWidth * 0.5f);
		// rotation is ignored (update the game object if you need to)
		def.shape = &circleShape;
		break;
	case Shape::Triangle:
		assert("Shape not implemented" && false);
		break;
	default:
		assert("Shape not implemented" && false);
		break;
	}

	// Other parameters should have been set before being passed in
	this->pB2Body->CreateFixture(&def);
}

void PhysicsBody::SetActive(bool active)
{
	this->pB2Body->SetActive(active);
}

float PhysicsBody::GetAngle()
{
	return this->pB2Body->GetAngle();
}

void PhysicsBody::SetPosition(float x, float y)
{
	this->pB2Body->SetTransform(b2Vec2(PixelToMeter(x), PixelToMeter(y)), this->pB2Body->GetAngle());
}

void PhysicsBody::SetAngle(float angle)
{
	this->pB2Body->SetTransform(this->pB2Body->GetPosition(), angle);
}

void PhysicsBody::ApplyForce(Vect2D& force)
{
	b2Vec2 tmp(force.x, force.y);
	this->pB2Body->ApplyForceToCenter(pB2Body->GetMass() * tmp, true);
}

void PhysicsBody::ApplyForceToPoint(Vect2D& force, Vect2D& point)
{
	b2Vec2 tmp(force.x, force.y);
	//b2Vec2 ForcePoint(+PixelToMeter(point.x), +PixelToMeter(point.y));
	b2Vec2 ForcePoint(point.x, point.y);
	this->pB2Body->ApplyForce(pB2Body->GetMass() * tmp, pB2Body->GetWorldPoint(ForcePoint), true);
}

void PhysicsBody::ApplyImpulse(Vect2D& impulse)
{
	b2Vec2 tmp(impulse.x, impulse.y);
	this->pB2Body->ApplyLinearImpulseToCenter(pB2Body->GetMass() * tmp, true);
}

void PhysicsBody::ApplyImpulseToPoint(Vect2D& impulse, Vect2D& point)
{
	b2Vec2 tmp(impulse.x, impulse.y);
	//b2Vec2 ForcePoint(+PixelToMeter(point.x), +PixelToMeter(point.y));
	b2Vec2 ForcePoint(point.x, point.y);
	this->pB2Body->ApplyLinearImpulse(pB2Body->GetMass() * tmp, pB2Body->GetWorldPoint(ForcePoint), true);
}

void PhysicsBody::SetCollisionFlags(unsigned int categoryBits, unsigned int maskBits)
{
	for (b2Fixture* f = this->pB2Body->GetFixtureList(); f; f = f->GetNext())
	{
		b2Filter filter = f->GetFilterData();

		filter.categoryBits = (uint16)categoryBits;
		filter.maskBits = (uint16)maskBits;

		f->SetFilterData(filter);
	}
}

PhysicsWorld* PhysicsBody::GetWorld()
{
	return this->pWorld;
}

b2Body* PhysicsBody::GetB2Body()
{
	return this->pB2Body;
}
