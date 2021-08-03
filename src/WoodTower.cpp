#include "WoodTower.h"
#include "WoodPlatShort.h"
#include "GameObjectMan.h"
#include "PhysicsMan.h"

WoodTower::WoodTower(float x, float y, int numLevels)
	:numObjects(numLevels * 3)
{
	pObjects = (PhysicsObject2D**)new unsigned char[sizeof(PhysicsObject2D*) * numObjects];

	PhysicsObject2D* pGameObj;
	PhysicsWorld* pWorld = PhysicsMan::GetWorld();

	for (int i = 0; i < numLevels; i++)
	{

		pGameObj = new WoodPlatShort(x - 30.0f, y, pWorld);
		GameObjectMan::Add(pGameObj, GameObjectName::MainGroup);
		pGameObj->SetAngle(MATH_PI2);
		pObjects[i * 3] = (PhysicsObject2D*)pGameObj;

		pGameObj = new WoodPlatShort(x + 30.0f, y, pWorld);
		GameObjectMan::Add(pGameObj, GameObjectName::MainGroup);
		pGameObj->SetAngle(MATH_PI2);
		pObjects[i * 3 + 1] = (PhysicsObject2D*)pGameObj;

		pGameObj = new WoodPlatShort(x, y + 60.0f, pWorld);
		GameObjectMan::Add(pGameObj, GameObjectName::MainGroup);
		pObjects[i * 3 + 2] = (PhysicsObject2D*)pGameObj;

		y += 100.0f;
	}

}

WoodTower::~WoodTower()
{
	delete[] pObjects;
}

void WoodTower::Demolish()
{
	for (int i = 0; i < numObjects; i++)
	{
		GameObjectMan::AddToDeleteList(pObjects[i]);
	}
	delete this;
}
