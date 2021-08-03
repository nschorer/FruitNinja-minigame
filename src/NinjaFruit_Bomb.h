#ifndef NINJA_FRUIT_BOMB_H
#define NINJA_FRUIT_BOMB_H

#include "NinjaFruit.h"

class PhysicsWorld;

class NinjaFruit_Bomb : public NinjaFruit
{
public:
	NinjaFruit_Bomb(float x, float y, PhysicsWorld* pWorld);
	virtual ~NinjaFruit_Bomb() = default;

	void OnCut() override;

private:
	static ImageName::Name imgNames[2];
	static float radius;
};

#endif