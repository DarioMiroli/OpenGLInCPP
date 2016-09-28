#include <iostream>
#include "DarGameEngine.h"

int main(){
  std::cout << std::endl << "Main" << std::endl;
  DarGameEngine D1 = DarGameEngine::getInstance();
  D1.createWindow(800,600);
  D1.bindShaderProgram();
  D1.initDrawing();

  while(!D1.closeDarGame()){
    D1.update();
  }



  return 0;
}
