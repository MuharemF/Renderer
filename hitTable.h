//
// Created by muharem on 6/27/26.
//

#ifndef TEST_HITTABLE_H
#define TEST_HITTABLE_H
#include "ray.h"
class hitRecord {
public:
    point3 p;
    vec3 normal;
    double t;
    bool frontFace;


    void setFaceNormal(const ray& r,const vec3& outwardNormal)
    {
        //ray is pointing inside the sphere (not in view if the user)
        if (dot(r.direction(),outwardNormal)<0.0)
        {
            normal=-outwardNormal;
            frontFace=false;

        }else
        {
            //ray is pointing outside the sphere towards the viewer/user
            normal=outwardNormal;
            frontFace=true;
        }
    }


};

class hitTable {
public:
    virtual ~hitTable()= default;
    virtual  bool hit(const ray&r,double rayTmin,double rayTmax, hitRecord& rec)const =0;
};

#endif //TEST_HITTABLE_H