#pragma once

#include <cmath>
#include <stdexcept>

namespace Math{

    template<typename T>
    struct Vector3 final{
        T x, y, z;
        Vector3():x(0), y(0), z(0) {};
        Vector3(T x, T y, T z):x(x), y(y), z(z) {};

        Vector3 operator-() const{
            return {-x, -y, -z};
        }

        Vector3 operator+(const Vector3& other) const{
            return {x + other.x, y + other.y, z + other.z};
        }

        Vector3 operator-(const Vector3& other) const{
            return {x - other.x, y - other.y, z - other.z}; 
        }

        Vector3 operator*(const T& a) const{
            return {x * a, y * a, z * a};
        }
        
        friend Vector3 operator*(const T& a, const Vector3& other){
            return other * a;
        }

        Vector3 operator/(const T& a) const{
            if (a == 0) {
                throw std::domain_error("Division by zero");
            }
            return {x / a, y / a, z / a};
        }

        Vector3 operator*(const Vector3& other) const{
            return {y * other.z - z * other.y, 
                    z * other.x - x * other.z, 
                    x * other.y - y * other.x};
        }
        
        T operator%(const Vector3& other) const{
            return x * other.x + y * other.y + z * other.z;
        }

        T abs() const{
            return std::sqrt(x * x + y * y + z * z);
        };

        bool is_between(const Vector3& a, const Vector3& b) const{
            if (x < std::min(a.x, b.x) || x > std::max(a.x, b.x) ||
                y < std::min(a.y, b.y) || y > std::max(a.y, b.y) ||
                z < std::min(a.z, b.z) || z > std::max(a.z, b.z))
                return false;
            return true;            
        }

        bool operator==(const Vector3& other) const{
            return std::abs(x - other.x)<1e-7 && 
                   std::abs(y - other.y)<1e-7 && 
                   std::abs(z - other.z)<1e-7;
        }

        bool operator!=(const Vector3& other) const{
            return !(*this == other);
        }

        friend std::ostream& operator<<(std::ostream& ostream, const Vector3& v){
            return ostream << v.x << " " << v.y << " " << v.z;
        }

        friend std::istream& operator>>(std::istream& istream, Vector3& v){
            return istream >> v.x >> v.y >> v.z;
        }
    };    

    using Vector3lf = Vector3<double>;

    namespace utils {

        double distance_to_line(const Vector3lf& M0, 
                                const Vector3lf& M1, 
                                const Vector3lf& s);
            // distance from point M0 to line with vector S and point M1


        Vector3lf project_point_to_line(const Vector3lf& M0,
                                        const Vector3lf& M1,
                                        const Vector3lf& s);
            // project point M0 to line with vector S and point M1

    }

}
