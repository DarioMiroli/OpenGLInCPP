#ifndef ObjectClass
#define OBJECTCLASS

#include <iostream>
#include <vector>

class Particle{
  private:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> acceleration;
    std::vector<double> force;
    double mass;
    int id;
    static int Maxid;


  public:
    Particle(){
      init();
    }
    Particle(double x, double y){
        init();
        position[0] = x;
        position[1] = y;
    }
    void init(){
      position = {0,0,0};
      velocity = {0,0,0};
      acceleration = {0,0,0};
      force = {0,0,0};
      mass = 0;
      id = Maxid++;
    }
    void setPosition(std::vector<double> newPosition){
      position = newPosition;
    }
    void setVelocity(std::vector<double> newVelocity){
      velocity = newVelocity;
    }
    void setAcceleration(std::vector<double> newAcceleration){
      acceleration = newAcceleration;
    }
    void SetForces(std::vector<double> newForce){
      force = newForce;
    }
    void setMass(double newMass){
      mass = newMass;
    }
    void computeAcceleration(){
      for(int i = 0; i<3; i++){
          acceleration[i] = force[i]/mass;
      }
    }
    std::vector<double> getPosition(){
      return position;
    }
    std::vector<double> getVelocity(){
      return velocity;
    }
    std::vector<double> getAcceleration(){
      return acceleration;
    }
    std::vector<double> getForce(){
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
  out << "Position (" << particle.position[0] << " , " << particle.position[1] << " , " << particle.position[2] << ")" ;
  out << std::endl;
  out << "Velocity (" << particle.velocity[0] << " , " << particle.velocity[1] << " , " << particle.velocity[2] << ")" ;
  out << std::endl;
  out << "Acceleration (" << particle.acceleration[0] << " , " << particle.acceleration[1] << " , " << particle.acceleration[2] << ")" ;
  out << std::endl << "***********************" << std::endl;
  return out;
  }
  int Particle::Maxid = 1;

#endif
