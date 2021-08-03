#include "WoodRect.h"
#include "ContactAction.h"

#include "WoodMaterial.h"

PhysicsFixture WoodRect::fixture(Shape::Rectangle, *WoodMaterial::Instance());
float WoodRect::width = 84.0f;
float WoodRect::height = 44.0f;
ImageName::Name WoodRect::imgNames[] = { ImageName::Name::Wood_Rect_0, ImageName::Name::Wood_Rect_1, ImageName::Name::Wood_Rect_2, ImageName::Name::Wood_Rect_3 };

WoodRect::WoodRect(float x, float y, PhysicsWorld* pWorld)
	:Block_Base(GameObjectName::Wood_Rect, x, y, width, height, &fixture, imgNames, WoodMaterial::Instance(), pWorld)
{

}

