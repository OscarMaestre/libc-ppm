#include <fstream>
#include <iostream>
#include <vector>

struct Color {
    unsigned char r, g, b; // Componentes de color (rojo, verde, azul)
};

int main() {
    // Dimensiones de la imagen
    const int width = 256;
    const int height = 256;

    // Crear una matriz de colores
    std::vector<Color> pixels(width * height);

    // Generar un degradado simple (rojo a azul)
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            unsigned char r = static_cast<unsigned char>((x * 255) / width); // Rojo basado en x
            unsigned char g = static_cast<unsigned char>((y * 255) / height); // Verde basado en y
            unsigned char b = 128; // Azul constante
            pixels[y * width + x] = {r, g, b};
        }
    }

    // Nombre del archivo PPM
    const std::string filename = "output.ppm";

    // Abrir archivo en modo binario
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error al abrir el archivo " << filename << std::endl;
        return 1;
    }

    // Escribir la cabecera del archivo PPM
    file << "P6\n"                // Tipo de archivo
         << width << " " << height << "\n" // Dimensiones
         << "255\n";              // Valor máximo de color

    // Escribir los datos binarios de la imagen
    file.write(reinterpret_cast<char*>(pixels.data()), pixels.size() * sizeof(Color));

    // Cerrar el archivo
    file.close();

    std::cout << "Archivo PPM generado: " << filename << std::endl;
    return 0;
}
