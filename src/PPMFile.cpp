#include "PPMFile.hpp"
#include <iostream>
PPMFile::PPMFile(unsigned int width, unsigned int height)
{
    this->width=width;
    this->height=height;
    matrix=std::vector<unsigned char>(width * height * 3);
}

unsigned int PPMFile::get_width() const
{
    return this->width;
}

unsigned int PPMFile::get_height() const
{
    return this->height;
}

void PPMFile::set_pixel_color(unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b)
{
    unsigned int base_r=((y*width)+x)*3;
    unsigned int base_g=base_r+1;
    unsigned int base_b=base_g+1;
    this->matrix[base_r]=r;
    this->matrix[base_g]=g;
    this->matrix[base_b]=b;
}

void PPMFile::save_file(const std::string filename)
{
    std::ofstream destination(filename, std::ios::binary);

    destination << "P6" << std::endl;
    destination << width << " " << height << std::endl;
    destination << 255 << std::endl;
    auto data=matrix.data();
    auto data_size=matrix.size();
    destination.write(reinterpret_cast<const char*>(data), data_size);
    destination.close();
}