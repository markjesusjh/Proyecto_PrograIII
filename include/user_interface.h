#ifndef USER_INTERFACE_H
#define USER_INTERFACE_H

#include "movie_database.h"
#include "observable.h"
#include <fstream>
#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

namespace UI {

class UserInterface : public Observable {
public:
  UserInterface() {
    loadLaterList();
    loadLikedMovies();
  }

  ~UserInterface() {
    saveLaterList();
    saveLikedMovies();
  }

  void showLaterList() const {
    clearConsole();
    std::cout << "\033[1;36mPelículas para ver más tarde:\033[0m\n";
    for (const auto &movie : laterList) {
      std::cout << "\033[1;33m" << movie.title << "\033[0m (" << movie.imdb_id
                << ")\n";
    }
    pauseConsole();
  }

  void showLikedMovies() const {
    clearConsole();
    std::cout << "\033[1;36mPelículas que te gustaron:\033[0m\n";
    for (const auto &movie : likedMovies) {
      std::cout << "\033[1;33m" << movie.title << "\033[0m (" << movie.imdb_id
                << ")\n";
    }
    pauseConsole();
  }

  void showRecommendedMovies() const {
    std::unordered_set<std::string> likedTags;
    for (const auto &movie : likedMovies) {
      auto tags = splitTags(movie.tags);
      likedTags.insert(tags.begin(), tags.end());
    }

    auto similarMovies =
        MovieDB::MovieDatabase::getInstance().getSimilarMovies(likedTags);
    clearConsole();
    std::cout
        << "\033[1;36mPelículas recomendadas basadas en tus gustos:\033[0m\n";
    for (const auto &movie : similarMovies) {
      std::cout << "\033[1;33m" << movie.title << "\033[0m (" << movie.imdb_id
                << ")\n";
    }
    pauseConsole();
  }

  void searchAndDisplayMovies(const std::string &keyword) {
    auto results = MovieDB::MovieDatabase::getInstance().searchByTitle(keyword);
    displayMovies(results);
  }

  void searchAndDisplayMoviesByTag(const std::string &tag) {
    auto results = MovieDB::MovieDatabase::getInstance().searchByTag(tag);
    displayMovies(results);
  }

  void selectMovie(const Utilities::Movie &movie) {
    clearConsole();
    std::cout << "\033[1;36mSinopsis de la película \033[1;33m" << movie.title
              << "\033[0m:\n"
              << movie.plot_synopsis << "\n";
    std::cout << "\033[1;32m[1] Like\n[2] Ver más tarde\n[3] Volver\033[0m\n";
    int choice;
    std::cin >> choice;
    if (choice == 1) {
      likedMovies.insert(movie);
      notifyObservers();
    } else if (choice == 2) {
      laterList.insert(movie);
      notifyObservers();
    }
    clearConsole();
  }

  void displayMovies(
      const std::vector<Utilities::Movie> &movies) { // Mover a sección pública
    int page = 0;
    int perPage = 5;
    while (true) {
      clearConsole();
      int start = page * perPage;
      int endIndexMovie =
          (std::min)(start + perPage, static_cast<int>(movies.size()));
      if (start >= endIndexMovie) {
        std::cout << "\033[1;31mNo hay más resultados.\033[0m\n";
        pauseConsole();
        break;
      }
      for (int i = start; i < endIndexMovie; ++i) {
        std::cout << "\033[1;33m[" << i + 1 << "] " << movies[i].title
                  << "\033[0m (" << movies[i].imdb_id << ")\n";
      }
      std::cout << "\033[1;32m[n] Siguiente página, [q] Salir, [#] Seleccionar "
                   "número\033[0m\n";
      std::string choice;
      std::cin >> choice;
      if (choice == "q")
        break;
      if (choice == "n")
        ++page;
      else {
        int index = std::stoi(choice) - 1;
        if (index >= start && index < endIndexMovie) {
          selectMovie(movies[index]);
          clearConsole();
        }
      }
    }
  }

private:
  std::set<Utilities::Movie> likedMovies;
  std::set<Utilities::Movie> laterList;

  void saveLaterList() const {
    std::ofstream file("later_list.txt");
    for (const auto &movie : laterList) {
      file << movie.imdb_id << "\n";
    }
  }

  void loadLaterList() {
    std::ifstream file("later_list.txt");
    std::string imdb_id;
    while (std::getline(file, imdb_id)) {
      laterList.insert(
          MovieDB::MovieDatabase::getInstance().getMovieById(imdb_id));
    }
  }

  void saveLikedMovies() const {
    std::ofstream file("liked_movies.txt");
    for (const auto &movie : likedMovies) {
      file << movie.imdb_id << "\n";
    }
  }

  void loadLikedMovies() {
    std::ifstream file("liked_movies.txt");
    std::string imdb_id;
    while (std::getline(file, imdb_id)) {
      likedMovies.insert(
          MovieDB::MovieDatabase::getInstance().getMovieById(imdb_id));
    }
  }

  std::vector<std::string> splitTags(const std::string &tags) const {
    std::vector<std::string> result;
    size_t start = 0, end = 0;
    while ((end = tags.find(", ", start)) != std::string::npos) {
      result.push_back(tags.substr(start, end - start));
      start = end + 2;
    }
    result.push_back(tags.substr(start));
    return result;
  }

  void clearConsole() const {
#ifdef _WIN32
    system("cls");
#else
    std::cout << "\033[2J\033[1;1H";
#endif
  }

  void pauseConsole() const {
    std::cout << "\n\033[1;31mPresiona Enter para continuar...\033[0m\n";
    std::cin.ignore();
    std::cin.get();
  }
};

} // namespace UI

#endif // USER_INTERFACE_H
