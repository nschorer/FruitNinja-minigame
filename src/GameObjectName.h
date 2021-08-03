#ifndef GAME_OBJECT_NAME
#define GAME_OBJECT_NAME

#include "EnumBase.h"

struct GameObjectName : public EnumBase
{
	GameObjectName(GameObjectName::Name n)
	{
		this->value = n;
	}

	enum Name
	{
		Root = 0x70000,

		// Sort Buckets
		MainGroup,
		Effects,
		Background,
		Sling_Back,
		Sling_Handle_Back,
		Sling_Front,
		Slong_Handle_Front,

		// Demos
		Stitch,
		Alien,
		Lander,

		// AngryBirds
		Bird_Red,
		Bird_Yellow,
		Bird_Black,
		Bird_White,
		Bird_Green,
		Bird_Blue,
		Bird_Big,

		Pig_Big,
		Pig_Medium,
		Pig_Small,
		Pig_King,
		Pig_Mustache,

		WoodPlatform,

		Wood_Plat_Long,
		Wood_Plat_Medium,
		Wood_Plat_Short,
		Wood_Plat_Tiny,

		Wood_Square,
		Wood_Rect,
		Wood_Circle,
		
		Glass_Plat_Long,
		Glass_Plat_Medium,
		Glass_Plat_Short,
		Glass_Plat_Tiny,
		
		Glass_Square,
		Glass_Rect,

		Stone_Plat_Long,
		Stone_Plat_Medium,
		Stone_Plat_Short,
		Stone_Plat_Tiny,

		Stone_Square,
		Stone_Rect,

		Wood_Tower,

		Sling,
		Sling_Tree,
		Sling_Branch,
		Slingshot,

		Bang,
		Floor,

		NOT_INITIALIZED
	};
};

#endif