#ifndef MOVIE_FACTORY_H
#define MOVIE_FACTORY_H

class MovieFactory {
public:
  static Movie createMovie(const std::string &imdb_id, const std::string &title,
                           const std::string &plot_synopsis, const std::string &tags) {
    return Movie{imdb_id, title, plot_synopsis, tags};
  }
};

#endif // MOVIE_FACTORY_H
