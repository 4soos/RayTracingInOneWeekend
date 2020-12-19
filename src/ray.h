//
// Created by young on 12/6/2020.
//

#ifndef RAYTRACINGINONEWEEKEND_RAY_H
#define RAYTRACINGINONEWEEKEND_RAY_H

#include "vec3.h"

class ray {
public:
    ray() = default;
    ray(const point3 &origin, const vec3 &direction) : orig(origin), dir(direction) {}

    [[nodiscard]] point3 orign() const { return orig; }

    [[nodiscard]] vec3 direction() const { return dir; }

    [[nodiscard]] point3 at(double t) const {
        return orig + t * dir;
    }

public:
    point3 orig{};
    vec3 dir{};
};

#endif //RAYTRACINGINONEWEEKEND_RAY_H
