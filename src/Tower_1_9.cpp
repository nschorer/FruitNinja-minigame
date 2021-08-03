#include "Tower_1_9.h"

#include "PhysicsObject2D.h"
#include "GameObjectMan.h"
#include "BlocksHeader.h"
#include "BirdsPigsHeader.h"

Tower_1_9::Tower_1_9(float x, float y, PhysicsWorld* pWorld)
{
	PhysicsObject2D* pPhysObj;
	int idx = 0;

	pPhysObj = new StoneRect(x - 120, 0.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new StoneRect(x + 120, 0.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new StoneRect(x - 170, 0.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new StoneRect(x + 170, 0.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatMedium(x, y + 50.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new MediumPig(x, y + 100.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodSquare(x-100, y + 60.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodRect(x - 160, y + 60.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodRect(x + 125, y + 60.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodSquare(x + 185, y + 60.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodRect(x - 125, y + 110.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodSquare(x - 175, y + 110.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodRect(x + 164, y + 110.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodSquare(x + 105, y + 110.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new StoneRect(x - 140, y + 170.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new StoneRect(x + 145.0f, y + 170.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatShort(x + 95.0f, y + 170.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatShort(x + 195.0f, y + 170.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatShort(x - 90, y + 170.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatShort(x - 190, y + 170.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatMedium(x - 140, y + 220.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodRect(x - 203, y + 245.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodRect(x - 77, y + 245.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatMedium(x - 140, y + 310.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new SmallPig(x - 140, y + 230.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new GlassRect(x - 140, y + 325.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new GlassPlatShort(x - 140, y + 380.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatMedium(x + 145, y + 220.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodRect(x + 82, y + 245.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodRect(x + 208, y + 245.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new WoodPlatMedium(x + 145, y + 310.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new SmallPig(x + 145.0f, y + 230.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new GlassRect(x + 145.0f, y + 325.0f, pWorld);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;

	pPhysObj = new GlassPlatShort(x + 145.0f, y + 380.0f, pWorld);
	pPhysObj->SetAngle(MATH_PI2);
	GameObjectMan::Add(pPhysObj, GameObjectName::MainGroup);
	pObjects[idx++] = pPhysObj;
}

void Tower_1_9::Demolish()
{
	for (int i = 0; i < sizeof(pObjects)/sizeof(PhysicsObject2D*); i++)
	{
		GameObjectMan::AddToDeleteList(pObjects[i]);
	}
}
