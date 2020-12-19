//
// Created by young on 19/12/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_RTWEEKEND_H
#define RAYTRACINGINONEWEEKEND_RTWEEKEND_H

#include <cmath>
#include <limits>
#include <memory>
#include <cstdlib>
#include <random>

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

const double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

[[maybe_unused]] inline double degrees_to_radians(double degress) {
    return degress * pi / 180.0;
}

inline double clamp(double x, double min, double max) {
    if (x < min) return min;
    if (x > max) return max;

    return x;
}

inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

[[maybe_unused]] inline double random_double(double min, double max) {
    return min + (max - min) *  random_double();
}

#include "ray.h"
#include "vec3.h"

#endif //RAYTRACINGINONEWEEKEND_RTWEEKEND_H
