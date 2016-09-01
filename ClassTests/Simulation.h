#ifndef SIMULATION
#define SIMULATION

#include <iostream>
#include <vector>
#include "Particle.h"
#include <cmath>

class Simulation{
  private:
    std::vector<Particle> ParticleArray;
    std::vector<std::vector<Vec>> ForcesArray;
    int NumberOfParticles;
    double gravConstant;
    double timeStep;
  public:
  Simulation(std::vector<Particle> newParticleArray, double timeStep){
    ParticleArray = newParticleArray;
    NumberOfParticles = newParticleArray.size();
    ForcesArray = std::vector<std::vector<Vec>>(NumberOfParticles, std::vector<Vec>(NumberOfParticles,Vec()));
    gravConstant = 1.0;
    this->timeStep = timeStep;
  }


  void step(){
      computeGravitationalForces();
      updateGravitationalForces();
      for(int i=0; i < NumberOfParticles; i++){
        updateAccelerations();
        updateVelocities();
        updatePositions();
      }
  }

  void computeGravitationalForces(){
    for(int i = 0; i < NumberOfParticles; i++ ){
      for(int j=0; j < NumberOfParticles; j++){
        if (i != j){
          Particle P1 = ParticleArray[i];
          Particle P2 = ParticleArray[j];
          Vec r = Vec::subtract(P1.getPosition(),P2.getPosition());
          double rmag = -1.0 * r.getMag();
          double alpha = (gravConstant*P1.getMass()*P2.getMass())/pow(rmag,3);
          Vec forceVector = Vec::scalarMultiply(alpha,r);
          ForcesArray[i][j] = forceVector;

        }
      }
    }
  }

  void updateGravitationalForces(){
      Vec summedForce;
      for(int i=0; i<NumberOfParticles;i++){
        summedForce = Vec();
        for(int j=0; j<NumberOfParticles; j++){
          summedForce = Vec::add(summedForce,ForcesArray[i][j]);
        }
        ParticleArray[i].SetForce(summedForce);
      }
  }

  void updateAccelerations(){
    for(int i=0; i< NumberOfParticles; i++){
      ParticleArray[i].computeAcceleration();
    }
  }

  void updateVelocities(){
    for(int i=0; i< NumberOfParticles; i++){
      Particle P = ParticleArray[i];
      Vec newVelocity = Vec::add(P.getVelocity(),Vec::scalarMultiply(timeStep,P.getAcceleration()));
      ParticleArray[i].setVelocity(newVelocity);
    }
  }

  void updatePositions(){
    for(int i=0; i< NumberOfParticles; i++){
      Particle P = ParticleArray[i];
      Vec newPosition = Vec::add(P.getPosition(),Vec::scalarMultiply(timeStep,P.getVelocity()));
      ParticleArray[i].setPosition(newPosition);
    }
  }

  std::vector<Particle> getParticleArray(){
    return ParticleArray;
  }


};

#endif
