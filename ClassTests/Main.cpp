#include <iostream>
#include <vector>
#include "Particle.h"
#include "Simulation.h"
#include "Vec.h"

int main(){
  std::cout << "Starting main" << std::endl;

  std::vector<Particle> ParticleArray(3,Particle());
  ParticleArray[1].setPosition(Vec(0,1,0));
  ParticleArray[2].setPosition(Vec(0,-1,0));
  ParticleArray[1].setVelocity(Vec(10.0,0,0));
  ParticleArray[2].setVelocity(Vec(-10.0,0,0));
  ParticleArray[0].setMass(100.0);

  Simulation S1(ParticleArray, 0.001);
  for(int i =0; i<100000; i++){
    std::cout << S1.getParticleArray()[1].getPosition();
    S1.step();
  }
  std::cout << "Ending main" << std::endl;
  return 0;
}
