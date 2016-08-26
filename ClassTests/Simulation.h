#ifndef SIMULATION
#define SIMULATION

#include <iostream>
#include <vector>
#include "Particle.h"
#include <cmath>

class Simulation{
  private:
    std::vector<Particle> ParticleArray;
    std::vector< std::vector<std::vector<double> > > ForcesArray;
    int NumberOfParticles;
    double gravConstant;

  Simulation(std::vector<Particle> newParticleArray){
    ParticleArray = newParticleArray;
    NumberOfParticles = newParticleArray.size();
    ForcesArray = std::vector<std::vector<std::vector<double>>>(NumberOfParticles, std::vector<std::vector<double>>(NumberOfParticles, std::vector<double>(3)));
    gravConstant = 1.0;
  }

  void computeGravitationalForces(){
    for(int i = 0; i < NumberOfParticles; i++ ){
      for(int j=0; j < NumberOfParticles; j++){
        if (i != j){
          std::vector<double> r(0,3);
          std::vector<double> force(0,3);
          for(int k=0; k<3;k++){
            r[k] = ParticleArray[i].getPosition()[k] - ParticleArray[j].getPosition()[k];
          }
          double magrSquared = r[0]*r[0] + r[1]*r[1] + r[2]*r[2];
          double magr = pow(magrSquared,0.5);
          double coefficient = (ParticleArray[i].getMass()*ParticleArray[j].getMass()*gravConstant)/magrSquared;
          for(int l =0; l<3;l++){force[l] = (coefficient* r[l])/magr;}
          ForcesArray[i][j] = force;

        }
      }
    }
  }


};

#endif
