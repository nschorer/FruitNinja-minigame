#include "TimerEvent_LaunchFruit.h"

TimerEvent_LaunchFruit::TimerEvent_LaunchFruit(NinjaLauncher* _pLauncher, NinjaLauncher::Difficulty _diff)
	:pLauncher(_pLauncher), diff(_diff)
{
}

void TimerEvent_LaunchFruit::Execute(float currTime)
{
	currTime;
	pLauncher->StartLaunching(diff);
}
