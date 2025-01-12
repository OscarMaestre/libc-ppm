#ifndef PPM_FILE_H
#define PPM_FILE_H

#include <vector>
#include <memory> // Para std::unique_ptr
#include <fstream>
class PPMFile {
private:
    unsigned int width, height;
    std::vector<unsigned char> matrix;

public:
    // Constructor
    PPMFile(unsigned int width, unsigned int height);

    // Getters
    unsigned int get_width() const;
    unsigned int get_height() const;

    // Modificar el color de un píxel
    void set_pixel_color(unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b);
    
    void save_file(const std::string filename);
};

#endif // PPM_FILE_H
