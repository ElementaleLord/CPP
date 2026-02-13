#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define WINDOW_WIDTH_CUS 800
#define WINDOW_HEIGHT_CUS 600

void framebuffer_size_callback(GLFWwindow*, int, int);
void processInput(GLFWwindow*);

//* char constant Used To Mimic Shader Source File
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource="#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.8f, 0.3f, 1.0f);\n"
    "}\0";

int main(){
    //* variables
    int  success; char infoLog[512];
    unsigned int VAO, VBO, EBO, vertexShader, shaderProgram;

    //* Init of glfw and GLAD
    if (!glfwInit()){
    //^ Init For glfw
        std::cout << "Failed to initialize glfw" << std::endl;
        return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
    GLFWwindow* window= glfwCreateWindow(
        WINDOW_WIDTH_CUS, WINDOW_HEIGHT_CUS, "LearnOpenGL", NULL, NULL);
    if (window == NULL){
        std::cout << "Failed to create GLFW Window " << std:: endl;
        glfwTerminate();
        return -2;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -3;
    }
    glViewport(0, 0, WINDOW_WIDTH_CUS, WINDOW_HEIGHT_CUS);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    //* Creating, Compiling and Error handling our simple Vertex Shader
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR: Vector Shader Compilation Failed.\n" << infoLog << std::endl;
    }

    //* Creating, Compiling and Error handling our simple Fragment Shader
    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR: Fragment Shader Compilation Failed.\n" << infoLog << std::endl;
    }

    //* Creating, Linking and Error Handling a Shader Program Object
    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR: Shader Program Objec Linking Failed.\n" << infoLog << std::endl;
    }
    


    //* Our Objects Vertecies
    float vertices[] = {
    //~ Base tri-force
     0.0f,  0.75f,  0.0f,       //0 top top
     0.375f,  0.0f,  0.0f,      //1 bottom top right
    -0.375f,  0.0f,  0.0f,      //2 bottom top left
     0.0f, -0.75f,  0.0f,       //3 bottom bottom middle
     0.75f, -0.75f,  0.0f,      //4 bottom bottom right
    -0.75f, -0.75f,  0.0f,     //5 bottom bottom left
    //~ Flipped (smal) tri-force
     0.0f, -0.6f,  0.0f,        //6 bottom bottom
    -0.125f, -0.35f,  0.0f,     //7 top bottom right
     0.125f, -0.35f,  0.0f,     //8 top bottom left
     0.0f, -0.1f,  0.0f,        //9 top top middle
    -0.25f, -0.1f,  0.0f,       //10 top top right
     0.25f, -0.1f,  0.0f,       //11 top top left
    };
    unsigned int indices[] = {
        0, 1, 2,   // first triangle
        1, 3, 4,   // second triangle
        2, 3, 5,   // third triangle
        6, 7, 8,   // fourth triangle
        7, 9, 10,   // fifth triangle
        8, 9, 11,   // sixth triangle
    };
    


    //* Genrating And Binding To A Vertex Array Object
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    //* Generating, Binding and Passing Indices Data To A Element Buffer Object
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); 

    //* Generating, Binding and Passing Vertex Data To A Vertex Buffer Object
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    //* Setting How Data is Read
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); //~ To Enable WireFrame Drawing Mode
    // glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); //~ To Enable Default Drawing Mode

    //* NOTE -   Render Loop
    while(!glfwWindowShouldClose(window)){
        //$ input
        processInput(window);
        
        //$ rendering commands here
        glClearColor( 0.5f, 0.0f, 0.5f, 0.01f);
        glClear(GL_COLOR_BUFFER_BIT);

        //* Using the shader program
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);

        //$ check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //* Deleting The Vertex and Fragment Shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader); 
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
