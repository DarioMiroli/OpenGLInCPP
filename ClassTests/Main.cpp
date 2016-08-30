#include <iostream>
#include <vector>
#include "Particle.h"
#include "Vec.h"

int main(){
  std::cout << "Starting main" << std::endl;

  Vec v1(1,2,3);
  Vec v2(4,5,6);

  std::cout << v1 << v2;
  std::cout << v1.getMag();
  v1.scalarMultiply(10.0);
  std::cout << std::endl << v1 << std::endl;
  std::cout << Vec::add(v1,v2);
  std::cout << Vec::subtract(v1,v2);
  std::cout << std::endl << "End of program" << std::endl;
  return 0;
}
