#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <string>
#include <memory>
#include <fstream>

#include "forceField.h"
#include "particleSystem.h"

class Scene
{
public:
    Scene(unsigned int nbf, float ts, std::string fname) : nbFrames(nbf), timeStep(ts), filename(fname) {}

    void exportAnimation()
    {
        outfile.open(filename);
        outfile << "#PV==" << std::endl;
        outfile << timeStep << std::endl;
        outfile << particleSystem->particles.size() << std::endl;
        outfile << nbFrames << std::endl;

        outfile << "point 0:" << particleSystem->particles.size()-1 << std::endl;
        outfile << "===" << std::endl;

        for(Particle p : particleSystem->particles)
        {
            outfile << p.position << std::endl;
        }

        for(unsigned int f = 0 ; f < nbFrames ; f++)
        {
            particleSystem->animate(forceFileds, timeStep);
            for(Particle p : particleSystem->particles)
            {
                outfile << p.position << std::endl;
            }
        }
        outfile.close();
    }

    void setParticleSystem(std::shared_ptr<ParticleSystem> ps)
    {
        particleSystem = ps;
    }

    void addForceField(std::shared_ptr<ForceField> ff)
    {
        forceFileds.push_back(ff);
    }
private:
    std::shared_ptr<ParticleSystem> particleSystem;
    std::vector<std::shared_ptr<ForceField>> forceFileds;
    unsigned int nbFrames;
    float timeStep;
    std::string filename;
    std::ofstream outfile;
};

#endif