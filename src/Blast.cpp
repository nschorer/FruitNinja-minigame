#include "Blast.h"
#include "ContactAction.h"

#include "BlocksHeader.h"

PhysicsFixture Blast::fixture(Shape::Circle);
ImageName::Name Blast::image = ImageName::Bang;
float Blast::width = 150.0f;
float Blast::height = 150.0f;

Blast::Blast(float x, float y, PhysicsWorld* pWorld)
	:PhysicsObject2D(GameObjectName::Bang, new GraphicsObject_Sprite(image, Rect(x, y, Blast::width, Blast::height)), pWorld, BodyType::Static, &Blast::fixture), framecount(0)
{

}

void Blast::Update(float t)
{
	if (framecount > 60)
	{
		this->MarkForDelete();
	}

	framecount++;

	PhysicsObject2D::Update(t);
}

//void Blast::CollideVisit(WoodPlatShort& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse)
//{
//	ContactAction::ContactPair(*this, other, pcontact, pimpulse);
//}
