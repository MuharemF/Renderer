//
// Created by muharem on 6/22/26.
//
//test comment
#ifndef TEST_RAY_H
#define TEST_RAY_H
#include "vec3.h"
class ray {
public:
    ray();
    //This block of code
    // ray(const point3& origin, const vec3& dirction) {
    //     orgi=origin;
    //     dir=dirction;
    //
    // }
    //equals this line of code but is more efficent
    ray(const point3& origin, const vec3& dirction): orgi(origin), dir(dirction) {}


    const point3& origin() const {
        return orgi;
    }
    const vec3& direction() const {
        return dir;
    }

    point3 at(double t) const {
        return orgi+dir*t;
    }
private:
    point3 orgi;
    vec3 dir;






};





#endif //TEST_RAY_H