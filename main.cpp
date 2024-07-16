#include "include/command.h"
#include "include/movie_database.h"
#include "include/movie_factory.h"
#include "include/search_strategy.h"
#include "include/user_interface.h"
#include "utilities/movie.h"
#include "utilities/readCSV.h"
#include <iostream>
#include <vector>

#ifdef _WIN32
void setConsoleUTF8() {
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
}
#endif

int main() {
#ifdef _WIN32
  setConsoleUTF8();
#endif

  // Leer las películas del archivo CSV
  std::vector<Utilities::Movie> movies =
      Utilities::readCSV("mpst_full_data.csv");

  // Cargar las películas en la base de datos
  MovieDB::MovieDatabase::getInstance().loadMovies(movies);

  // Crear la interfaz de usuario
  UI::UserInterface ui;

  // Mostrar las películas "Ver más tarde"
  ui.showLaterList();

  // Mostrar películas recomendadas
  ui.showRecommendedMovies();

  // Interacción con el usuario
  while (true) {
    std::cout << "Elige una opción:\n";
    std::cout << "[1] Buscar por título\n[2] Buscar por tag\n[3] Ver películas "
                 "que me gustaron\n[4] Salir\n";
    int choice;
    std::cin >> choice;

    if (choice == 1) {
      std::string keyword;
      std::cout << "Ingrese una palabra o frase para buscar: ";
      std::cin.ignore();
      std::getline(std::cin, keyword);
      Search::TitleSearchStrategy searchStrategy;
      auto results = searchStrategy.search(keyword);
      ui.displayMovies(results); // Llama a la función pública
    } else if (choice == 2) {
      std::string tag;
      std::cout << "Ingrese un tag para buscar: ";
      std::cin.ignore();
      std::getline(std::cin, tag);
      Search::TagSearchStrategy searchStrategy;
      auto results = searchStrategy.search(tag);
      ui.displayMovies(results); // Llama a la función pública
    } else if (choice == 3) {
      ui.showLikedMovies();
    } else if (choice == 4) {
      break;
    }
  }

  return 0;
}
