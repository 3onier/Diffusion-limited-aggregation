#include "Particle.h"

Particle::Particle() {
    this->x = 0;
    this->y = 0;
}

Particle::Particle(int x, int y,int upperWidth,int upperHeight) {
    this->x = x;
    this->y = y;
    this->maxY = upperHeight;
    this->maxX = upperWidth;
}

void Particle::setRectBoundaries(int minX, int minY, int maxX, int maxY){
    this->maxX = maxX;
    this->maxY = maxY;
    this->minX = minX;
    this->minY = minY;
}

void Particle::setCircBoundaries(int midX, int midY, int radius) {
    this->midX = midX;
    this->midY = midY;
    this->borderRadius = radius;
}

void Particle::fix() {
    this->isFixed = true;
}

void Particle::unfix() {
    this->isFixed = false;
}

void Particle::move() {
    //save the new position temporarily
    long int tempX = this->getX() + Random::randInt(-1,1);
    long int tempY = this->getY() + Random::randInt(-1,1);

    // calculate distance and angle
    double distance = sqrt(pow(tempY - this->midY, 2) + pow(tempX - this->midX, 2));
    double angle = atan2(
            tempX - this->midX,
            tempY - this->midY
            );

    if(distance > this->borderRadius){
        tempX = static_cast<int>(this->borderRadius*cos(angle)) + this->midX;
        tempY = static_cast<int>(this->borderRadius*sin(angle)) + this->midY;
    }

    //check and reset to rectangular boundaries
    if(tempX < this->minX){
        this->setX(minX);
    }else if(tempX > this->maxX){
        this->setX(this->maxX);
    } else{
        this->setX(tempX);
    }

    if(tempY < this->minY){
        this->setY(minY);
    }else if(tempY > this->maxY){
        this->setY(this->maxY);
    } else{
        this->setY(tempY);
    }

}

void Particle::setPosition(int x,int y) {
    this->x = x;
    this->y = y;
}

void Particle::setX(int x) {
    this->x = x;
}

void Particle::setY(int y) {
    this->y = y;
}

int Particle::getX() {
    return this->x;
}

int Particle::getY() {
    return this->y;
}

int Particle::getUpperWidth() const {
    return maxX;
}

int Particle::getUpperHeight() const {
    return maxY;
}

void Particle::setUpperHeight(int upperHeight) {
    Particle::maxY = upperHeight;
}

void Particle::setUpperWidth(int upperWidth) {
    Particle::maxX = upperWidth;
}
