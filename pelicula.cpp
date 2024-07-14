#include "pelicula.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Pelicula> leerCSV(const std::string& nombreArchivo) {
    std::vector<Pelicula> peliculas;
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo\n";
        return peliculas;
    }

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string titulo, sinopsis, tagsStr;
        std::getline(ss, titulo, ',');
        std::getline(ss, sinopsis, ',');
        std::getline(ss, tagsStr, ',');
        
        Pelicula pelicula;
        pelicula.titulo = titulo;
        pelicula.sinopsis = sinopsis;
        std::stringstream ssTags(tagsStr);
        std::string tag;
        while (std::getline(ssTags, tag, ';')) {
            pelicula.tags.push_back(tag);
        }

        peliculas.push_back(pelicula);
    }

    archivo.close();
    return peliculas;
}
