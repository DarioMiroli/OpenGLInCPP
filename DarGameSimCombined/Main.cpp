#include <iostream>
#include "DarGameEngine.h"
#include "Simulation.h"
#include "Vec.h"
#include "Particle.h"
#include <stdlib.h>
int main(){
  std::cout << std::endl << "Main" << std::endl;
  DarGameEngine D1 = DarGameEngine::getInstance();
  D1.createWindow(800,600);
  D1.bindShaderProgram();
  D1.initDrawing();

  std::vector<Particle> ParticleArray(3,Particle());
  ParticleArray[1].setPosition(Vec(0,1,0));
  ParticleArray[2].setPosition(Vec(0,-1,0));
  ParticleArray[1].setVelocity(Vec(10.0,0,0));
  ParticleArray[2].setVelocity(Vec(-10.0,0,0));
  ParticleArray[0].setMass(100.0);

  Simulation S1(ParticleArray, 0.0005);


  while(!D1.closeDarGame()){
    _sleep(1);
    D1.update();
    S1.step();
    for(int i =0; i<3;i++){
      D1.vertices[i] = S1.getParticleArray()[1].getPosition().getComponent(i)/2.0;
      D1.vertices[i+3] = S1.getParticleArray()[2].getPosition().getComponent(i)/2.0;
      D1.vertices[i+6] = S1.getParticleArray()[0].getPosition().getComponent(i)/2.0;

    }
  }



  return 0;
}
