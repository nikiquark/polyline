#include <Solver.h>
#include <Vector3.h>
#include <limits>


using namespace Math;

Solver::RecordVec Solver::solve(const Math::Polyline& polyline, const Math::Vector3lf& point){
    RecordVec result;
    double min_dist = std::numeric_limits<double>::max();

    auto& nodes = polyline.nodes;
    for (size_t i = 0; i < nodes.size() - 1; i++){
        Math::Polyline::Segment seg{nodes[i], nodes[i + 1]};
        auto res = near_point_on_segment(point, seg);
        min_dist = std::min(min_dist, res.second);
    }

    for (size_t i = 0; i < nodes.size() - 1; i++){
        Math::Polyline::Segment seg{nodes[i], nodes[i + 1]};
        auto res = near_point_on_segment(point, seg);
        if (std::abs(res.second - min_dist) < 1e-7)
            result.push_back({i, res.first});
    }

    return result;
};

std::pair<Math::Vector3lf, double>
Solver::near_point_on_segment(const Math::Vector3lf& point, const Math::Polyline::Segment& seg){
    using namespace Math::utils;
    double d = distance_to_line(point, seg.first, (seg.second-seg.first));
    auto p   = project_point_to_line(point, seg.first, (seg.second-seg.first));

    if (p.is_between(seg.first, seg.second))
        return std::make_pair(p, d);
    
    double d1 = (point-seg.first).abs();
    double d2 = (point-seg.second).abs();
    if (d1 < d2) 
        return {seg.first, d1}; 
    return {seg.second, d2};
}