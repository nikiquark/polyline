#pragma once

#include <vector>
#include <utility>
#include <Vector3.h>

namespace Math{

    struct Polyline final{
        using Node =  Math::Vector3lf;
        using Segment = std::pair<Node, Node>;
        std::vector<Node> nodes;

        Polyline() = default;
        Polyline(const std::vector<Node>& nodes) : nodes(nodes) {}
    };

}