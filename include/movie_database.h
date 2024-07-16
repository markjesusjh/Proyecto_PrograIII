#ifndef MOVIE_DATABASE_H
#define MOVIE_DATABASE_H

#include "../utilities/movie.h"
#include <algorithm>
#include <future>
#include <regex>
#include <sstream>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace MovieDB {

class MovieDatabase {
public:
  static MovieDatabase &getInstance() {
    static MovieDatabase instance;
    return instance;
  }

  void loadMovies(const std::vector<Utilities::Movie> &movies) {
    for (const auto &movie : movies) {
      moviesById[movie.imdb_id] = movie;
      moviesByTitle[toLowerCase(movie.title)].push_back(movie);
      auto tags = splitTags(movie.tags);
      for (const auto &tag : tags) {
        moviesByTag[toLowerCase(tag)].push_back(movie);
      }
    }
  }

  template <typename T>
  std::vector<Utilities::Movie> search(const T &data,
                                       const std::string &query) const {
    std::string lowerQuery = toLowerCase(query);
    std::vector<Utilities::Movie> results;
    std::regex wordRegex("\\b" + lowerQuery +
                         "\\b"); // Regex para coincidencia exacta de palabra

    std::vector<std::future<std::vector<Utilities::Movie>>> futures;
    for (const auto &pair : data) {
      futures.push_back(std::async(std::launch::async, [&pair, &wordRegex]() {
        std::vector<Utilities::Movie> localResults;
        if (std::regex_search(pair.first, wordRegex)) {
          localResults.insert(localResults.end(), pair.second.begin(),
                              pair.second.end());
        }
        return localResults;
      }));
    }

    for (auto &future : futures) {
      auto localResults = future.get();
      results.insert(results.end(), localResults.begin(), localResults.end());
    }

    return results;
  }

  std::vector<Utilities::Movie> searchByTitle(const std::string &title) const {
    return search(moviesByTitle, title);
  }

  std::vector<Utilities::Movie> searchByTag(const std::string &tag) const {
    return search(moviesByTag, tag);
  }

  std::vector<Utilities::Movie>
  getSimilarMovies(const std::unordered_set<std::string> &likedTags) const {
    std::vector<Utilities::Movie> similarMovies;
    for (const auto &tag : likedTags) {
      auto moviesWithTag = searchByTag(tag);
      similarMovies.insert(similarMovies.end(), moviesWithTag.begin(),
                           moviesWithTag.end());
    }
    std::sort(similarMovies.begin(), similarMovies.end(),
              [](const Utilities::Movie &a, const Utilities::Movie &b) {
                return a.title < b.title;
              });
    auto last = std::unique(similarMovies.begin(), similarMovies.end());
    similarMovies.erase(last, similarMovies.end());

    // Limitar a las top 10 películas
    if (similarMovies.size() > 10) {
      similarMovies.resize(10);
    }

    return similarMovies;
  }

  Utilities::Movie getMovieById(const std::string &id) const {
    return moviesById.at(id);
  }

private:
  MovieDatabase() = default;
  MovieDatabase(const MovieDatabase &) = delete;
  MovieDatabase &operator=(const MovieDatabase &) = delete;

  std::unordered_map<std::string, Utilities::Movie> moviesById;
  std::unordered_map<std::string, std::vector<Utilities::Movie>> moviesByTitle;
  std::unordered_map<std::string, std::vector<Utilities::Movie>> moviesByTag;

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

  std::string toLowerCase(const std::string &str) const {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(),
                   ::tolower);
    return lowerStr;
  }
};

} // namespace MovieDB

#endif // MOVIE_DATABASE_H
