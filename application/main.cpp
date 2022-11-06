#include <iostream>
#include <string>

#include "algorithm/algorithm.h"
#include "simulator/simulator.h"

int main(int argc, char *argv[]) {
  rwa2group9::Algorithm algo;

  std::cerr << algo << std::endl;

  // while (true) {
  //   if (Simulator::wasReset()) {
  //     std::cerr << "Simulator reset button pressed!" << std::endl;
  //     // Perform reset
  //     Simulator::ackReset();
  //   }
  // }
  return 0;
}
