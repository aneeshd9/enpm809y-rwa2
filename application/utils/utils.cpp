#include "utils.h"

char rwa2group9::Utils::next_direction_left(char direction) {
  if (direction == 'n') {
    return 'w';
  }
  else if (direction == 'w') {
    return 's';
  }
  else if (direction == 's') {
    return 'e';
  }
  else {
    return 'n';
  }
}

char rwa2group9::Utils::next_direction_right(char direction) {
  if (direction == 'n') {
    return 'e';
  }
  else if (direction == 'e') {
    return 's';
  }
  else if (direction == 's') {
    return 'w';
  }
  else {
    return 'n';
  }
}

char rwa2group9::Utils::int_to_direction(int direction_i) {
  if (direction_i == 0) {
    return 'n';
  }
  else if (direction_i == 1) {
    return 'e';
  }
  else if (direction_i == 2) {
    return 's';
  }
  else {
    return 'w';
  }
}

int rwa2group9::Utils::direction_to_int(char direction) {
  if (direction == 'n') {
    return 0;
  }
  else if (direction == 'e') {
    return 1;
  }
  else if (direction == 's') {
    return 2;
  }
  else {
    return 3;
  }
}
