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

void loadMovies(const std::string& filename) {
  try {
    std::vector<Utilities::Movie> movies = Utilities::readCSV(filename);
    MovieDB::MovieDatabase::getInstance().loadMovies(movies);
  } catch (const std::exception& e) {
    std::cerr << "Error al leer el archivo CSV: " << e.what() << std::endl;
    exit(EXIT_FAILURE);
  }
}

void displayMenu() {
  std::cout << "Elige una opción:\n";
  std::cout << "[1] Buscar por título\n[2] Buscar por tag\n[3] Ver películas que me gustaron\n[4] Salir\n";
}

int getUserChoice() {
  int choice;
  while (true) {
    std::cout << "Ingrese su opción: ";
    if (std::cin >> choice && choice >= 1 && choice <= 4) {
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpiar el buffer
      break;
    } else {
      std::cin.clear(); // Clear error flag
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
      std::cout << "Entrada inválida, por favor intente nuevamente.\n";
    }
  }
  return choice;
}

std::string getSearchKeyword() {
  std::string keyword;
  std::cout << "Ingrese una palabra o frase para buscar: ";
  std::getline(std::cin, keyword);
  return keyword;
}

std::string getSearchTag() {
  std::string tag;
  std::cout << "Ingrese un tag para buscar: ";
  std::getline(std::cin, tag);
  return tag;
}

void handleUserChoice(int choice, UI::UserInterface& ui) {
  switch (choice) {
    case 1: {
      std::string keyword = getSearchKeyword();
      Search::TitleSearchStrategy searchStrategy;
      auto results = searchStrategy.search(keyword);
      ui.displayMovies(results);
      break;
    }
    case 2: {
      std::string tag = getSearchTag();
      Search::TagSearchStrategy searchStrategy;
      auto results = searchStrategy.search(tag);
      ui.displayMovies(results);
      break;
    }
    case 3:
      ui.showLikedMovies();
      break;
    case 4:
      std::cout << "Saliendo del programa.\n";
      break;
  }
}

int main() {
#ifdef _WIN32
  setConsoleUTF8();
#endif

  loadMovies("mpst_full_data.csv");

  UI::UserInterface ui;
  ui.showLaterList();
  ui.showRecommendedMovies();

  int choice;
  do {
    displayMenu();
    choice = getUserChoice();
    handleUserChoice(choice, ui);
  } while (choice != 4);

  return 0;
}