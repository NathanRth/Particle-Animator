#ifndef GRAVITY_H
#define GRAVITY_H

#include "vector.h"
#include "forceField.h"

// add a gravity constant to the physic system
class Gravity : public ForceField
{
public:
    Gravity() : ForceField(), direction({0,-9.81,0}) {}

    Gravity(const Vector &dir) : ForceField(), direction(dir) {}

    Vector force(const Particle &p) const override
    {
        return direction * strength * p.mass;
    }

    Vector direction;
};

#endif