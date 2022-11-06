#include "algorithm.h"
#include "../simulator/simulator.h"
#include "../cell/cell.h"
#include "../robot/robot.h"

#include <array>
#include <iostream>
#include <memory>
#include <ostream>
#include <utility>

rwa2group9::Algorithm::Algorithm() {
  std::cerr << "Initializing algorithm!" << std::endl;
  this->reset_members();
}

void rwa2group9::Algorithm::reset() {
  this->reset_members();
}

void rwa2group9::Algorithm::reset_members() {
  for (int i = 0; i < this->m_maze.size(); ++i) {
    for (int j = 0; j < this->m_maze[i].size(); ++j) {
      this->m_maze[i][j] = rwa2group9::Cell();
    }
  }
  this->robot = std::make_unique<rwa2group9::Robot>();
  this->goal = std::make_pair(-1, -1);
  this->m_maze_height = 0;
  this->m_maze_width = 0;
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
