#include "TimerEvent_DeleteJoint.h"
#include "PhysicsMan.h"
#include "Game.h"

TimerEvent_DeleteJoint::TimerEvent_DeleteJoint(b2Joint* _pJoint)
	: pJoint(_pJoint)
{
}

void TimerEvent_DeleteJoint::Execute(float currTime)
{
	currTime;
	PhysicsMan::GetWorld()->GetWorld()->DestroyJoint(pJoint);
}
