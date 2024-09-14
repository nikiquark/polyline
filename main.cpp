#include <iostream>
#include <string>
#include <Vector3.h>
#include <Polyline.h>
#include <PolylineParser.h>
#include <Solver.h>

int main(int argc, char* argv[]){
    using Math::Polyline;
    using Math::PolylineParser;
    using Math::Solver;
    using Math::Vector3lf;

    if (argc != 5){
        std::cout << "Usage: " << argv[0] << " <input file> <x> <y> <z>" << std::endl;
        return 0;
    }
    const std::string ifname{argv[1]};
    const Vector3lf point{std::stod(argv[2]), std::stod(argv[3]), std::stod(argv[4])};
    
    Polyline polyline;
    
    try{
        polyline = PolylineParser::read_file(ifname);
    }
    catch (const std::invalid_argument& e){
        std::cout << e.what() << std::endl;
        return 0;
    }

    auto res = Solver::solve(polyline, point);

    for (auto v: res){
        std::cout << "segment " << v.first + 1 << " point " << v.second << std::endl;
    }

    return 0;
}