#ifndef DRAG_H
#define DRAG_H

#include "vector.h"
#include "forceField.h"

// Add aerodynamic drag to the physic system
class Drag : public ForceField
{
public:
    Drag() : ForceField() {}

    Drag(float mu) : ForceField(mu) {}

    Vector force(const Particle &p) const override
    {
        return -p.speed * strength;
    }
};

#endif