#include "SmallPig.h"
#include "TimerEvent_DeleteJoint.h"
#include "TimerMan.h"

PhysicsFixture SmallPig::fixture(Shape::Circle, 20.0f, 0.3f, 0.5f);
float SmallPig::width = 48.0f;
float SmallPig::height = 46.0f;
ImageName::Name SmallPig::imgNames[] = { ImageName::Name::Pig_Small_0, ImageName::Name::Pig_Small_1 };
float SmallPig::maxHealth = 25.0f;

SmallPig::SmallPig(float x, float y, PhysicsWorld* pWorld)
	:Pig_Base(GameObjectName::Name::Pig_Small, x, y, width, height, &fixture, maxHealth, imgNames, pWorld), pJoint(nullptr)
{

}

void SmallPig::DestroyJoint()
{
	if (pJoint)
	{
		TimerEvent* pEvent = new TimerEvent_DeleteJoint(pJoint);
		TimerMan::AddEvent(0, pEvent);
		pJoint = nullptr;
	}
}
