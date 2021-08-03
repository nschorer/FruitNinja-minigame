#include "RedBird.h"
#include "ContactAction.h"


PhysicsFixture RedBird::fixture(Shape::Circle, 5.0f, 0.3f, 0.75f, FilterCategory::BIRD);
ImageName::Name RedBird::image = ImageName::Bird_Red_0;
float RedBird::width = 46.0f;
float RedBird::height = 45.0f;

RedBird::RedBird(float x, float y, PhysicsWorld* pWorld)
	:PhysicsObject2D(GameObjectName::Bird_Red, new GraphicsObject_Sprite(image, Rect(x, y, RedBird::width, RedBird::height)), pWorld, BodyType::Dynamic, &RedBird::fixture)
{

}

void RedBird::CollideVisit(Block_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	if (pimpulse)
		ContactAction::ContactPair(*this, other, pcontact, pimpulse);
}

void RedBird::CollideVisit(Pig_Base& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
{
	if (pimpulse)
		ContactAction::ContactPair(*this, other, pcontact, pimpulse);
}

