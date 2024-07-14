#ifndef BUSQUEDA_H
#define BUSQUEDA_H

#include <vector>
#include <string>
#include "pelicula.h"

std::vector<Pelicula> buscarPorTitulo(const std::vector<Pelicula>& peliculas, const std::string& termino);
std::vector<Pelicula> buscarPorTag(const std::vector<Pelicula>& peliculas, const std::string& tag);
void mostrarResultados(const std::vector<Pelicula>& resultados, int pagina);

#endif // BUSQUEDA_H
