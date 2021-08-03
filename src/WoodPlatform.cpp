#include "WoodPlatform.h"

PhysicsFixture WoodPlatform::fixture(Shape::Rectangle, 1.0f, 0.3f, 0.0f);
ImageName::Name WoodPlatform::image = ImageName::Wood_Platform;
float WoodPlatform::width = 156.0f;
float WoodPlatform::height = 44.0f;

WoodPlatform::WoodPlatform(float x, float y, PhysicsWorld* pWorld)
	:PhysicsObject2D(GameObjectName::WoodPlatform, new GraphicsObject_Sprite(image, Rect(x, y, WoodPlatform::width, WoodPlatform::height)), pWorld, BodyType::Dynamic, &WoodPlatform::fixture)
{

}
