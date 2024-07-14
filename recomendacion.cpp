#include "recomendacion.h"
#include <unordered_set>
#include <algorithm>

extern std::unordered_set<std::string> likes;

std::vector<Pelicula> recomendarPeliculas(const std::vector<Pelicula>& peliculas) {
    std::unordered_set<std::string> tagsLikes;
    for (const auto& titulo : likes) {
        auto it = std::find_if(peliculas.begin(), peliculas.end(), [&titulo](const Pelicula& p) {
            return p.titulo == titulo;
        });
        if (it != peliculas.end()) {
            tagsLikes.insert(it->tags.begin(), it->tags.end());
        }
    }

    std::vector<Pelicula> recomendaciones;
    for (const auto& pelicula : peliculas) {
        if (std::any_of(pelicula.tags.begin(), pelicula.tags.end(), [&tagsLikes](const std::string& tag) {
            return tagsLikes.find(tag) != tagsLikes.end();
        })) {
            recomendaciones.push_back(pelicula);
        }
    }
    return recomendaciones;
}
