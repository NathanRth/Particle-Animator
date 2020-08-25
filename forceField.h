#ifndef FORCE_FIELD_H
#define FORCE_FIELD_H

#include "vector.h"
#include "particle.h"

class ForceField
{
public:
    ForceField() : strength(1.0) {}
    ForceField(float s) : strength(s) {}
    virtual ~ForceField() = default;
    virtual Vector force(const Particle &p) const = 0;

    float strength;
};

#endif