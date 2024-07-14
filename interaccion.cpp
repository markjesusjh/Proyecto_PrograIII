#include "interaccion.h"
#include <algorithm>
#include <iostream>

std::unordered_set<std::string> likes;
std::unordered_set<std::string> verMasTarde;

void darLike(const std::string& titulo) {
    likes.insert(titulo);
}

void agregarVerMasTarde(const std::string& titulo) {
    verMasTarde.insert(titulo);
}

void mostrarVerMasTarde(const std::vector<Pelicula>& peliculas) {
    for (const auto& titulo : verMasTarde) {
        auto it = std::find_if(peliculas.begin(), peliculas.end(), [&titulo](const Pelicula& p) {
            return p.titulo == titulo;
        });
        if (it != peliculas.end()) {
            std::cout << it->titulo << std::endl;
        }
    }
}
