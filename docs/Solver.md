
# Solver module

## class `Math::Solver`

Class `Solver` solves [this problem](./task.pdf). 

It provides a static method `Solver::solve` that returns the desired set of answers.

## types
```cpp
Solver::Record = std::pair<size_t, Math::Vector3lf>;
Solver::RecordVec = std::vector<Record>;
```
The auxiliary type `Record` is used to record each response point. The first element of the pair is the index of the segment on which the closest point lies, the second element of the pair is the closest point on the corresponding segment.

The auxiliary type `RecordVec` is a `std::vector<Record>`.


## `solve`
```cpp
static RecordVec Math::Solver::solve(const Math::Polyline&, const Math::Vector3lf&);
```

The static function `solve` finds the closest points on the `Math::Polyline` passed as the first argument to the point passed as the second argument.
