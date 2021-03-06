#include <iostream>
#include "classes/PetriDish.h"
#include "utils/Random.h"


int main(int argc, char** argv) {
    //check if enough arguments have been given
    if(argc != 8){
        std::cout << "DLA [amount] [height] [width] [collision radius] [init x] [init y] [seed]" << std::endl;
        return 0;
    }
    Random::init(atoi(argv[7]));
    PetriDish test = PetriDish(
            atoi(argv[1]),
            atoi(argv[2]),
            atoi(argv[3]),
            strtod(argv[4],NULL),
            atoi(argv[5]),
            atoi(argv[6])
            );
    test.runAll();
    test.printParticleByPos();
    return 0;
}
