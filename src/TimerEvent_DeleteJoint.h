#ifndef TIMER_EVENT_DELETE_JOINT_H
#define TIMER_EVENT_DELETE_JOINT_H

#include "TimerEvent.h"
#include "Box2DWrapper.h"

class TimerEvent_DeleteJoint : public TimerEvent
{
public:
	TimerEvent_DeleteJoint(b2Joint* pJoint);
	virtual ~TimerEvent_DeleteJoint() = default;

	virtual void Execute(float currTime) override;

	b2Joint* pJoint;
};

#endif