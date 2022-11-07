#include "algorithm.h"
#include "../simulator/simulator.h"
#include "../cell/cell.h"
#include "../robot/robot.h"
#include "../utils/utils.h"

#include <array>
#include <iostream>
#include <memory>
#include <ostream>
#include <string>
#include <utility>
#include <experimental/random>

rwa2group9::Algorithm::Algorithm() {
  std::cerr << "Initializing algorithm!" << std::endl;
  this->reset_members();
}

void rwa2group9::Algorithm::reset() {
  this->reset_members();
  this->reset_simulator();
}

void rwa2group9::Algorithm::reset_members() {
  for (int i = 0; i < this->m_maze.size(); ++i) {
    for (int j = 0; j < this->m_maze[i].size(); ++j) {
      this->m_maze[i][j] = rwa2group9::Cell();
    }
  }
  this->robot = std::make_unique<rwa2group9::Robot>();
  this->goal = std::make_pair(-1, -1);
  this->m_maze_height = Simulator::mazeHeight();
  this->m_maze_width = Simulator::mazeWidth();
}

void rwa2group9::Algorithm::reset_simulator() {
  Simulator::clearAllColor();
  Simulator::clearAllText();
}

void rwa2group9::Algorithm::generate_goal() {
  int x = -1, y = -1;
  x = std::experimental::randint(0, 15);
  if (x == 0 || x == 15) {
    y = std::experimental::randint(0, 15);
  } else {
    y = std::experimental::randint(0, 1) * 15;
  }

  this->goal = std::make_pair(x, y);
  Simulator::setText(x, y, "G");
  Simulator::setColor(x, y, 'r');
}

void rwa2group9::Algorithm::init_outer_walls() {
  for (int x = 0; x < this->m_maze_width; ++x) {
    this->m_maze.at(x).at(0).set_wall(2, true);
    this->m_maze.at(x).at(this->m_maze_height - 1).set_wall(0, true);
    Simulator::setWall(x, 0, 's');
    Simulator::setWall(x, this->m_maze_height - 1, 'n');
  }
  for (int y = 0; y < this->m_maze_height; ++y) {
    this->m_maze.at(0).at(y).set_wall(3, true);
    this->m_maze.at(this->m_maze_width - 1).at(y).set_wall(1, true);
    Simulator::setWall(0, y, 'w');
    Simulator::setWall(this->m_maze_width - 1, y, 'e');
  }
}

void rwa2group9::Algorithm::set_front_wall() {
  std::pair<int, int> pos = this->robot->at();
  char wall_direction = this->robot->direction();
  int wall_direction_i = rwa2group9::Utils::direction_to_int(wall_direction);
  Simulator::setWall(pos.first, pos.second, wall_direction);
  this->m_maze.at(pos.first).at(pos.second).set_wall(wall_direction_i, true);
}

void rwa2group9::Algorithm::set_left_wall() {
  std::pair<int, int> pos = this->robot->at();
  char wall_direction = rwa2group9::Utils::next_direction_left(this->robot->direction());
  int wall_direction_i = rwa2group9::Utils::direction_to_int(wall_direction);
  Simulator::setWall(pos.first, pos.second, wall_direction);
  this->m_maze.at(pos.first).at(pos.second).set_wall(wall_direction_i, true);
}

void rwa2group9::Algorithm::set_right_wall() {
  std::pair<int, int> pos = this->robot->at();
  char wall_direction = rwa2group9::Utils::next_direction_right(this->robot->direction());
  int wall_direction_i = rwa2group9::Utils::direction_to_int(wall_direction);
  Simulator::setWall(pos.first, pos.second, wall_direction);
  this->m_maze.at(pos.first).at(pos.second).set_wall(wall_direction_i, true);
}

void rwa2group9::Algorithm::detect_walls() {
  if (Simulator::wallFront()) {
    this->set_front_wall();
  }
  if (Simulator::wallLeft()) {
    this->set_left_wall();
  }
  if (Simulator::wallRight()) {
    this->set_right_wall();
  }
}

void rwa2group9::Algorithm::follow_wall_left() {
  std::pair<int, int> pos = this->robot->at();
  int x = pos.first;
  int y = pos.second;
  Cell current = this->m_maze.at(x).at(y);
  char forward_direction = this->robot->direction();
  char left_direction = rwa2group9::Utils::next_direction_left(forward_direction);
  char right_direction = rwa2group9::Utils::next_direction_right(forward_direction);

  if (!current.is_wall(rwa2group9::Utils::direction_to_int(left_direction))) {
    this->robot->turn_left();
    this->robot->move_forward();
  }
  else if (!current.is_wall(rwa2group9::Utils::direction_to_int(forward_direction))) {
    this->robot->move_forward();
  }
  else if (!current.is_wall(rwa2group9::Utils::direction_to_int(right_direction))) {
    this->robot->turn_right();
    this->robot->move_forward();
  }
  else {
    this->robot->turn_left();
    this->robot->turn_left();
    this->robot->move_forward();
  }
}

void rwa2group9::Algorithm::run(std::string direction) {
  std::cerr << *this << std::endl;

  this->generate_goal();
  this->init_outer_walls();

  while (this->robot->at() != this->goal) {
    if (Simulator::wasReset()) {
      std::cerr << "Simulator reset button pressed!" << std::endl;
      this->reset();
      Simulator::ackReset();
      this->generate_goal();
      this->init_outer_walls();
      std::cerr << *this << std::endl;
    }

    this->detect_walls();
    rwa2group9::Algorithm::follow_wall_left();
    std::cerr << *this << std::endl;
  }
}

std::ostream& rwa2group9::operator<<(std::ostream& os, const rwa2group9::Algorithm& algo) {
  os << "Current state is as follows:" << std::endl;
  os << *(algo.robot) << std::endl;
  os << "The goal is (" << algo.goal.first << ", " << algo.goal.second
    << ")" << std::endl;
  os << "The maze dimensions are (h, w): (" << algo.m_maze_height << ", "
    << algo.m_maze_width << ")" << std::endl;
  os << "The full state of the maze is:" << std::endl;
  for (int i = 0; i < algo.m_maze.size(); ++i) {
    for (int j = 0; j < algo.m_maze[i].size(); ++j) {
      os << algo.m_maze[i][j] << " ";
    }
    os << std::endl;
  }
  os << std::endl;
  return os;
}
