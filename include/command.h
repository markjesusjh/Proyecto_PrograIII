#ifndef COMMAND_H
#define COMMAND_H

#include "../utilities/movie.h"
#include "user_interface.h"

namespace UI {

class Command {
public:
  virtual ~Command() = default;
  virtual void execute() = 0;
};

class LikeCommand : public Command {
public:
  LikeCommand(UserInterface &ui, const Utilities::Movie &movie)
      : ui(ui), movie(movie) {}
  void execute() override { ui.selectMovie(movie); }

private:
  UserInterface &ui;
  Utilities::Movie movie;
};

class LaterCommand : public Command {
public:
  LaterCommand(UserInterface &ui, const Utilities::Movie &movie)
      : ui(ui), movie(movie) {}
  void execute() override { ui.selectMovie(movie); }

private:
  UserInterface &ui;
  Utilities::Movie movie;
};

} // namespace UI

#endif // COMMAND_H
