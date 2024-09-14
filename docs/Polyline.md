# Polyline module

Represents a polyline in 3D space.
 
`Polyline` class defines a polyline consisting of nodes represented by `Vector3lf` points.
Each segment of the polyline is defined by a pair of nodes.

Also contain a utility class `Math::PolylineParser` for parsing `Math::Polyline` objects from files.


## types
```cpp
Polyline::Node = Math::Vector3lf;
Polyline::Segment = std::pair<Node, Node>;
```

## `Math::Polyline`

```cpp
struct Polyline{
    std::vector<Node> nodes;

    Polyline(const std::vector<Node>& nodes);
};
```

## `Math::PolylineParser`

```cpp
struct PolylineParser{
    static Polyline read_file(const std::string& ifname);
};
```

Generates `Polyline` from the contents of a file named `ifname` (first argument).
The file has the format:
```
x1 y1 z1
x2 y2 z2
x3 y3 z3
...
xn yn zn 
```
Throws an exception `std::invalid_argument` if the file cannot be opened or if the file format is invalid.

