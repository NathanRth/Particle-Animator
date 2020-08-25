#ifndef FORCE_H
#define FORCE_H

#include "forceField.h"
#include "vector.h"

enum ForceType
{
    Constant,
    InverseLinear,
    InverseSquare
};

class Force : public ForceField
{
public:
    Force();
    Force(Vector p, float s = 1.0, ForceType t = ForceType::Constant);

    Vector force(const Particle &p) const override;

public:
    Vector position;
    ForceType type;
};

Force::Force() : ForceField(), position(), type(ForceType::Constant) {}
Force::Force(Vector p, float s, ForceType t) : ForceField(s), position(p), type(t) {}

Vector Force::force(const Particle &p) const
{
    Vector direction = (p.position - position).normalized();
    switch (type)
    {
    case Constant:
        return direction * strength;
    case InverseLinear:
        float d = distance(p.position, position);
        return strength * direction/d;
    case InverseSquare:
        float d = distance2(p.position, position);
        return strength * direction/d;
    default:
        break;
    }
}

#endif