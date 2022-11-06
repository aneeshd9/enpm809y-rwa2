#ifndef __CELL_H__
#define __CELL_H__

#pragma once

#include <array>
#include <ostream>

namespace rwa2group9 {
class Cell {
public:
  void init_cell_walls();
  void set_wall(int wall, bool is_wall);
  bool is_wall(int wall);

  friend std::ostream& operator<<(std::ostream& str, const Cell& cell);

  Cell();
private:
  std::array<bool, 4> m_walls;
};

std::ostream& operator<<(std::ostream& str, const Cell& cell);
} // namespace rwa2group9

#endif // __CELL_H__
