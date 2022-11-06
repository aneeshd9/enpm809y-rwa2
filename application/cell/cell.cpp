#include "cell.h"

#include <stdexcept>

rwa2group9::Cell::Cell() {
  for (int i = 0; i < this->m_walls.size(); ++i) {
    this->m_walls[i] = false;
  }
}

void rwa2group9::Cell::init_cell_walls() {
  for (int i = 0; i < this->m_walls.size(); ++i) {
    this->m_walls[i] = false;
  }
}

bool rwa2group9::Cell::is_wall(int wall) {
  if (wall < 0 || wall > 3) {
    throw std::runtime_error("Wall has to be in [0, 3] range!");
  }
  return this->m_walls[wall];
}

void rwa2group9::Cell::set_wall(int wall, bool is_wall) {
  if (wall < 0 || wall > 3) {
    throw std::runtime_error("Wall has to be in [0, 3] range!");
  }
  this->m_walls[wall] = is_wall;
}
