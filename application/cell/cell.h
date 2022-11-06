#ifndef __CELL_H__
#define __CELL_H__

#pragma once

#include <array>

namespace rwa2group9 {
class Cell {
public:
  void init_cell_walls();
  void set_wall(int wall, bool is_wall);
  bool is_wall(int wall);

  Cell();
private:
  std::array<bool, 4> m_walls;
};
} // namespace rwa2group9

#endif // __CELL_H__
