#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include <array>
#include <memory>
#include <utility>

#include "../cell/cell.h"
#include "../robot/robot.h"

namespace rwa2group9 {
class Algorithm {
public:
  void run();
  void init_outer_walls();
  void follow_wall_left();
  void follow_wall_right();
  void generate_goal();
  void set_right_wall();
  void set_left_wall();
  void set_front_wall();

  Algorithm();

private:
  std::array<std::array<rwa2group9::Cell, 16>, 16> m_maze;
  std::unique_ptr<rwa2group9::Robot> robot;
  std::pair<int, int> goal;
  int m_maze_height;
  int m_maze_width;
};
} // namespace rwa2group9

#endif // __ALGORITHM_H__
