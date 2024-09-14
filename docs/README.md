# Documentation

## Vector3 module

`Vector3` class representing a 3D vector with x, y, and z components.

Supports arithmetic operations like addition, subtraction, scalar and matrix multiplication, and multiplication/division by scalar.
 
Provides methods for calculating absolute value, checking if a point is between two other points, and overloading comparison operators.

It also contains auxiliary functions: projecting a point onto a line, and calculating the distance from a point to a line.

[Detailed description](./Vector3.md)

## Polyline module

Represents a polyline in 3D space.
 
This struct defines a polyline consisting of nodes represented by `Vector3lf` points.
Each segment of the polyline is defined by a pair of nodes.

Also contain a utility class for parsing Polyline objects from files.

[Detailed description](./Polyline.md)

## Solver module

Class `Solver` solves [this problem](./task.pdf). It provides a static method `Solver::solve` that returns the desired set of answers.

[Detailed description](./Solver.md)
