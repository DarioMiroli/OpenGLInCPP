#include "DarGameEngine.h"

DarGameEngine::DarGameEngine(){
  init();
}

void DarGameEngine::init(){
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_RESIZABLE,GL_FALSE);
}

void DarGameEngine::createWindow(int screenWidth, int screenHeight){
  this->window = glfwCreateWindow(800,600, "Learning OpenGL", nullptr, nullptr);
  if(window == nullptr){
      std::cout << "Failed to create GLFW window" << std::endl;
      glfwTerminate();
      this->window = window;
  }
  glfwMakeContextCurrent(this->window);
  //Initialise GLEW
  glewExperimental = GL_TRUE;
  if(glewInit() != GLEW_OK){
      std::cout << "Failed to initialise GLEW" << std::endl;
  }
  glViewport(0,0,screenWidth,screenHeight);
}

DarGameEngine DarGameEngine::getInstance(){
  if(!instanceFlag){
    DarGameEngine::engineInstance = new DarGameEngine();
    instanceFlag = true ;
    return *DarGameEngine::engineInstance;
  }
  else{
    return *DarGameEngine::engineInstance;
  }
}

void DarGameEngine::bindShaderProgram(){
  const GLchar* vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 position;\n"
    "void main()\n"
    "{\n"
    "  gl_PointSize = 10.0; \n"
    "gl_Position = vec4(position.x, position.y, position.z, 1.0);\n"
    "}\0";

  const GLchar* fragmentShaderSource = "#version 330 core\n"
      "out vec4 color;\n"
      "void main()\n"
      "{\n"
      "color = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
      "}\n\0";

    GLuint vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    GLint success;
    GLchar infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS,&success);
    if (!success){
      glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    GLuint fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader,1, &fragmentShaderSource,NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS,&success);
    if (!success){
      glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
      std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram,vertexShader);
    glAttachShader(shaderProgram,fragmentShader);
    glLinkProgram(shaderProgram);
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    glUseProgram(shaderProgram);
}

void DarGameEngine::updateVBO(){
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STREAM_DRAW);
}

void DarGameEngine::initDrawing(){
  GLuint VBO;
  glGenBuffers(1,&VBO);
  glGenVertexArrays(1,&VAO);
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  updateVBO();
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*)0);
  glEnableVertexAttribArray(0);
  glEnable(GL_PROGRAM_POINT_SIZE);
}

bool DarGameEngine::closeDarGame(){
  return glfwWindowShouldClose(window);
}

int DarGameEngine::getScreenWidth(){
  return screenWidth;
}

void DarGameEngine::update(){
  glfwPollEvents();
  glClearColor(0.2f,0.3f,0.3f,1.0f);
  glClear(GL_COLOR_BUFFER_BIT);
  updateVBO();
  //gl_PointSize =10.0;
  glDrawArrays(GL_POINTS,0, 3);
  glfwSwapBuffers(window);
}

int DarGameEngine::getScreenHeight(){
  return screenHeight;
}

bool DarGameEngine::instanceFlag = false;
DarGameEngine* DarGameEngine::engineInstance;
