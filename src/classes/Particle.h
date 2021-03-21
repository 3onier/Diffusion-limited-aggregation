#ifndef DLA_PARTICLE_H
#define DLA_PARTICLE_H

#include "../utils/Random.h"
#include <math.h>

class Particle {
public:
    int x; ///< x-position of the particle
    int y; ///< y-position of the particle

    int minX = 0; ///< the minimum x-position a particle can be
    int minY = 0; ///< the minimum y-position a particle can be
    int maxX = 0; ///< the maximum x-position a particle can be
    int maxY = 0; ///< the maximum y-position a particle can be

    int midX = 0;
    int midY = 0;
    int borderRadius = 0;

    bool isFixed = false; ///< flag weather particle is a fixed or not

    unsigned long int moves = 0; ///< amount of moves the particle made

    Particle();
    Particle(int x, int y, int upperWidth, int upperHeight);

    void setRectBoundaries(int minX, int minY, int maxX, int maxY);

    void setCircBoundaries(int midX, int midY, int radius);

    /// @description sets the particle to fixed
    void fix();
    /// @description sets the particle to unfixed
    void unfix();

    /// @description moves the partical random and according to the forces
    void move();

    /// @description sets the position of the particle
    void setPosition(int x, int y);
    /// @description sets the x-position
    void setX(int x);
    /// @description sets the y-position
    void setY(int y);

    /// @description Gets the x-position of the Particle
    /// @returns x-position
    int getX();
    /// @description Gets the y-position of the Particle
    /// @returns y-position
    int getY();

    int getUpperWidth() const;

    int getUpperHeight() const;

    void setUpperHeight(int upperHeight);

    void setUpperWidth(int upperWidth);

};


#endif //DLA_PARTICLE_H