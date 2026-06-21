//
// Created by muharem on 6/20/26.
//

#ifndef TEST_VEC3_H
#define TEST_VEC3_H


#include <iostream>
#include <cmath>

class vec3 {
public:
    double e[3];
    vec3(): e{0,0,0}{}
    vec3(double e0,double e1,double e2): e{e0,e1,e2}{}
    double x() const {
        return e[0];
    }
    double y() const {
        return e[1];
    }
    double z() const {
        return e[2];
    }
    //returns the inverse of the vector
    vec3 operator-() const {
        return vec3(-e[0], -e[1],-e[2]);
    }
    double operator[](int i) const {
        return e[i];
    }
    double& operator[](int i ) {
        return e[i];
    }

    //defines the += operator
    vec3& operator+=(const vec3& v) {
        e[0]+=v.e[0];
        e[1]+=v.e[1];
        e[2]+=v.e[2];
        return *this;
    }
    //defines the *= operator
    vec3& operator*=(double t){
        e[0]*=t;
        e[1]*=t;
        e[2]*=t;
        return *this;

    }
    //this is a trick to define scalor multiplication or divison
    vec3&operator/=(double t) {
        return *this *= 1/t;
    }


    double lengthSquared() const{
        return e[0]*e[0]+e[1]*e[1]+e[2]*e[2];
    }
    double length() const {
        return std::sqrt(lengthSquared());
    }




};
//all this means is that from here on point3 is vec3 we use a different name for clarity
using point3=vec3;

//ultility functions
//inline is a rquest to replace a fucntion call with its code to reduce overhead meaning it trys to run its code automaticly
//becase its a request it doesnt mean its going to happen
inline std::ostream& operator<<(std::ostream& out,const vec3& v) {
    return out <<v.e[0]<<' '<<v.e[1]<<' '<<v.e[2];
}
inline vec3 operator+(const vec3& u,const vec3& v) {
    return vec3(u.e[0]+v.e[0],u.e[1]+v.e[1],u.e[2]+v.e[2]);
}
inline vec3 operator-(const vec3& u,const vec3&v) {
    return vec3(u.e[0]-v.e[0],u.e[1]-v.e[1],u.e[2]-v.e[2]);
}
inline vec3 operator*(const vec3& u,const vec3&v) {
    return vec3(u.e[0]*v.e[0],u.e[1]*v.e[1],u.e[2]*v.e[2]);
}
inline vec3 operator*(double t, const vec3& v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}
inline vec3 operator*(const vec3&v,double t) {
    return t*v;
}
inline vec3 operator/(const vec3& v,double t) {
    return (1/t)*v;
}
//dot product
inline double dot(const vec3&u, const vec3& v) {
    return u.e[0]*v.e[0]+u.e[1]*v.e[1]+u.e[2]*v.e[2];
}
//cross product
inline vec3 cross(const vec3&u,const vec3&v) {
    return vec3(
        u.e[1]*v.e[2]-u.e[2]*v.e[1],
        u.e[2]*v.e[0]-u.e[0]*v.e[2],
        u.e[0]*v.e[1]-u.e[1]*v.e[0]);
}
inline vec3 unitVec(const vec3&v) {
    return v/v.length();
}



#endif //TEST_VEC3_H