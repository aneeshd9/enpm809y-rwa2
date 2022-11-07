#include "robot.h"
#include "../simulator/simulator.h"
#include "../utils/utils.h"

#include <ostream>
#include <utility>

rwa2group9::Robot::Robot() {
  m_position = std::make_pair(0, 0);
  m_direction = 'n';
}

void rwa2group9::Robot::turn_left() {
  this->m_direction = rwa2group9::Utils::next_direction_left(this->m_direction);
  Simulator::turnLeft();
}

void rwa2group9::Robot::turn_right() {
  this->m_direction = rwa2group9::Utils::next_direction_right(this->m_direction);
  Simulator::turnRight();
}

void rwa2group9::Robot::move_forward() {
  if (this->m_direction == 'n') {
    this->m_position.second += 1;
  }
  else if (this->m_direction == 's') {
    this->m_position.second -= 1;
  }
  else if (this->m_direction == 'e') {
    this->m_position.first += 1;
  }
  else {
    this->m_position.first -= 1;
  }

  Simulator::moveForward();
}

std::pair<int, int> rwa2group9::Robot::at() {
  return this->m_position;
}

char rwa2group9::Robot::direction() {
  return this->m_direction;
}

std::ostream& rwa2group9::operator<<(std::ostream& os, const rwa2group9::Robot& robot) {
  os << "The robot is at (" << robot.m_position.first << ", " << robot.m_position.second
    << ") and is facing " << robot.m_direction << "!";
  return os;
}
