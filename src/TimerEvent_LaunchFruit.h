#ifndef TIMER_EVENT_LAUNCH_FRUIT_H
#define TIMER_EVENT_LAUNCH_FRUIT_H

#include "TimerEvent.h"
#include "NinjaLauncher.h"

class TimerEvent_LaunchFruit : public TimerEvent
{
public:
	TimerEvent_LaunchFruit(NinjaLauncher* pLauncher, NinjaLauncher::Difficulty _diff);
	virtual ~TimerEvent_LaunchFruit() = default;

	virtual void Execute(float currTime) override;

	NinjaLauncher* pLauncher;
	NinjaLauncher::Difficulty diff;
};

#endif