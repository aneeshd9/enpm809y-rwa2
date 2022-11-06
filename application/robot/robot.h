#ifndef __ROBOT_H__
#define __ROBOT_H__

#pragma once

#include <utility>

namespace rwa2group9 {
class Robot {
private:
  std::pair<int, int> m_position;
  char m_direction;

public:
  void turn_left();
  void turn_right();
  void move_forward();

  Robot();

  void debug_print() const;
};
} // namespace rwa2group9

#endif
