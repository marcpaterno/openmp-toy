# openmp-toy

Toy programs using OpenMP, to demonstrate how to build OpenMP programs.

## Recommended build

We use *CMake*. Get a modern version!
To set up the build, use:

    mkdir build
    cd build
    cmake -DCMAKE_BUILD_TYPE=Release ../

I often prefer to use the Ninja generator; to use this, the last line should be:

    cmake -DCMAKE_BUILD_TYPE=Release -G Ninja ../


