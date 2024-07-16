#ifndef READCSV_H
#define READCSV_H

#include "../lib/rapidcsv.h"
#include "movie.h"
#include <vector>
#include <iostream>

namespace Utilities {

std::vector<Movie> readCSV(const std::string& filename) {
  std::vector<Movie> movies;

  try {
    // Leer el documento CSV
    rapidcsv::Document doc(filename, rapidcsv::LabelParams(0, -1),
                           rapidcsv::SeparatorParams(',', true, '"', true));

    // Validar si el archivo tiene las columnas esperadas
    std::vector<std::string> expectedColumns = {
        "imdb_id", "title", "plot_synopsis", "tags", "split", "synopsis_source"};

    for (const auto& col : expectedColumns) {
      if (doc.GetColumnIdx(col) == static_cast<size_t>(-1)) {
        throw std::runtime_error("Column not found: " + col);
      }
    }

    size_t rowCount = doc.GetRowCount();

    // Leer y almacenar cada fila como una película
    for (size_t i = 0; i < rowCount; ++i) {
      Movie movie;
      movie.imdb_id = doc.GetCell<std::string>("imdb_id", i);
      movie.title = doc.GetCell<std::string>("title", i);
      movie.plot_synopsis = doc.GetCell<std::string>("plot_synopsis", i);
      movie.tags = doc.GetCell<std::string>("tags", i);
      movie.split = doc.GetCell<std::string>("split", i);
      movie.synopsis_source = doc.GetCell<std::string>("synopsis_source", i);
      movies.push_back(movie);
    }
  } catch (const std::exception& e) {
    std::cerr << "Error leyendo el archivo CSV: " << e.what() << std::endl;
  }

  return movies;
}

} // namespace Utilities

#endif // READCSV_H

