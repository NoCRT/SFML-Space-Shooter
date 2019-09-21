#ifndef FILES_GENERIC_INCLUDE_H
#define FILES_GENERIC_INCLUDE_H

// generic include file used for classes

// default 1250
// changes how quickly asteroids can spawn
#define DEF_ASTEROID_SPAWN_TIMER 1250

// default 100
// timer * amount allowed to spawn * speed
// changes how laser works. shorter value = burst fire : higher value = singular shots
#define DEF_LASER_SPAWN_TIMER 100

// template macro that defines type as T
#define DT template <typename T, typename P> 

// sfml includes
#include "sfml/Graphics.hpp"
#include "sfml/Audio.hpp"
#include "sfml/System.hpp"

// std includes
#include <vector>
#include <string>
#include <random>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <random>
#include <functional>
#include <cfloat>

// assett locations
const static std::string
    SOUND_LASER{"Sounds/laser-shot.wav"},
    SOUND_LASER_BOUNDS{"Sounds/live-impact.wav"},
    MUSIC_SPACE{"Music/space-background.wav"},
    SOUND_ASTEROID{"Sounds/asteroid-impact.wav"},
    IMAGE_SHIP{"Images/ship.png"},
    IMAGE_ASTEROID{"Images/asteroid.png"},
    IMAGE_SPACE{"Images/space.png"},
    IMAGE_LASER{"Images/laser.png"},
    FONT_GEOSANS{"Fonts/GeosansLight.ttf"};

static unsigned int winWidth{1024};
static unsigned int winHeight{768};

// functions that would be useful for most classes
// Link = https://stackoverflow.com/questions/12657962/how-do-i-generate-a-random-number-between-two-variables-that-i-have-stored
static inline int CreateRandom(int min, int max)
{
    int n = max - min + 1;
    int remainder = RAND_MAX % n;
    int x;
    do
    {
        x = rand();
    } while (x >= RAND_MAX - remainder);
    return min + x % n;
}

static inline auto CreateRandomNew(int min, int max)
{
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(min, std::nextafter(max, DBL_MAX));
    return dist(mt);
}

static inline void PRINT(std::string inpStr)
{ // macro for printing to debug console
    std::cout << inpStr << "\n";
}

#endif //FILES_GENERIC_INCLUDE_H