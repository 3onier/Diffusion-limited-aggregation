cmake_minimum_required(VERSION 3.17)
project(DLA)

set(CMAKE_CXX_STANDARD 14)

add_executable(DLA main.cpp classes/PetriDish.h classes/PetriDish.cpp classes/Particle.h classes/Particle.cpp utils/Random.cpp utils/Random.h)
#add_subdirectory(classes)