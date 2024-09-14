# Vector3 module

`Vector3` class representing a 3D vector with x, y, and z components.

Supports arithmetic operations like addition, subtraction, scalar and matrix multiplication, and multiplication/division by scalar.
 
Provides methods for calculating absolute value, checking if a point is between two other points, and overloading comparison operators.

It also contains auxiliary functions: projecting a point onto a line, and calculating the distance from a point to a line.

> In real life I would use Eigen library or something similar

## Vector3

```cpp
template<typename T>
struct Vector3{
    T x, y, z;
    ...
}
```

A typical class for a 3D vector.

`operator*(const Vector3& other)` - matrix multiplication by another vector
`operator%(const Vector3& other)` - scalar multiplication by another `Vector3`


## Math::utils

The namespace in which the functions reside:
```cpp
double distance_to_line(const Vector3lf& M0, 
                        const Vector3lf& M1, 
                        const Vector3lf& s);
// distance from point M0 to line with vector S and point M1


Vector3lf project_point_to_line(const Vector3lf& M0,
                                const Vector3lf& M1,
                                const Vector3lf& s);
// projection of point M0 onto line with vector S and point M1

```

