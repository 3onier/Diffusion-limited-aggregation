#include "Particle.h"

Particle::Particle() {
    this->x = 0;
    this->y = 0;
}

Particle::Particle(int x, int y,int upperWidth,int upperHeight) {
    this->x = x;
    this->y = y;
    this->upperHeight = upperHeight;
    this->upperWidth = upperWidth;
}

void Particle::setBoundaries(int width, int height) {
    this->upperWidth = width;
    this->upperHeight = height;
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

    //check and reset to boundaries
    if(tempX < 0){
        this->setX(0);
    }else if(tempX > this->getUpperWidth()){
        this->setX(this->getUpperWidth());
    } else{
        this->setX(tempX);
    }

    if(tempY < 0){
        this->setY(0);
    }else if(tempY > this->getUpperHeight()){
        this->setY(this->getUpperHeight());
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
    return upperWidth;
}

int Particle::getUpperHeight() const {
    return upperHeight;
}

void Particle::setUpperHeight(int upperHeight) {
    Particle::upperHeight = upperHeight;
}

void Particle::setUpperWidth(int upperWidth) {
    Particle::upperWidth = upperWidth;
}
