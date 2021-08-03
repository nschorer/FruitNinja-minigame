#ifndef IMAGE_NAME
#define IMAGE_NAME


#include "EnumBase.h"

struct ImageName : public EnumBase
{
	ImageName(ImageName::Name n)
	{
		this->value = n;
	}

	enum Name
	{
		Root = 0x30000,

		Alien_Blue,
		Alien_Green,
		Alien_Red,
		Stitch,

		Bird_Red_0,
		Bird_Red_1,
		Bird_Red_2,
		Bird_Red_3,
		Bird_Red_4,

		Bird_Yellow_0,
		Bird_Yellow_1,
		Bird_Yellow_2,
		Bird_Yellow_3,
		Bird_Yellow_4,
		Bird_Yellow_5,

		Bird_Black_0,
		Bird_Black_1,
		Bird_Black_2,
		Bird_Black_3,
		Bird_Black_4,
		Bird_Black_5,
		Bird_Black_6,

		Bird_White_0,
		Bird_White_1,
		Bird_White_2,
		Bird_White_3,
		Bird_White_4,
		Bird_White_5,

		Bird_Green_0,
		Bird_Green_1,
		Bird_Green_2,
		Bird_Green_3,
		Bird_Green_4,

		Bird_Blue_0,
		Bird_Blue_1,
		Bird_Blue_2,
		Bird_Blue_3,

		Bird_Big_0,
		Bird_Big_1,
		Bird_Big_2,

		Pig_Big_0,
		Pig_Big_1,

		Pig_Medium_0,
		Pig_Medium_1,

		Pig_Small_0,
		Pig_Small_1,

		Pig_King_0,
		Pig_King_1,
		Pig_King_2,
		Pig_King_3,
		Pig_King_4,
		Pig_King_5,
		Pig_King_6,
		Pig_King_7,
		Pig_King_8,

		Pig_Mustache_0,
		Pig_Mustache_1,
		Pig_Mustache_2,
		Pig_Mustache_3,
		Pig_Mustache_4,
		Pig_Mustache_5,
		Pig_Mustache_6,
		Pig_Mustache_7,
		Pig_Mustache_8,

		Wood_Platform,

		Wood_Plat_Long_0,
		Wood_Plat_Long_1,
		Wood_Plat_Long_2,
		Wood_Plat_Long_3,

		Wood_Plat_Medium_0,
		Wood_Plat_Medium_1,
		Wood_Plat_Medium_2,
		Wood_Plat_Medium_3,

		Wood_Plat_Short_0,
		Wood_Plat_Short_1,
		Wood_Plat_Short_2,
		Wood_Plat_Short_3,

		Wood_Plat_Tiny_0,
		Wood_Plat_Tiny_1,
		Wood_Plat_Tiny_2,
		Wood_Plat_Tiny_3,

		Wood_Rect_0,
		Wood_Rect_1,
		Wood_Rect_2,
		Wood_Rect_3,

		Wood_Square_0,
		Wood_Square_1,
		Wood_Square_2,
		Wood_Square_3,

		Wood_Circle_Big_0,

		Glass_Plat_Long_0,
		Glass_Plat_Long_1,
		Glass_Plat_Long_2,
		Glass_Plat_Long_3,

		Glass_Plat_Medium_0,
		Glass_Plat_Medium_1,
		Glass_Plat_Medium_2,
		Glass_Plat_Medium_3,

		Glass_Plat_Short_0,
		Glass_Plat_Short_1,
		Glass_Plat_Short_2,
		Glass_Plat_Short_3,

		Glass_Plat_Tiny_0,
		Glass_Plat_Tiny_1,
		Glass_Plat_Tiny_2,
		Glass_Plat_Tiny_3,

		Glass_Rect_0,
		Glass_Rect_1,
		Glass_Rect_2,
		Glass_Rect_3,
		
		Glass_Square_0,
		Glass_Square_1,
		Glass_Square_2,
		Glass_Square_3,

		Stone_Plat_Long_0,
		Stone_Plat_Long_1,
		Stone_Plat_Long_2,
		Stone_Plat_Long_3,
		
		Stone_Plat_Medium_0,
		Stone_Plat_Medium_1,
		Stone_Plat_Medium_2,
		Stone_Plat_Medium_3,
		
		Stone_Plat_Short_0,
		Stone_Plat_Short_1,
		Stone_Plat_Short_2,
		Stone_Plat_Short_3,
		
		Stone_Plat_Tiny_0,
		Stone_Plat_Tiny_1,
		Stone_Plat_Tiny_2,
		Stone_Plat_Tiny_3,
		
		Stone_Rect_0,
		Stone_Rect_1,
		Stone_Rect_2,
		Stone_Rect_3,
		
		Stone_Square_0,
		Stone_Square_1,
		Stone_Square_2,
		Stone_Square_3,

		Bang,
		Sling,
			Sling_Tree,
			Sling_Branch,

		BG_0,

		Null,
		Not_Initialized,
	};
};

#endif