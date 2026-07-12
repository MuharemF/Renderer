//
// Created by muharem on 6/27/26.
//
//test comment
#ifndef TEST_HITTABLE_H
#define TEST_HITTABLE_H

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
          frontFace=true;
            normal = outwardNormal;
        }else
        {
            frontFace=false;
            normal=-outwardNormal;
        }
    }


};

class hitTable {
public:
    virtual ~hitTable()= default;
    virtual  bool hit(const ray&r,double rayTmin,double rayTmax, hitRecord& rec)const =0;
};

#endif //TEST_HITTABLE_H