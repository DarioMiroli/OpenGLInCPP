#include <iostream>
#include "Particle.h"

int main(){
  std::cout << "Starting main" << std::endl;
  Particle P1 {};
  std::cout << P1.getMass() << std::endl;
  std::cout << P1.getPosition()[0] << std::endl;
  return 0;
}
