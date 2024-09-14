#include <PolylineParser.h>
#include <Polyline.h>

#include <fstream>
#include <sstream>

using namespace Math;

Polyline PolylineParser::read_file(const std::string& ifname){

    std::fstream ifile(ifname, std::ios::in);
    if (!ifile.good()) 
        throw std::invalid_argument("File not found");

    std::string str;
    Polyline p;
    while(getline(ifile, str)){
        double x, y, z;
        std::stringstream ss(str);
        if (!(ss >> x >> y >> z))
            throw std::invalid_argument("Invalid file format");
        p.nodes.emplace_back(x, y, z);
    }
    p.nodes.shrink_to_fit();
    return p;
}

