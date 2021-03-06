
#ifndef DLA_PETRIDISH_H
#define DLA_PETRIDISH_H

#include<iostream>
#include<math.h>
#include "Particle.h"

/// @description Class containing the Particles and running the simulation
class PetriDish {
public:
    int amount; ///< Amount of Particles to be simulated
    Particle* particles;///< array of the particles that already have been fixed at a point

    Particle** pParticleByPos;

    int collisionSquareSideLen = 0; ///< side length of the square estimating possible collisions

    int fixedIndex = 0; ///< index of last fixed particle, since we through them in order, so we ignore some iterations

    int width; ///< width of the grid
    int height; ///< height of the grid
    float collisionRadius; ///< the minimum distance for a collision

    PetriDish(int amount, ///< Amount of Particles to be simulated
              int height, ///< height of the grid
              int width, ///< width of the grid
              double collisionRadius, ///< the minimum distance for a collision
              int initX, ///< x-position of the initial particle
              int initY ///< y-position of the initial particle
              );

    /// @description runs the simulation for a single particle until it has been fixed
    void runSingle(
            int index ///< index of the particle to be simulated
            );

    /// @description runs the simulation for all Particles
    void runAll();

    /// @description deletes all allocated memory
    void cleanup();

    /// @description Prints postion of all fixed particles
    void debugPrintFixed();

    /// @description Checks if there is a collision with another particle
    /// @returns true when there is a collision
    bool isCollision(Particle a) const;

    int getFixedIndex() const;

    void setFixedIndex(int fixedIndex);

    void addFixedIndex();

    void printParticleByPos();

    /// @description map all positions in the square to the corresponding particle for collision detection optimization
    void fillCollisionSquare(int x, int y);

};

#endif //DLA_PETRIDISH_H