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

## `Math::PolylineParser`





