#ifndef MOVIE_FACTORY_H
#define MOVIE_FACTORY_H

#include "../utilities/movie.h"

namespace Utilities {

class MovieFactory {
public:
  static Movie createMovie(const std::string &imdb_id, const std::string &title,
                           const std::string &plot_synopsis,
                           const std::string &tags, const std::string &split,
                           const std::string &synopsis_source) {
    return Movie{imdb_id, title, plot_synopsis, tags, split, synopsis_source};
  }
};

} // namespace Utilities

#endif // MOVIE_FACTORY_H
