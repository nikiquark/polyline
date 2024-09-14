#pragma once

#include <Vector3.h>
#include <Polyline.h>
#include <utility>
#include <vector>

namespace Math{
    struct Solver final{
        
        using Record = std::pair<size_t, Math::Vector3lf>;
        using RecordVec = std::vector<Record>;

        Solver() = delete;
        static RecordVec solve(const Math::Polyline&, const Math::Vector3lf&);

    private:
        static std::pair<Math::Vector3lf, double>
        near_point_on_segment(const Math::Vector3lf&, const Math::Polyline::Segment&);
    };
}