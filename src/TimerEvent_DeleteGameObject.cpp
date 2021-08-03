#include "TimerEvent_DeleteGameObject.h"
#include "GameObjectMan.h"

TimerEvent_DeleteGameObject::TimerEvent_DeleteGameObject(GameObject2D* _pGObj)
	:pGObj(_pGObj)
{
}

void TimerEvent_DeleteGameObject::Execute(float currTime)
{
	currTime;
	pGObj->MarkForDelete();
}
