#ifndef INTERACCION_H
#define INTERACCION_H

#include <unordered_set>
#include <string>
#include <vector>
#include "pelicula.h"

void darLike(const std::string& titulo);
void agregarVerMasTarde(const std::string& titulo);
void mostrarVerMasTarde(const std::vector<Pelicula>& peliculas);

#endif // INTERACCION_H
