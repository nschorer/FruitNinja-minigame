#ifndef WOOD_MATERIAL_H
#define WOOD_MATERIAL_H

#include "PhysicsMaterial.h"

class WoodMaterial : public PhysicsMaterial
{
public:
	WoodMaterial() = default;
	virtual ~WoodMaterial() = default;

	const virtual float Density() final { return 20.0f; }
	const virtual float Friction() final { return 0.5f; }
	const virtual float Restitution() final { return 0.5f; }
	const virtual float Health() final { return 10.0f; }

	static WoodMaterial* Instance();
};

#endif