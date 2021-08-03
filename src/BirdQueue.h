#ifndef BIRD_QUEUE_H
#define BIRD_QUEUE_H

#include "BirdsPigsHeader.h"
#include "BirdLink.h"

class PhysicsWorld;

class BirdQueue
{
public:

	BirdQueue(int capacity, float qFrontX, float qFrontY, PhysicsWorld* pWorld);
	~BirdQueue();

	void Reload();
	void Push(RedBird* pBird);
	RedBird* Pop();

private:

	void AdvanceQueue();

private:
	BirdLink* pHead;
	PhysicsWorld* pWorld;

	int capacity;
	int size;
	float qFrontX;
	float qFrontY;

};

#endif