# Technical Task No. 1

A polyline in 3D is given by the list of nodes’ coordinates. Implement an algorithm that
searches the nearest point on the polyline to any given point. In case of multiple solutions,
output all of them.

A detailed description is available [here](docs/task.pdf).   
A detailed documentation is available [here](docs/README.md). 

This instruction was tested on Windows11, it could slightly differ for other systems.

## Setup

### Install packages
- `mingw`
- `cmake`

### Setup application

```bash
cmake -S . -B build/ -D CMAKE_BUILD_TYPE=Release -G "MinGW Makefiles"
cmake --build ./build/
```

## Usage 

### Run

```bash
./build/PolylineSolver.exe [filename] [x] [y] [z]
```

### Testing

Run the command in directory `./build/`

```bash
ctest -V
```
### Examples

```bash
./build/PolylineSolver.exe data/example1.txt 2 0.5 0.5
./build/PolylineSolver.exe data/example2.txt 1 1 1
./build/PolylineSolver.exe data/example3.txt 3 3 3
```


