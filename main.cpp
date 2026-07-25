#include "Ray_Tracing_Weekend.h"
#include "hitTable.h"
#include "camera.h"
#include "hitTableList.h"
#include "sphere.h"
using namespace std;
// we can create the circle using the formula x^2+y^2+z^2=r^2
//however it is better to use the formula h=b/(-2)=d*(C-Q)





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
    camera cam;
    cam.aspectRatio=16.0/9.0;
    cam.imageWidth=1200;
    cam.render(world);






}