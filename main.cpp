#include "Ray_Tracing_Weekend.h"
#include "hitTable.h"
#include "hitTableList.h"
#include "sphere.h"
using namespace std;
// we can create the circle using the formula x^2+y^2+z^2=r^2
//however it is better to use the formula h=b/(-2)=d*(C-Q)



color ray_color(const ray& r, const hitTable& world) {
    hitRecord rec;
    if (world.hit(r,0.0001,infinity,rec))
    {
        return .5*(rec.normal+color(1,1,1));
    }
    vec3 unitDirection=unitVec(r.direction());

    auto a=.5*(unitDirection.y()+1.0);
    return (1-a)*color(1.0,1.0,1.0)+a*color(.5,.7,1.0);
}


int main() {
    //the way the image space is calculated is from the 0th point that being the top left of the image to the last pixel that being the bottem right pixel we calculate row by row each pixel going down from there
    //image space
    auto aspectRatio= 16.0/9.0;
    int imageWidth=1200;
    //the image height but always be a whole number and can never be <1 otherwise the ratio changes
    int imageHeight=int(imageWidth/aspectRatio);
    if (imageHeight<1) {
        imageHeight=1;
    }
    //world
    hitTableList world;
    world.add(make_shared<sphere>(point3(0,0,-1),0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1),100.0));




    //camera
    auto focalLength=1.0;
    auto viewportHeight=2.0;
                                                    //gives the value of the aspect ratio
    auto viewportWidth=viewportHeight*(double(imageWidth)/imageHeight);
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
            color pixelColor=ray_color(r,world);
            writeColor(cout,pixelColor);
        }
    }
    clog << "\rDone.                 \n";


}