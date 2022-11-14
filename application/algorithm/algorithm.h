#ifndef __ALGORITHM_H__
#define __ALGORITHM_H__

#include <array>
#include <memory>
#include <ostream>
#include <string>
#include <utility>
#include <vector>

#include "../cell/cell.h"
#include "../robot/robot.h"

namespace rwa2group9 {
class Algorithm {
public:
  void run(std::string direction);
  void init_outer_walls();
  void follow_wall_left();
  void follow_wall_right();
  void generate_goal();
  void set_right_wall();
  void set_left_wall();
  void set_front_wall();
  void reset();

  Algorithm();

  friend std::ostream& operator<<(std::ostream& os, const Algorithm& algo);
private:
  std::array<std::array<rwa2group9::Cell, 16>, 16> m_maze;
  std::unique_ptr<rwa2group9::Robot> robot;
  std::pair<int, int> goal;
  std::vector<std::pair<int, int>> path;
  int m_maze_height;
  int m_maze_width;

  void reset_members();
  void reset_simulator();
  void detect_walls();
  std::vector<std::pair<int, int>> remove_loops_in_path();
  void traceback_path(std::vector<std::pair<int, int>>& path);
};

std::ostream& operator<<(std::ostream& os, const Algorithm& algo);
} // namespace rwa2group9

#endif // __ALGORITHM_H__
