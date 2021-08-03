#ifndef TEXTURE_NAME
#define TEXTURE_NAME

#include "EnumBase.h"

struct TextName : public EnumBase
{
	TextName(TextName::Name n)
	{
		this->value = n;
	}

	enum Name
	{
		Root = 0x40000,

		Invaders,
		Stitch,
		AngryBackground,
		GlassBlocks,
		SlingV2,
		StoneBlocks,
		WoodBlocks,
		WoodPlatform,
		BirdPigsEffects,

		Not_initialized
	};
};
#endif
