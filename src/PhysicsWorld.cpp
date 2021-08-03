#include "PhysicsWorld.h"
#include "GameObject2D.h"

PhysicsWorld::PhysicsWorld()
{
	// Gravity in Y direction
	b2Vec2 gravity(0.0, -10.0f);
	pWorld = new b2World(gravity);

	// scale: pixels per meter
	UnitScale::Create(50);
}

PhysicsWorld::~PhysicsWorld()
{
	delete pWorld;
}

PhysicsWorld::PhysicsWorld(float _gravity, float pix_meter)
{
	if (_gravity > 0)
	{
		_gravity *= -1;
	}

	// Gravity in Y direction
	b2Vec2 gravity(0.0, _gravity);
	pWorld = new b2World(gravity);

	// scale: pixels per meter
	UnitScale::Create(pix_meter);
}

void PhysicsWorld::Update()
{
	int velocityIterations = 8;
	int positionIterations = 3;
	float timestep = 1.0f / 60; // 60 fps. Box2D does not recommend tying this to framerate
	pWorld->Step(timestep, velocityIterations, positionIterations);

	b2Body* pBody = pWorld->GetBodyList();
	while (pBody != 0) // Loop through all the bodies in the Box2D
	{
		b2Fixture* pFix = pBody->GetFixtureList();
		while (pFix != 0) // For each body, loop through all its fixtures
		{
			// For a given fixture, get the associated GameObject2D
			GameObject2D* pGObj = static_cast<GameObject2D*>(pFix->GetUserData());

			b2Vec2 fixCenter;
			if (pBody->IsActive())
			{
				fixCenter = pFix->GetAABB(0).GetCenter();
			}
			else
			{   // Must extract the center this way when body is inactive
				b2AABB tmpAABB;
				pFix->GetShape()->ComputeAABB(&tmpAABB, pBody->GetTransform(), 0);
				fixCenter = tmpAABB.GetCenter();
			}

			float ang = pBody->GetAngle();

			pGObj->PhysicsUpdate(fixCenter, ang);

			pFix = pFix->GetNext();
		}

		pBody = pBody->GetNext();
	}
}

PhysicsBody* PhysicsWorld::CreateBody(GameObject2D* pGameObj, BodyType bodyType, PhysicsFixture* pFixture)
{
	assert(pGameObj);

	b2BodyDef bodyDef;
	bodyDef.type = (b2BodyType)bodyType; // see PhysicsBody.h
	bodyDef.position.Set(PixelToMeter(pGameObj->posX), PixelToMeter(pGameObj->posY));
	bodyDef.angle = pGameObj->currAngle;

	return new PhysicsBody(pGameObj, this, pWorld->CreateBody(&bodyDef), pFixture);
}

void PhysicsWorld::DestroyBody(PhysicsBody* pBody)
{
	pBody->DestroyBody(this->pWorld);
}

b2Joint* PhysicsWorld::CreateJoint(b2JointDef& def)
{
	return this->pWorld->CreateJoint(&def);
}

b2World* PhysicsWorld::GetWorld()
{
	return pWorld;
}

