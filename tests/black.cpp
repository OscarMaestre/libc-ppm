#include <iostream>
#include "PPMFile.hpp"
#include <fstream>

int main(){
    unsigned int width, height;
    width=1024;
    height=768;
    PPMFile ppmfile(width,height);
    float step_h=255.0/(width-1);
    float step_v=255.0/(height-1);
    for (int y=0; y<height; y++)
    {
        auto other=(step_v*y);
        for (int x=0; x<width; x++){
            auto grey=(step_h*x);
            ppmfile.set_pixel_color(x, y, grey, 255-grey, other);
        }
    }
    ppmfile.save_file("image.ppm");

}