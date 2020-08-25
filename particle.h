#ifndef PARTICLE_H
#define PARTICLE_H

#include "vector.h"

// An abstract object in space
class Particle
{
public:
    Particle();

    void applyForce(const Vector &force);
    void update(float t);

    Vector position;
    Vector speed;
    float size;
    float mass;
    unsigned int age;
private:
    Vector sumForce;
};

Particle::Particle() : position(), speed(), size(0.1), mass(1.0), age(0), sumForce() {}

void Particle::applyForce(const Vector &force)
{
    sumForce += force;
}

void Particle::update(float t)
{
    Vector Ftm = (sumForce*t)/mass;

    position = position + speed*t + Ftm * t;
    speed = speed + Ftm;
    sumForce = Vector(0,0,0);

    age++;
}

#endif // PARTICLE_H