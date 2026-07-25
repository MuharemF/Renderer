//
// Created by muharem on 7/25/26.
//

#ifndef TEST_CAMERA_H
#define TEST_CAMERA_H
#include <iostream>
#include <ostream>

#include "hitTable.h"
class camera
{
public:
    //the way the image space is calculated is from the 0th point that being the top left of the image to the last pixel that being the bottem right pixel we calculate row by row each pixel going down from there
    //image space
    double aspectRatio= 1.0;
    int imageWidth=100;
    void render(const hitTable& world)
    {
        intialize();
        std::cout<<"P3\n" <<imageWidth<<' '<<imageHeight<<"\n255\n";
        for (int i=0;i<imageHeight;i++) {
            std::clog<<"\rScanlines remaining: "<<(imageHeight-i)<< ' ' <<std::flush;
            for (int j=0;j<imageWidth;j++) {
                auto pixelCenter=pixel_00+(j*pixelDelta_u)+(i*pixelDelta_v);
                auto rayDirection=pixelCenter-cameraCenter;
                ray r(cameraCenter,rayDirection);


                color pixelColor=rayColor(r,world);
                writeColor(std::cout,pixelColor);
            }
        }
        std::clog << "\rDone.                 \n";
    }


private:
    int    imageHeight;   // Rendered image height
    point3 cameraCenter;         // Camera center
    point3 pixel_00;    // Location of pixel 0, 0
    vec3   pixelDelta_u;  // Offset to pixel to the right
    vec3   pixelDelta_v;  // Offset to pixel below

    void intialize()
    {
        imageHeight=int(imageWidth/aspectRatio);
        if (imageHeight<1) {
            imageHeight=1;
        }
        //camera
        auto focalLength=1.0;
        auto viewportHeight=2.0;
        //gives the value of the aspect ratio
        auto viewportWidth=viewportHeight*(double(imageWidth)/imageHeight);
        cameraCenter=point3(0,0,0);

        //calculates the horzontal vectors and down the vertival edges of the viewport
        //horozontal
        auto viewport_u = vec3(viewportWidth,0,0);
        //vertical (negative cause it goes down)
        auto viewport_v=vec3(0,-viewportHeight,0);

        //calculate the horizontal and vertical delat vectors going pixel to pixel
        pixelDelta_u=viewport_u/imageWidth;
        pixelDelta_v=viewport_v/imageHeight;

        //this is to calculate the 0th most pixel (upper left)
        auto viewport_upperLeft=cameraCenter-vec3(0,0,focalLength)-viewport_u/2-viewport_v/2;
        pixel_00=viewport_upperLeft + 0.5*(pixelDelta_u+pixelDelta_v);


    }
    color rayColor(const ray& r, const hitTable& world) const
    {
        hitRecord rec;
        if (world.hit(r,interval(0,infinity),rec))
        {
            return .5*(rec.normal+color(1,1,1));
        }
        vec3 unitDirection=unitVec(r.direction());

        auto a=.5*(unitDirection.y()+1.0);
        return (1-a)*color(1.0,1.0,1.0)+a*color(.5,.7,1.0);
    }
};
#endif //TEST_CAMERA_H