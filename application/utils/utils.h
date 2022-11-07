#ifndef __UTILS_H__
#define __UTILS_H__

namespace rwa2group9 {
class Utils {
public:
  static char next_direction_left(char direction);
  static char next_direction_right(char direction);
  static int direction_to_int(char direction);
  static char int_to_direction(int direction_i);
};
}

#endif // __UTILS_H__
