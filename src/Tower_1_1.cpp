#include "Tower_1_1.h"

#include "PhysicsObject2D.h"
#include "BlocksHeader.h"
#include "BirdsPigsHeader.h"
#include "GameObjectMan.h"

Tower_1_1::Tower_1_1(float x, float y, PhysicsWorld* pWorld)
{
	PhysicsObject2D* pPhysObj;
	int idx = 0;

	pPhysObj = new WoodPlatform(x - 70.0f, y, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatform(x + 70.0f, y, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatMedium(x - 73.0f, y + 155.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatMedium(x + 73.0f, y + 155.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatMedium(x, y + 240.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatMedium(x - 37.0f, y + 300.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatMedium(x + 37.0f, y + 300.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatTiny(x, y + 250.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatTiny(x - 130.0f, y + 60.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatTiny(x + 130.0f, y + 60.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatTiny(x, y + 430.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatShort(x, y + 80.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatShort(x, y + 180.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatShort(x, y + 400.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new GlassPlatShort(x - 30.0f, y + 120.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new GlassPlatShort(x + 30.0f, y + 120.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new SmallPig(x, y + 280.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;
}


void Tower_1_1::Demolish()
{
	for (int i = 0; i < sizeof(pObjects)/sizeof(PhysicsObject2D*); i++)
	{
		GameObjectMan::AddToDeleteList(pObjects[i]);
	}
}
