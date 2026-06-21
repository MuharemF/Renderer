#include "color.h"
#include "vec3.h"

#include <iostream>
using namespace std;

int main() {
    int image_height=256;
    int image_width=256;
    cout<<"P3\n " <<image_width<<' '<<image_height<<"\n255\n";
    for (int i=0;i<image_height;i++) {
        clog<<"\rScanlines remaining: "<<(image_height-i)<< ' ' <<flush;
        for (int j=0;j<image_width;j++) {
            auto pixleColor=color(double(j)/(image_width-1),double(i)/(image_height-1),0);
            writeColor(cout,pixleColor);
        }
    }
    clog << "\rDone.                 \n";


}