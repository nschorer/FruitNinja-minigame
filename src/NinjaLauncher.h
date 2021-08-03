#ifndef NINJA_LAUNCHER_H
#define NINJA_LAUNCHER_H

class PhysicsWorld;

class NinjaLauncher
{
public:

	enum class Difficulty {
		NORMAL,
		HARD
	};

	NinjaLauncher(float x, float y, float radius, PhysicsWorld* pWorld);

	void StartLaunching(Difficulty d);
	void StopLaunching();

private:
	void LaunchRandomFruit();

	float x;
	float y;
	float radius;
	PhysicsWorld* pWorld;
	Difficulty diff;
	bool active;
};

#endif