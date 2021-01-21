#ifndef RAY_TRACER_HPP
#define RAY_TRACER_HPP

#include <string>
#include <vector>
#include "Vec3.hpp"
#include "Sphere.hpp"

class RayTracer
{
public:
    /** Default constructor */
    RayTracer() : maxRayDepth(5), width(640), height(480),
                  fov(30.0f), filename("./untitled.ppm"), bgColor(2){};

    /**
     * Mixes two scalar values basedon a mix value.
     */
    float mix(const float &a, const float &b, const float &mix)
    {
        return b * mix + a * (1 - mix);
    }

    Vec3f trace(const Vec3f &rayorig, const Vec3f &raydir,
                const std::vector<Sphere> &spheres, const int &depth);

    void writeToPPM(unsigned width, unsigned height, Vec3f *image);

    void render(const std::vector<Sphere> &spheres);

private:
    unsigned maxRayDepth; // Maximum recursion depth
    unsigned width;       // Width of output image
    unsigned height;      // Height of output image
    float fov;            // Field of View
    std::string filename; // Name of output image
    Vec3f bgColor;        // Background color
};

#endif