#ifndef OBJECTCLASS
#define OBJECTCLASS

#include <iostream>
#include <vector>
#include "Vec.h"

class Particle{
  private:
    Vec position;
    Vec velocity;
    Vec acceleration;
    Vec force;
    double mass;
    int id;
    static int Maxid;


  public:
    Particle(){
      init();
    }
    Particle(double x, double y,double z){
        init();
        position.setComponents(x,y,z);
    }
    void init(){
      position = Vec() ;
      velocity = Vec();
      acceleration = Vec();
      force = Vec();
      mass = 1;
      id = Maxid++;
    }
    void setPosition(std::vector<double> newPosition){
      position = Vec(newPosition);
    }
    void setPosition(Vec newPosition){
      position = newPosition;
    }
    void setVelocity(std::vector<double> newVelocity){
      velocity = Vec(newVelocity);
    }
    void setVelocity(Vec newVelocity){
      velocity = newVelocity;
    }
    void setAcceleration(std::vector<double> newAcceleration){
      acceleration = Vec(newAcceleration);
    }
    void SetForce(std::vector<double> newForce){
      force = Vec(newForce);
    }
    void SetForce(Vec newForce){
      force = newForce;
    }
    void setMass(double newMass){
      mass = newMass;
    }
    void computeAcceleration(){
      acceleration = Vec::scalarMultiply(1.0/mass, force);
    }
    Vec getPosition(){
      return position;
    }
    Vec getVelocity(){
      return velocity;
    }
    Vec getAcceleration(){
      return acceleration;
    }
    Vec getForce(){
      return force;
    }
    double getMass(){
      return mass;
    }
    friend std::ostream& operator<< (std::ostream &out, const Particle &particle);

  };
  // Out of class stuff initialisation of static variables and friend funcitons
  std::ostream& operator<< (std::ostream &out, const Particle &particle){
  out << std::endl << "***********************" << std::endl;
  out << "Particle ID: " << particle.id << "  Mass: " << particle.mass ;
  out << std::endl;
  out << "Position: " << particle.position;
  out << "Velocity: " << particle.velocity;
  out << "Acceleration: " << particle.acceleration;
  out << "Force: " << particle.force;
  out << "***********************" << std::endl;
  return out;
  }
  int Particle::Maxid = 1;

#endif
