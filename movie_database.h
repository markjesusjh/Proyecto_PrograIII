
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class MovieDatabase {
public:
  static MovieDatabase &getInstance() {
    static MovieDatabase instance;
    return instance;
  }

  void loadMovies(const std::vector<Movie> &movies) {
    for (const auto &movie : movies) {
      moviesById[movie.imdb_id] = movie;
      moviesByTitle[movie.title].push_back(movie);
    }
  }

  std::vector<Movie> searchByTitle(const std::string &title) const {
    if (moviesByTitle.find(title) != moviesByTitle.end()) {
      return moviesByTitle.at(title);
    }
    return {};
  }

  Movie getMovieById(const std::string &id) const { return moviesById.at(id); }

private:
  MovieDatabase() = default;
  MovieDatabase(const MovieDatabase &) = delete;
  MovieDatabase &operator=(const MovieDatabase &) = delete;

  std::unordered_map<std::string, Movie> moviesById;
  std::unordered_map<std::string, std::vector<Movie>> moviesByTitle;
};

#endif // MOVIE_DATABASE_H
