#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <fstream>
#include <vector>
#include <iostream>
#include <cassert>
#include <string>

#include "Vec3.hpp"
#include "Sphere.hpp"
#include "RayTracer.hpp"

/*
constexpr unsigned MAX_RAY_DEPTH = 5;               // Maximum recursion depth
constexpr unsigned WIDTH = 640;                     // Width of output image
constexpr unsigned HEIGHT = 480;                    // Height of output image
constexpr float FOV = 30.0f;                        // Field of View
const std::string FILENAME = "./sphere-image.ppm";  // Name of output image
const Vec3f BG_COLOR(2);                            // Background color
*/

/**
 * In the main function, we will create the scene which is composed of 5 spheres
 * and 1 light (which is also a sphere). Then, once the scene description is complete
 * we render that scene, by calling the render() function.
 */
int main(int argc, char **argv)
{
    srand48(13);

    // Holds all our sphere objects in the scene
    std::vector<Sphere> spheres;

    // position, radius, surface color, reflectivity, transparency, emission color
    spheres.push_back(Sphere(Vec3f(0.0, -10004, -20), 10000, Vec3f(0.20, 0.20, 0.20), 0, 0.0));
    spheres.push_back(Sphere(Vec3f(0.0, 0, -20), 4, Vec3f(1.00, 0.32, 0.36), 1, 0.5));
    spheres.push_back(Sphere(Vec3f(5.0, -1, -15), 2, Vec3f(0.90, 0.76, 0.46), 1, 0.0));
    spheres.push_back(Sphere(Vec3f(5.0, 0, -25), 3, Vec3f(0.65, 0.77, 0.97), 1, 0.0));
    spheres.push_back(Sphere(Vec3f(-5.5, 0, -15), 3, Vec3f(0.90, 0.90, 0.90), 1, 0.0));

    // light
    spheres.push_back(Sphere(Vec3f(0.0, 20, -30), 3, Vec3f(0.00, 0.00, 0.00), 0, 0.0, Vec3f(3)));

    // Create our ray tracer then render the spheres
    RayTracer rayTracer;
    rayTracer.render(spheres);

    return 0;
}