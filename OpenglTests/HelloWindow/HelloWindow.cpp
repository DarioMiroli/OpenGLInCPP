#include <iostream>
#include <vector>
// GLEW
#define GLEW_STATIC
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);


int main(){
  //Init stuff
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);

  //Create window
  GLFWwindow *window = glfwCreateWindow(800,600, "Learning OpenGL", nullptr, nullptr);
  if(window == nullptr){
      std::cout << "Failed to create GLFW window" << std::endl;
      glfwTerminate();
      return -1;
  }
  glfwMakeContextCurrent(window);

  //Initialise GLEW
  glewExperimental = GL_TRUE;
  if(glewInit() != GLEW_OK){
      std::cout << "Failed to initialise GLEW" << std::endl;
      return -1;
  }
  glViewport(0,0,800,600);

  //Set up user inputs
  glfwSetKeyCallback(window, key_callback);

  // Run the program
  while(!glfwWindowShouldClose(window)){
    glfwPollEvents();
    glClearColor(0.2f,0.3f,0.3f,1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window);
  }

  //Clean up
  glfwTerminate();
  return 0;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode){
  // When a user presses the escape key, we set the WindowShouldClose property to true,
  // closing the application
  if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
  glfwSetWindowShouldClose(window, GL_TRUE);
}
