#ifndef DLA_RANDOM_H
#define DLA_RANDOM_H

#include <random>
#include <math.h>

namespace Random{
    static std::default_random_engine gen;
    static std::uniform_int_distribution<int> dist(0,std::numeric_limits<int>::max());

    void init(int seed);
    int randInt(int min, int max);

}

#endif //DLA_RANDOM_H
