#ifndef WIND_H
#define WIND_H

#include "vector.h"
#include "forceField.h"
#include "particle.h"

enum Shape
{
    Square,
    Circle
};

// A constant force
class Wind : public ForceField
{
public:
    Wind(float s = 1.0) : ForceField(s), direction(1,0,0), origin(), size(10.0) {}
    Wind(const Vector &dir, float s) : ForceField(s), direction(dir), origin(), size(10.0) {};

    Vector force(const Particle &p) const override
    {
        return direction.normalized() * strength;
    }

    Vector direction;
    Vector origin;
    float size;
};

#endif