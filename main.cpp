#include <iostream>
using namespace std;

int main() {
    int image_height=256;
    int image_width=256;
    cout<<"P3\n " <<image_width<<' '<<image_height<<"\n255\n";
    for (int i=0;i<image_height;i++) {
        clog<<"\rScanlines remaining: "<<(image_height-i)<< ' ' <<flush;
        for (int j=0;j<image_width;j++) {
            auto r= double(j)/(image_width-1);
            auto g=double(i)/(image_height-1);
            auto b=.5;
            int ir=int(255.99*r);
            int ig=int(255.99*g);
            int ib=int(255.99*b);
            cout<<ir<<' '<<ig<<' '<<ib<<endl;
        }
    }
    clog << "\rDone.                 \n";


}