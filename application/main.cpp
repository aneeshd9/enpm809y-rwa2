#include <iostream>
#include <string>

#include "algorithm/algorithm.h"

int main(int argc, char *argv[]) {
  std::string direction;
  if (argc > 1) {
    std::string argv1 {argv[1]};
    if (argv1 == "-right") {
      direction = "right";
    }
    else {
      direction = "left";
    }
  }

  rwa2group9::Algorithm algo;
  algo.run(direction);

  return 0;
}
