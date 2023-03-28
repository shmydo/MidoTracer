#ifndef _TUPLE_H
#define _TUPLE_H

#include <cassert>
#include <cmath>

namespace Mido{

    // (TODO): MOVE ALL OF THESE
    namespace constants{
        constexpr double EPISILON = 0.00001;
    }

    inline bool equal(double v1, double v2){
        return std::abs(v1 - v2) < constants::EPISILON;
    }
    // END OF TODO

    struct Tuple
    {
        double x, y, z, w;

        Tuple(double x, double y, double z, double w)
        : x{x}, y{y}, z{z}, w{w}
        {
        }

        friend inline bool operator==(const Tuple& lhs, const Tuple& rhs){
            return equal(lhs.x, rhs.x)  
                && equal(lhs.y, rhs.y) 
                && equal(lhs.z, rhs.z)
                && equal(lhs.w, rhs.w);
        }
        
        friend inline Tuple operator+(const Tuple& lhs, const Tuple& rhs){
            assert(lhs.w == 1 && !equal(lhs.w, rhs.w) 
                   && "(Tuple::operator+): Attempting to add two points");

            return Tuple(lhs.x + rhs.x, 
                         lhs.y + rhs.y, 
                         lhs.z + rhs.z,
                         lhs.w + rhs.w);             
        }
        
        friend inline Tuple operator-(const Tuple& lhs, const Tuple& rhs){
            assert(!(lhs.w == 0 && rhs.w == 1)
                && "(Tuple::operator-): Attempting Vector - Point (illegal)");

            return Tuple(lhs.x - rhs.x, 
                         lhs.y - rhs.y, 
                         lhs.z - rhs.z,
                         lhs.w - rhs.w);                         
        }

        friend inline Tuple operator-(const Tuple& rhs){
            return Tuple(-rhs.x, -rhs.y, -rhs.z, -rhs.w);
        }

        friend inline Tuple operator*(const Tuple& lhs, double rhs){
            return Tuple(lhs.x * rhs,
                         lhs.y * rhs,
                         lhs.z * rhs,
                         lhs.w * rhs);
        } 

        friend inline Tuple operator*(double lhs, const Tuple& rhs){
            return Tuple(rhs.x * lhs,
                         rhs.y * lhs,
                         rhs.z * lhs,
                         rhs.w * lhs); 
        }

        friend inline Tuple operator/(const Tuple& lhs, double rhs){
            return Tuple(lhs.x / rhs,
                         lhs.y / rhs,
                         lhs.z / rhs,
                         lhs.w / rhs);
        } 

        friend std::ostream& operator<<(std::ostream& os, const Tuple rhs){
            os << "Tuple(" 
               << rhs.x << ", " << rhs.y << ", " 
               << rhs.z << ", " << rhs.w << ")";

            return os;
        }

    };

    inline Tuple createPoint(double x, double y, double z){
        return Tuple(x,y,z,1);
    }

    inline Tuple createVector(double x, double y, double z){
        return Tuple(x,y,z,0);
    }

    inline double magnitude(const Tuple& tup){
        using std::sqrt;

        assert(tup.w != 1 
            && "(Tuple::magnitude): Attempting to get mag of a point");

        return sqrt( tup.x * tup.x 
                   + tup.y * tup.y 
                   + tup.z * tup.z
                   + tup.w * tup.w );
    }
    
    inline double dot(const Tuple& lhs, const Tuple& rhs){
        return (  lhs.x * rhs.x
                + lhs.y * rhs.y
                + lhs.z * rhs.z
                + lhs.w * rhs.w );
    }

    inline Tuple normalize(const Tuple& tup){
        double tup_mag = magnitude(tup);
        return Tuple( tup.x / tup_mag,
                      tup.y / tup_mag,
                      tup.z / tup_mag,
                      tup.w / tup_mag);
    }

    inline Tuple cross(const Tuple& lhs, const Tuple& rhs){
        return createVector( lhs.y * rhs.z - lhs.z * rhs.y,
                             lhs.z * rhs.x - lhs.x * rhs.z,
                             lhs.x * rhs.y - lhs.y * rhs.x);                
    }
}
#endif 