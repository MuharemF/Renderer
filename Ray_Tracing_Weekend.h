//
// Created by muharem on 7/12/26.
//

#ifndef TEST_RAY_TRACING_WEEKEND_H
#define TEST_RAY_TRACING_WEEKEND_H
#include <cmath>
#include <iostream>
#include <limits>
#include <memory>

using std::make_shared;
using std::shared_ptr;

const double infinity= std::numeric_limits<double>::infinity();
const double pi =3.1415926535897932385;


inline double degreesToRadians(double degree)
{
    return degree*pi/180.0;
}

#include "color.h"
#include "ray.h"
#include "vec3.h"
#include "interval.h"












#endif //TEST_RAY_TRACING_WEEKEND_H