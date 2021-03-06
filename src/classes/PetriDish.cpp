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
        this->particles[i].setRectBoundaries(0, 0, this->width, this->height);
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

    //generate dynamic boundaries
    this->generateDynamicBoundaries();
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
    for (int i = 0; i < this->getFixedIndex(); ++i) {
        std::cout << this->particles[i].x << " " << this->particles[i].y << std::endl;
    }
}

void PetriDish::runSingle(int index) {
    //create pointer for particle for easier reading
    Particle* part = &this->particles[index];
    //give Random Position
    part->setPosition(Random::randInt(0, this->width),Random::randInt(0, this->height));
    this->setParticleBoundaries(part);
    while(true) {
        part->move();
        //std::cout << part->getX() << " " << part->getY() << std::endl;
        if(this->isCollision(particles[index])){
            part->fix();
            this->addFixedIndex();
            //save index
            this->pParticleByPos[part->getY()*this->width + part->getX()] = &this->particles[index];
            this->updateDynamicBoundaries(part);
            return;
        }
    }
}

void PetriDish::runAll(bool print) {
    if(print){
        for (int i = 0; i < this->getFixedIndex(); ++i) {
            std::cout << i << " " << this->particles[i].getX() << " " << this->particles[i].getY() <<
            " " << this->particles[i].moves << std::endl;
        }
    }
    for (int i = this->getFixedIndex(); i < this->amount; i++) {
        this->runSingle(i);
        if(print){
            std::cout << i << " " << this->particles[i].getX() << " "
            << this->particles[i].getY() << " " << this->particles[i].moves << std::endl;
        }
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
    //check if particle is in another. if yes early return false
    int index = a.y * this->width + a.x;
    if(this->pParticleByPos[index] != nullptr){
        return false;
    }
    double distance = 0;
    int add = static_cast<int>(ceil(collisionRadius)+2);
    int minX = (a.x - add > 0) ? a.x - add : 0;
    int minY = (a.y - add > 0) ? a.y - add : 0;
    int maxX = (a.x + add < this->width) ? a.x + add : this->width;
    int maxY = (a.y + add < this->height) ? a.y + add : this->height;
    for (int x = minX; x <= maxX; ++x) {
        for (int y = minY; y <= maxY; ++y) {
            // test if max size isn't exceeded
            if(this->width*y + x >= this->width*this->height){
                break;
            }
            if(this->pParticleByPos[this->width*y + x] != nullptr){
                b = this->pParticleByPos[this->width*y + x];
                distance = sqrt(pow(b->x - a.x, 2) + pow(b->y - a.y, 2));
                if(distance <= this->collisionRadius){
                    return true;
                }
            }
        }
    }
    return false;
}

void PetriDish::setParticleBoundaries(Particle *part) {
    part->setRectBoundaries(0, 0, this->width, this->height);
    part->setCircBoundaries(
            this->midX,
            this->midY,
            this->borderRadius
            );
}

void PetriDish::generateDynamicBoundaries() {
    int maxX = 0;
    int maxY = 0;
    int minX = this->width;
    int minY = this->height;
    int avgX = 0;
    int avgY = 0;

    // get minimum and maximum of each coordinate and sum up for averaging
    for (int i = 0; i < this->getFixedIndex(); ++i) {
        maxX = std::max(maxX, this->particles[i].x);
        maxY = std::max(maxY, this->particles[i].y);
        minX = std::min(minX, this->particles[i].x);
        minY = std::min(minY, this->particles[i].y);
        avgX += this->particles[i].x;
        avgY += this->particles[i].y;
    }

    // get average
    avgX /= getFixedIndex();
    avgY /= getFixedIndex();

    // get furthest particle from average point
    int x = std::max(
            std::abs(avgX - maxX),
            std::abs(avgX - minX)
            );
    // get furthest particle from average point
    int y = std::max(
            std::abs(avgY - maxY),
            std::abs(avgY - minY)
    );

    int radius = static_cast<int>(ceil(sqrt(x*x + y*y))) + BORDER_PADDING;

    this->borderRadius = radius;
    this->midX = avgX;
    this->midY = avgY;
}

void PetriDish::updateDynamicBoundaries(Particle *part) {
    int x = abs(this->midX - part->x);
    int y = abs(this->midY - part->y);

    this->borderRadius = std::max(
            this->borderRadius - BORDER_PADDING,
            static_cast<int>(ceil(sqrt(x*x + y*y)))
            ) + BORDER_PADDING;
}
