#ifndef BIRD_LINK_H
#define BIRD_LINK_H

#include "BirdsPigsHeader.h"

class BirdLink
{
public:
	BirdLink(RedBird* pBird);

	BirdLink* pPrev;
	BirdLink* pNext;
	RedBird* pBird;
};

#endif