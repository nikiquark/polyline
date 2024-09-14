#pragma once

#include <string>
#include <Polyline.h>

namespace Math{
    struct PolylineParser final{
        PolylineParser() = delete;
        static Polyline read_file(const std::string&);
    };
}
