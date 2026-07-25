//
// Created by muharem on 7/25/26.
//

#ifndef TEST_INTERVAL_H
#define TEST_INTERVAL_H
#include "Ray_Tracing_Weekend.h"

class interval
{
public:
    double min, max;
    interval(): min(+infinity), max(-infinity){} //default interval is set up to be -inf and +inf
    interval(double min, double max): min(min), max(max) {}
    double size() const
    {
        return max-min;
    }
    bool contains(double x) const
    {
        return min<= x && x<=max;

    }
    bool surrounds(double x) const
    {
        return min<x&& x<max;
    }
    static const interval empty, universe;

};
const interval interval:: empty = interval(+infinity,-infinity);
const interval interval:: universe=interval(-infinity,+infinity);



#endif //TEST_INTERVAL_H