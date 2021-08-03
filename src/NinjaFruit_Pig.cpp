#include "NinjaFruit_Pig.h"

ImageName::Name NinjaFruit_Pig::imgNames[] = { ImageName::Name::Pig_Medium_0, ImageName::Name::Pig_Medium_1, ImageName::Name::Pig_Medium_1 };
float NinjaFruit_Pig::radius = 50.0f;

NinjaFruit_Pig::NinjaFruit_Pig(float x, float y, PhysicsWorld* pWorld)
	:NinjaFruit(GameObjectName::Name::Alien, x, y, NinjaFruit_Pig::radius, 100, NinjaFruit_Pig::imgNames, pWorld)
{
}
