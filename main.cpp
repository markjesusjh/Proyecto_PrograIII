#include <iostream>
#include <vector>
#include <algorithm> // Necesario para std::find_if
#include "pelicula.h"
#include "busqueda.h"
#include "interaccion.h"
#include "recomendacion.h"

int main() {
    std::string nombreArchivo = "mpst_full_data.csv";
    std::vector<Pelicula> peliculas = leerCSV(nombreArchivo);

    std::cout << "Películas para ver más tarde:\n";
    mostrarVerMasTarde(peliculas);

    std::string terminoBusqueda = "Matrix";
    std::vector<Pelicula> resultadosBusqueda = buscarPorTitulo(peliculas, terminoBusqueda);
    mostrarResultados(resultadosBusqueda, 0);

    std::string peliculaSeleccionada = "The Matrix";
    auto it = std::find_if(peliculas.begin(), peliculas.end(), [&peliculaSeleccionada](const Pelicula& p) {
        return p.titulo == peliculaSeleccionada;
    });

    if (it != peliculas.end()) {
        std::cout << "Sinopsis: " << it->sinopsis << std::endl;
        darLike(it->titulo);
        agregarVerMasTarde(it->titulo);
    }

    std::cout << "Recomendaciones basadas en tus Likes:\n";
    std::vector<Pelicula> recomendaciones = recomendarPeliculas(peliculas);
    for (const auto& recomendacion : recomendaciones) {
        std::cout << recomendacion.titulo << std::endl;
    }

    return 0;
}
