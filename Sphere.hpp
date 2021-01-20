#ifndef SPHERE_HPP
#define SPHERE_HPP

#if defined __linux__ || defined __APPLE__
// "Compiled for Linux
#else
// Windows doesn't define these values by default, Linux does
#define M_PI 3.141592653589793
#define INFINITY 1e8
#endif

#include "Vec3.hpp"

class Sphere
{
public:
    Vec3f center;                      /// position of the sphere
    float radius, radius2;             /// sphere radius and radius^2
    Vec3f surfaceColor, emissionColor; /// surface color and emission (light)
    float transparency, reflection;    /// surface transparency and reflectivity
    Sphere(
        const Vec3f &c,
        const float &r,
        const Vec3f &sc,
        const float &refl = 0,
        const float &transp = 0,
        const Vec3f &ec = 0) : center(c), radius(r), radius2(r * r), surfaceColor(sc), emissionColor(ec),
                               transparency(transp), reflection(refl)
    { /* empty */
    }
    //[comment]
    // Compute a ray-sphere intersection using the geometric solution
    //[/comment]
    bool intersect(const Vec3f &rayorig, const Vec3f &raydir, float &t0, float &t1) const
    {
        Vec3f l = center - rayorig;
        float tca = l.dot(raydir);
        if (tca < 0)
            return false;
        float d2 = l.dot(l) - tca * tca;
        if (d2 > radius2)
            return false;
        float thc = sqrt(radius2 - d2);
        t0 = tca - thc;
        t1 = tca + thc;

        return true;
    }
};

#endif