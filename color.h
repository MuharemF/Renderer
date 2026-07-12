//
// Created by muharem on 6/20/26.
//

#ifndef TEST_COLOR_H
#define TEST_COLOR_H


#include "vec3.h"

using color =vec3;
void writeColor(std::ostream&out, const color& pixelColor) {
    auto r=pixelColor.x();
    auto g=pixelColor.y();
    auto b=pixelColor.z();

    //Translating the [0,1] compomet values to the byte range [0, 255]
    int rbyte =int(255.999*r);
    int gbyte=int(255.999*g);
    int bbyte=int(255.999*b);
    //write the color components
    out<<rbyte<<' '<<gbyte<<' '<<bbyte<<"\n";
}
#endif //TEST_COLOR_H