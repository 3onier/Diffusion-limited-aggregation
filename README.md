#  Diffusion-limited-aggregation
## Description

This is a simulation for a process called [DLA](https://en.wikipedia.org/wiki/Diffusion-limited_aggregation)
I created with a friend for my University.

## Prerequisites

- [CMake](https://cmake.org/) >= v3.17
- [Python]() >= 3.9.2
- [Pipenv](https://pypi.org/project/pipenv/)
- [matplotlib](https://matplotlib.org/) >= 3.3.4 (optional if you dont have pipenv)

## Installation

### Linux
````
# get git repository
git clone https://github.com/3onier/Diffusion-limited-aggregation

# change directory
cd Diffusion-limited-aggregation

# create make file
cmake .

# build project
make 

# generate python virtual environment
pipenv install
````

### Windows

Work in Progress

### Mac

Work in Progress

## Usage

````
./DLA [amount] [heigt] [width] [collision radius] [init x] [init y] [seed] | python renderer.py
````