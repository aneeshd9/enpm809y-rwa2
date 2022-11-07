#ifndef __ROBOT_H__
#define __ROBOT_H__

#include <ostream>
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
  std::pair<int, int> at();
  char direction();

  Robot();

  friend std::ostream& operator<<(std::ostream& os, const Robot& robot);
};

std::ostream& operator<<(std::ostream& os, const Robot& robot);
} // namespace rwa2group9

#endif
