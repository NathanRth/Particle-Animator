#ifndef PARTICLE_SYSTEM_H
#define PARTICLE_SYSTEM_H

#include <forward_list>
#include <memory>
#include <functional>
#include "particle.h"

// A collection of particles
class ParticleSystem
{
public:
    explicit ParticleSystem(std::size_t number);

    // describe how particules are instanciated in the world
    void spawnParticles(std::function<Particle(std::size_t)> func);

    // compute the movement of the particles over <timeStep>
    void animate(std::vector<std::shared_ptr<ForceField>> &ffs, float timeStep);
    
    std::vector<Particle> particles;
    bool randomWeight;
    float minWeight, maxWeight;
};

ParticleSystem::ParticleSystem(std::size_t number) : particles(number), randomWeight(false), minWeight(1.0), maxWeight(1.0) {}

void ParticleSystem::spawnParticles(std::function<Particle(std::size_t)> func)
{
    for(std::size_t i = 0; i < particles.size(); i++)
    {
        particles.at(i) = func(i);
    }
}

void ParticleSystem::animate(std::vector<std::shared_ptr<ForceField>> &ffs, float timeStep)
{
#pragma omp parallel for
    for(std::size_t i = 0; i < particles.size() ; i++)
    {
        for(auto ff : ffs)
        {
            particles.at(i).applyForce(ff->force(particles.at(i)));
        }
        particles.at(i).update(timeStep);
    }
}

#endif