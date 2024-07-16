#ifndef SEARCH_STRATEGY_H
#define SEARCH_STRATEGY_H

#include "../utilities/movie.h"
#include "movie_database.h"
#include <string>
#include <vector>

namespace Search {

class SearchStrategy {
public:
  virtual ~SearchStrategy() = default;
  virtual std::vector<Utilities::Movie> search(const std::string &query) = 0;
};

} // namespace Search

#endif // SEARCH_STRATEGY_H
