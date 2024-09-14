#include <Vector3.h>

using namespace Math;

double utils::distance_to_line(const Vector3lf& M0, 
                               const Vector3lf& M1, 
                               const Vector3lf& s) {
    // distance from point M0 to line with vector s and point M1
    return ((M1 - M0) * s).abs() / s.abs();
}

Vector3lf utils::project_point_to_line(const Vector3lf& M0,
                                       const Vector3lf& M1,
                                       const Vector3lf& s) {
    // project point M0 to line with vector s and point M1
    const double p = (M1 - M0) % s / s.abs();
    return M1 - p / s.abs() * s;
}
        
