#ifndef DARGAME
#define DARGAME
#include <iostream>
#include <vector>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class DarGameEngine {
  private:
    static bool instanceFlag;
    static DarGameEngine *engineInstance;
    GLFWwindow* window;
    int screenWidth;
    int screenHeight;
    DarGameEngine();
    void init();
    void updateVBO();
    GLuint VAO;
    GLuint shaderProgram;

  public:
    GLfloat vertices[9] {0,0,0,0,0,0,0,0,0};
    static DarGameEngine getInstance();
    void createWindow(int screenWidth,int screenHeight);
    void bindShaderProgram();
    void initDrawing();
    bool closeDarGame();
    void update();
    int getScreenWidth();
    int getScreenHeight();


};
#endif
