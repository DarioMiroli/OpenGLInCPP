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
    GLfloat vertices[6] { -0.5,0,0,0.5,0,0};
    DarGameEngine();
    void init();
    void updateVBO();
    GLuint VAO;
    GLuint shaderProgram;

  public:
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
