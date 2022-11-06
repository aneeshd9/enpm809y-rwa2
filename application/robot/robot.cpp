#include "robot.h"

#include <ostream>
#include <utility>

rwa2group9::Robot::Robot() {
  m_position = std::make_pair(0, 0);
  m_direction = 'n';
}

std::ostream& rwa2group9::operator<<(std::ostream& os, const rwa2group9::Robot& robot) {
  os << "The robot is at (" << robot.m_position.first << ", " << robot.m_position.second
    << ") and is facing " << robot.m_direction << "!";
  return os;
}
