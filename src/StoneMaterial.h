#ifndef STONE_MATERIAL_H
#define STONE_MATERIAL_H

#include "PhysicsMaterial.h"

class StoneMaterial : public PhysicsMaterial
{
public:
	StoneMaterial() = default;
	virtual ~StoneMaterial() = default;

	const virtual float Density()  final { return 2.5f; }
	const virtual float Friction()  final { return 0.8f; }
	const virtual float Restitution()  final { return 0.1f; }
	const virtual float Health()  final { return 200.0f; }

	static StoneMaterial* Instance();
};

#endif