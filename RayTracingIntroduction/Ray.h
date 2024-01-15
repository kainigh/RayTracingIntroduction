#ifndef RAY_H
#define RAY_H

#include "Vector3.h"

class ray {
public:
    ray() {}

    ray(const Position& origin, const Vector3& direction) : orig(origin), dir(direction) {}

    Position GetOrigin() const { return orig; }
    Vector3 GetDirection() const { return dir; }

    Position at(double t) const {
        return orig + t * dir;
    }

private:
    Position orig;
    Vector3 dir;
};

#endif

