#include <iostream>
#include <memory>

#include "scene.h"
#include "particleSystem.h"
#include "forceField.h"
#include "gravity.h"
#include "random.h"
#include "drag.h"

/* Args:
 * 1: number of particles
 * 2: timestep
 * 3: number of frames
 * 4: output filename
 */
int main(int argc, char const *argv[])
{
    if(argc != 5)
    {
        return EXIT_FAILURE;
    }

    unsigned int nbParticles    = static_cast<unsigned int>(std::atol(argv[1]));
    float timeStep              = std::atof(argv[2]);
    unsigned int nbFrames       = static_cast<unsigned int>(std::atol(argv[3]));
    std::string fileName        = argv[4];

    Scene scene(nbFrames,timeStep,fileName);
    
    auto system = std::make_shared<ParticleSystem>(nbParticles);

    system->spawnParticles([&](std::size_t i)
    {
        Particle p;
        p.position = Vector(uniform_float(),uniform_float(),uniform_float());
        std::cout << p.position << std::endl;
        p.mass = uniform_float();
        p.speed = Vector(0,0,0);
        return p;
    });

    scene.setParticleSystem(system);
    scene.addForceField(std::make_shared<Gravity>(Gravity()));
    scene.addForceField(std::make_shared<Drag>(Drag(1.0)));
    scene.exportAnimation();

    return 0;
}
