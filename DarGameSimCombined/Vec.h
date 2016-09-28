#ifndef VEC
#define VEC

#include <iostream>
#include <vector>
#include <cmath>

class Vec{
  static int dimensions;
  private:
    std::vector<double> m_vector;
  public:

    Vec(){
      m_vector = std::vector<double>(dimensions);
    }

    Vec(double x, double y, double z){
      m_vector = std::vector<double> {x,y,z};
    }

    std::vector<double> getComponents(){
      return m_vector;
    }

    Vec(std::vector<double> v1){
      m_vector = v1;
    }

    void setComponents(double x, double y, double z){
      m_vector[0]=x;
      m_vector[1]=y;
      m_vector[2]=z;
    }

    double getComponent(int i){
      return m_vector[i];
    }

    double getMag(){
      double magSquared = pow(m_vector[0],2) + pow(m_vector[1],2) + pow(m_vector[2],2);
      return pow(magSquared,0.5);
    }

    void scalarMultiply(double scalar){
      for(int i=0; i<dimensions;i++){
        m_vector[i] = m_vector[i]*scalar;
      }
    }

    static Vec scalarMultiply(double scalar, Vec v1){
      Vec v2 = Vec();
      for(int i=0; i<dimensions;i++){
        v2.m_vector[i] = v1.m_vector[i]*scalar;
      }
      return v2;
    }

    static Vec add(Vec v1, Vec v2){
      std::vector<double> v3 = std::vector<double>(dimensions);
      for(int i=0; i<dimensions; i++){
        v3[i] = v1.m_vector[i] + v2.m_vector[i];
      }
      return Vec(v3[0],v3[1],v3[2]);
    }

    static Vec subtract(Vec v1, Vec v2){
      v2.scalarMultiply(-1.0);
      Vec v3 = Vec::add(v1,v2);
      return v3;

    }
    friend std::ostream& operator<< (std::ostream &out, const Vec &vec);
};

//Out of class stuff
std::ostream& operator<< (std::ostream &out, const Vec &vec){
out << "Vec_(" << vec.m_vector[0] << " , " << vec.m_vector[1] << " , " << vec.m_vector[2];
out << ")" << std::endl;
return out;
}
int Vec::dimensions = 3;

#endif
