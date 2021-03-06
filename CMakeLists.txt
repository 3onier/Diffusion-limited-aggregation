cmake_minimum_required(VERSION 3.17)
project(DLA)

set(CMAKE_CXX_STANDARD 14)

add_executable(DLA src/main.cpp src/classes/PetriDish.h src/classes/PetriDish.cpp src/classes/Particle.h src/classes/Particle.cpp src/utils/Random.cpp src/utils/Random.h)
#add_subdirectory(classes)