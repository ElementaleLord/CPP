#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define WINDOW_WIDTH_CUS 800
#define WINDOW_HEIGHT_CUS 600

void framebuffer_size_callback(GLFWwindow*, int, int);
void processInput(GLFWwindow*);

int main(){
    if (!glfwInit()){
    //^ Init For glfw
        std::cout << "Failed to initialize glfw" << std::endl;
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
    //^ Sets Major Version Of GL As 3.x
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); 
    //^ Sets Minor Version Of GL As x.3
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
    //^ Sets That The Profile We Want Is The Core Profile
    // glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); 
    //^ MAC Specific

    //* Creating a Window context
    GLFWwindow* window= glfwCreateWindow(
        WINDOW_WIDTH_CUS, WINDOW_HEIGHT_CUS, "LearnOpenGL", NULL, NULL);
    if (window == NULL){
        std::cout << "Failed to create GLFW Window " << std:: endl;
        glfwTerminate();
        return -2;
    }
    glfwMakeContextCurrent(window);

    //* Initializing GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -3;
    }

    //* Setting Viewport x-y-W-H
    glViewport(0, 0, WINDOW_WIDTH_CUS, WINDOW_HEIGHT_CUS);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    //^ Setting The Function To Use When The Viewport Is Resized

    //* Render Loop
    while(!glfwWindowShouldClose(window)){
        //$ input
        processInput(window);
        
        //$ rendering commands here
        glClearColor( 0, 0, 0.5f, 0.01f);
        glClear(GL_COLOR_BUFFER_BIT);

        //$ check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
};
void processInput(GLFWwindow* window){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    };

    // if (glfwGetKey(window, GLFW_KEY_H) == GLFW_PRESS){
    //     std::cout << "Hi" << std::endl;
    // };
}
