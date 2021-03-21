
#ifndef DLA_PETRIDISH_H
#define DLA_PETRIDISH_H

#include<iostream>
#include "Particle.h"

#define BORDER_PADDING 1

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

    // dynamic boundary
    int dynMinX = 0;
    int dynMaxX = 0;
    int dynMinY = 0;
    int dynMaxY = 0;

    // dynamic boundaries
    int midX = 0;
    int midY = 0;
    int borderRadius = 0;

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
    void runAll(bool print = false);

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

    /// @description Sets particle boundaries for optimization
    void setParticleBoundaries(Particle* part);

    void generateDynamicBoundaries();

    void updateDynamicBoundaries(Particle* part);

};

#endif //DLA_PETRIDISH_H
