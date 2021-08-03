#ifndef TIMER_EVENT_DELETE_GAME_OBJECT_H
#define TIMER_EVENT_DELETE_GAME_OBJECT_H

#include "TimerEvent.h"
#include "GameObject2D.h"

class TimerEvent_DeleteGameObject : public TimerEvent
{
public:
	TimerEvent_DeleteGameObject(GameObject2D* pGObj);
	virtual ~TimerEvent_DeleteGameObject() = default;

	virtual void Execute(float currTime) override;

	GameObject2D* pGObj;
};

#endif