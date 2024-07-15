#ifndef MOVIE_H
#define MOVIE_H

#include <string>

namespace Utilities {

struct Movie {
  std::string imdb_id;
  std::string title;
  std::string plot_synopsis;
  std::string tags;
  std::string split;
  std::string synopsis_source;

  bool operator<(const Movie &other) const { return imdb_id < other.imdb_id; }
  bool operator==(const Movie &other) const { return imdb_id == other.imdb_id; }
};

} // namespace Utilities

#endif // MOVIE_H
