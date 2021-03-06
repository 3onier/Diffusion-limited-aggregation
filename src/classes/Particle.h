#ifndef DLA_PARTICLE_H
#define DLA_PARTICLE_H

#include "../../utils/Random.h"

class Particle {
public:
    int x; ///< x-position of the particle
    int y; ///< y-position of the particle

    int upperWidth = 0; ///< the maximum x-position a particle can move to
    int upperHeight = 0; ///< the maximum y-position a particle can move to

    bool isFixed = false; ///< flag weather particle is a fixed or not

    Particle();
    Particle(int x, int y, int upperWidth, int upperHeight);

    void setBoundaries(int width, int height);

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