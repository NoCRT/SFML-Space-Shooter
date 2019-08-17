#ifndef FERAL_ENGINE_HELPER_FUNCTIONS_H
#define FERAL_ENGINE_HELPER_FUNCTIONS_H

// Link = https://stackoverflow.com/questions/12657962/how-do-i-generate-a-random-number-between-two-variables-that-i-have-stored

#include "GENERIC_INCLUDE.h"
#include <random>
#include <functional>

/*int CreateRandom(int min, int max) {
    int n = max - min + 1;
    int remainder = RAND_MAX % n;
    int x;
    do {
        x = rand();
    } while (x >= RAND_MAX - remainder);
    return min + x % n;
}*/

float CreateRandom(float min, float max)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<float> dist(min, max);
    return dist(mt);
}

#endif //FERAL_ENGINE_HELPER_FUNCTIONS_H
