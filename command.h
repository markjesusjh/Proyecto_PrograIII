#ifndef COMMAND_H
#define COMMAND_H

class Command {
public:
  virtual ~Command() = default;
  virtual void execute() = 0;
};

class LikeCommand : public Command {
public:
  LikeCommand(UserInterface &ui, const Movie &movie) : ui(ui), movie(movie) {}
  void execute() override { ui.selectMovie(movie); }

private:
  UserInterface &ui;
  Movie movie;
};

#endif // COMMAND_H
