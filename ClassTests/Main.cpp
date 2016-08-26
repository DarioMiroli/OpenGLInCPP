#include <iostream>
#include <vector>
#include "Particle.h"

int main(){
  std::cout << "Starting main" << std::endl;
  std::vector<Particle> ParticleArray(10);
  for(int i=0; i < ParticleArray.size(); i++){
    std::cout <<  ParticleArray[i];
  }
  return 0;
}
