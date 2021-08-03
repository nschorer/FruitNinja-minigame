#include "Lander.h"
#include "MathEngine.h"
#include "Keyboard.h"

PhysicsFixture Lander::fixture(Shape::Rectangle, 0.3f, 0.3f, 0.3f);

Lander::Lander(PhysicsWorld* pWorld)
	:PhysicsObject2D(GameObjectName::Lander, new GraphicsObject_Sprite(ImageName::Bird_Red_0, Rect(400, 500, 50, 50)), pWorld, BodyType::Dynamic, &Lander::fixture)
{
}

void Lander::Update(float t)
{
	PhysicsObject2D::Update(t);
	t++;
}
