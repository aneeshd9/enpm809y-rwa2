#include "robot.h"

#include <iostream>
#include <utility>

rwa2group9::Robot::Robot() {
  m_position = std::make_pair(0, 0);
  m_direction = 'n';
}

void rwa2group9::Robot::debug_print() const {
  std::cout << "The robot is at (" << this->m_position.first << ", "
    << this->m_position.second << ")" << std::endl;
  std::cout << "The direction of the robot is " << this->m_direction << std::endl;
}
