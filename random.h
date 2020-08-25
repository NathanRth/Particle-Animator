#ifndef RANDOM_H
#define RANDOM_H

#include <random>

std::random_device rd;

std::mt19937 e2(rd());

//
// Distribtuions
//
std::uniform_real_distribution<> dist(0,1.0);

float uniform_float()
{
    return dist(e2);
}

#endif