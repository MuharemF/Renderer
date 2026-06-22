#include "color.h"
#include "ray.h"
#include "vec3.h"
#include <iostream>
using namespace std;
color ray_color(const ray& r) {
    vec3 unitDirection=unitVec(r.direction());
    auto a=.5*(unitDirection.y()+1.0);
    return (1-a)*color(1.0,1.0,1.0)+a*color(.5,.7,1.0);
}


int main() {
    //the way the image space is calculated is from the 0th point that being the top left of the image to the last pixel that being the bottem right pixel we calculate row by row each pixel going down from there
    //image space
    auto aspectRatio= 16/9;
    int imageWidth=400;
    //the image height but always be a whole number and can never be <1 otherwise the ratio changes
    int imageHeight=int(imageWidth/aspectRatio);
    if (imageHeight<1) {
        imageHeight=1;
    }
    //camera
    auto focalLength=1.0;
    auto viewportHeight=2.0;
                                                    //gives the value of the aspect ratio
    auto viewportWidth=viewportHeight*(double(imageWidth/imageHeight));
    auto cameraCenter=point3(0,0,0);

    //calculates the horzontal vectors and down the vertival edges of the viewport
    //horozontal
    auto viewport_u = vec3(viewportWidth,0,0);
    //vertical (negative cause it goes down)
    auto viewport_v=vec3(0,-viewportHeight,0);

    //calculate the horizontal and vertical delat vectors going pixel to pixel
    auto pixelDelta_u=viewport_u/imageWidth;
    auto pixelDelta_v=viewport_v/imageHeight;

    //this is to calculate the 0th most pixel (upper left)
    auto viewport_upperLeft=cameraCenter-vec3(0,0,focalLength)-viewport_u/2-viewport_v/2;
    auto pixel_00=viewport_upperLeft + 0.5*(pixelDelta_u+pixelDelta_v);










    cout<<"P3\n " <<imageWidth<<' '<<imageHeight<<"\n255\n";
    for (int i=0;i<imageHeight;i++) {
        clog<<"\rScanlines remaining: "<<(imageHeight-i)<< ' ' <<flush;
        for (int j=0;j<imageWidth;j++) {
            auto pixelCenter=pixel_00+(j*pixelDelta_u)+(i*pixelDelta_v);
            auto rayDirection=pixelCenter-cameraCenter;
            ray r(cameraCenter,rayDirection);
            color pixelColor=ray_color(r);
            writeColor(cout,pixelColor);
        }
    }
    clog << "\rDone.                 \n";


}