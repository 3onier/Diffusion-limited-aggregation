#include "PetriDish.h"

PetriDish::PetriDish(int amount,
                     int height,
                     int width,
                     double collisionRadius,
                     int initX,
                     int initY
                     ) {
    this->amount = amount;
    this->height = height;
    this->width = width;
    this->collisionRadius = collisionRadius;

    this->particles = new Particle[this->amount];

    //Set boundaries of all particles to the boundaries of petri dish
    for(int i = 0; i < this->amount; i++){
        this->particles[i].setBoundaries(this->width, this->height);
    }

    //index of particle by position
    this->pParticleByPos = reinterpret_cast<Particle **>(new Particle[width * height]);
    for (int i = 0; i < width*height; ++i) {
        this->pParticleByPos[i] = nullptr;
    }

    //create initial fixed Particle
    this->particles[0] = Particle(initX, initY, this->height, this->width);
    this->particles[0].fix();
    this->pParticleByPos[initY*height + initX] = &this->particles[0];
    this->addFixedIndex();

    int collision_square_side_len = 2*static_cast<int>(ceil(collisionRadius)) + 1;
    this->collisionSquareSideLen = collision_square_side_len;
    int size = collision_square_side_len*collision_square_side_len;
}

void PetriDish::cleanup() {
    delete this->particles; //  delete the allocated memory
    delete this->pParticleByPos;
}

void PetriDish::debugPrintFixed() {
    std::cout << "Printing Fixed Particles" << std::endl;
    for(int i = 0; i< this->amount; i++){ // go though every particle
        if(this->particles[i].isFixed){ // check if its fixed
            std::cout << "i: "
                << i
                << " x: "
                << this->particles[i].getX()
                << " y: " << this->particles[i].getY()
                << std::endl;
        }
    }
}

void PetriDish::printParticleByPos() {
    std::cout << this->width << " " << this->height << " ";
    for (int i = 0; i < this->width*this->height; ++i) {
        if (this->pParticleByPos[i] == NULL){
            std::cout << "0 ";
        }else{
            std::cout << "1 ";
        }
    }
}

void PetriDish::runSingle(int index) {
    //create pointer for particle for easier reading
    Particle* part = &this->particles[index];
    //give Random Position
    part->setPosition(Random::randInt(0, this->width),Random::randInt(0, this->height));
    while(true) {
        part->move();
        //std::cout << part->getX() << " " << part->getY() << std::endl;
        if(this->isCollision(particles[index])){
            part->fix();
            this->addFixedIndex();
            //save index
            this->pParticleByPos[part->getY()*this->width + part->getX()] = &this->particles[index];
            return;
        }
    }
}

void PetriDish::runAll() {
    for (int i = this->getFixedIndex(); i < this->amount; i++) {
        this->runSingle(i);
    }
}

int PetriDish::getFixedIndex() const {
    return fixedIndex;
}

void PetriDish::setFixedIndex(int fixedIndex) {
    PetriDish::fixedIndex = fixedIndex;
}

void PetriDish::addFixedIndex() {
    this->fixedIndex++;
}

bool PetriDish::isCollision(Particle a) const {
    //set Particle
    Particle* b = nullptr;
    //check if particle is in another. if yes abort and return false
    for (int i = 0; i < this->getFixedIndex(); i++) {
        if(this->particles[i].getX() == a.getX() && this->particles[i].getY() == a.getY()){
            return false;
        }
    }
    double distance = 0;
    for (int i = 0; i < this->getFixedIndex(); i++) {
        b = &this->particles[i];
        distance = sqrt(pow(a.getX() - b->getX(), 2.0) + pow(a.getY() - b->getY(), 2.0));
        if(distance <= this->collisionRadius){
            return true;
        }
    }
    return false;
}