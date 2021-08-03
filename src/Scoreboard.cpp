#include "Scoreboard.h"
#include "NinjaLauncher.h"

void Scoreboard::Setup(NinjaLauncher* _pLauncher)
{
    Instance()->pLauncher = _pLauncher;
}

Scoreboard* Scoreboard::Instance()
{
    static Scoreboard instance;
    return &instance;
}

void Scoreboard::ChangeScore(int val)
{
    Scoreboard* sb = Instance();

    if (sb->time > 0)
    {
        sb->score += val;
        if (val > 0)
        {
            Trace::out("\n+%i (%i)", val, sb->score);
        }
        else
        {
            Trace::out("\n%i (%i)", val, sb->score);
        }
    }
}

void Scoreboard::Start()
{
    Instance()->time = 30.0f;
    Trace::out("\n**%i**", (int)ceil(Instance()->time));
}

void Scoreboard::Update(float elapsedTime)
{
    Scoreboard* sb = Instance();

    if (sb->time > 0)
    {
        float was = ceil(sb->time);
        sb->time -= elapsedTime;
        float is = ceil(sb->time);

        if (is == 0)
        {
            Trace::out("\n**DONE**");
            Trace::out("\nFinal Score: %i", sb->score);
            sb->pLauncher->StopLaunching();
        }
        else if (was != is)
        {
            Trace::out("\n**%i**", (int)is);
        }
    }
}
