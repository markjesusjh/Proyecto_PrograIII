#include "busqueda.h"
#include <algorithm>
#include <iostream>

std::vector<Pelicula> buscarPorTitulo(const std::vector<Pelicula>& peliculas, const std::string& termino) {
    std::vector<Pelicula> resultados;
    std::copy_if(peliculas.begin(), peliculas.end(), std::back_inserter(resultados), [&termino](const Pelicula& p) {
        return p.titulo.find(termino) != std::string::npos;
    });
    return resultados;
}

std::vector<Pelicula> buscarPorTag(const std::vector<Pelicula>& peliculas, const std::string& tag) {
    std::vector<Pelicula> resultados;
    std::copy_if(peliculas.begin(), peliculas.end(), std::back_inserter(resultados), [&tag](const Pelicula& p) {
        return std::find(p.tags.begin(), p.tags.end(), tag) != p.tags.end();
    });
    return resultados;
}

void mostrarResultados(const std::vector<Pelicula>& resultados, int pagina) {
    int inicio = pagina * 5;
    int fin = std::min(inicio + 5, static_cast<int>(resultados.size()));
    for (int i = inicio; i < fin; ++i) {
        std::cout << resultados[i].titulo << std::endl;
    }
    if (fin < resultados.size()) {
        std::cout << "Mostrar más (siguiente página)\n";
    }
}
