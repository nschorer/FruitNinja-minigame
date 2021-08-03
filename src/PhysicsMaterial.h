#ifndef PHYSICS_MATERIAL_H
#define PHYSICS_MATERIAL_H

class PhysicsMaterial
{
public:

	virtual ~PhysicsMaterial() = default;

	const virtual float Density() = 0;
	const virtual float Friction() = 0;
	const virtual float Restitution() = 0;
	const virtual float Health() = 0;

protected:
	PhysicsMaterial() = default;
};

#endif