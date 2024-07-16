#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <functional>
#include <vector>

class Observable {
public:
  void addObserver(const std::function<void()> &observer) {
    observers.push_back(observer);
  }


private:
  std::vector<std::function<void()>> observers;
};

#endif // OBSERVABLE_H
