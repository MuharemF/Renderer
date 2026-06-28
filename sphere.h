//
// Created by muharem on 6/27/26.
//
//test comment
#ifndef TEST_SPHERE_H
#define TEST_SPHERE_H
#include "hitTable.h"
#include "vec3.h"
class shpere :public hitTable{
    sphere(const point3& center, double radius) : center(center), radius(std::fMax(0,radius)){}
    bool hit(const ray& r, double rayTMin, double rayTMax,hitRecord& rec ) const override
    {
        vec3 oc = center-r.origin();
        auto a=r.direction().lengthSquared();
        auto h=dot(r.direction(),oc);
        auto c=oc.lengthSquared()-radius*radius;
        auto discriminant=h*h-a*c;
        if (discriminant<0) {
            return -1.0;
        }else {
            return((h-std::sqrt(discriminant))/a);
        }
        //nearest root that lies in acceptable range
        auto root =(h-sqrtd)/a;
        if (root<=rayTMin||rayTMax<=root)
        {
            root=(h+sqrtd)/a;
            if (root<=rayTMin||rayTMax<=rayTMax)
            {
                return false;
            }
        }
        rec.t=root;
        rec.p=r.at(rec.t);
        rec.normal=(rec.p-center)/radius;
        vec3 outwardNormal=(rec.p-center)/radius;
        rec.setFaceNormal(r,outwardNormal);

        return true;


    }

private:
    point3 center;
    double radius;




    
};
#endif //TEST_SPHERE_H