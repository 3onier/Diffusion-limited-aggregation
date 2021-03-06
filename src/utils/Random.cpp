#include "Random.h"


int Random::randInt(int min, int max) {
    return Random::dist(Random::gen) % (max - min + 1) + min;
}

void Random::init(int seed) {
    Random::gen.seed(seed);
}

