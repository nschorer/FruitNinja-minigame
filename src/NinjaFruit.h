#ifndef NINJA_FRUIT_H
#define NINJA_FRUIT_H

#include "PhysicsObject2D.h"

enum class Fruit
{
	Apple,
	Orange
};

class NinjaFruit : public PhysicsObject2D
{
public:
	NinjaFruit(GameObjectName::Name name, float x, float y, float radius, int score, ImageName::Name _imgNames[3], PhysicsWorld* pWorld);
	virtual ~NinjaFruit() = default;

	virtual void OnCut();

	b2Vec2 point;
	b2Vec2 normal;

private:
	ImageName::Name* imgNames;
	float radius;

protected:
	int score;

private:
	static PhysicsFixture fixture;
};

#endif