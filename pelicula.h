#ifndef PELICULA_H
#define PELICULA_H

#include <string>
#include <vector>

struct Pelicula {
    std::string titulo;
    std::string sinopsis;
    std::vector<std::string> tags;
};

std::vector<Pelicula> leerCSV(const std::string& nombreArchivo);

#endif // PELICULA_H
