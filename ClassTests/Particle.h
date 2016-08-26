#ifndef ObjectClass
#define OBJECTCLASS

#include <vector>

class Particle{
  private:
    std::vector<double> position;
    std::vector<double> velocity;
    std::vector<double> acceleration;
    std::vector<double> force;
    double mass;

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

};

#endif
