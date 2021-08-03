#ifndef SCOREBOARD_H
#define SCOREBOARD_H

class NinjaLauncher;

class Scoreboard
{
public:
	static void Setup(NinjaLauncher* pLauncher);
	static Scoreboard* Instance();
	static void ChangeScore(int val);
	static void Start();
	static void Update(float elapsedTime);

private:
	NinjaLauncher* pLauncher;
	int score;
	float time;
};

#endif