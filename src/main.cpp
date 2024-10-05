#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

const int WIDTH = 800, HEIGHT = 600;

int main(){
    
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "WINDOW", NULL, NULL);

    glfwMakeContextCurrent(window);
    glViewport(0, 0, WIDTH, HEIGHT);

    glewExperimental = GL_TRUE;
    glewInit();

    while(!glfwWindowShouldClose(window)){
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    return 0;
}