#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#define WINDOW_WIDTH_CUS 800
#define WINDOW_HEIGHT_CUS 600

void framebuffer_size_callback(GLFWwindow*, int, int);
void processInput(GLFWwindow*);
GLFWwindow* initProg(GLFWwindow*);

//* char constant Used To Mimic Shader Source File
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource1="#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.8f, 0.4f, 1.0f);\n"
    "}\0";
const char *fragmentShaderSource2="#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(0.8f, 1.0f, 0.4f, 1.0f);\n"
    "}\0";

int main(){
    //* variables
    int  success; char infoLog[512];
    unsigned int VAO[2], VBO[2], vertexShader, fragmentShader1, fragmentShader2, shaderProgram1, shaderProgram2;
    GLFWwindow* window;

    window= initProg(window);

    //* Creating, Linking and Error Handling a Vertex Program Object
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR: Vector Shader Compilation Failed.\n" << infoLog << std::endl;
    }

    //* Creating, Linking and Error Handling a Fragement Program Object
    fragmentShader1 = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader1, 1, &fragmentShaderSource1, NULL);
    glCompileShader(fragmentShader1);
    glGetShaderiv(fragmentShader1, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragmentShader1, 512, NULL, infoLog);
        std::cout << "ERROR: Fragment Shader Compilation Failed.\n" << infoLog << std::endl;
    }

    fragmentShader2= glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader2, 1, &fragmentShaderSource2, NULL);
    glCompileShader(fragmentShader2);
    glGetShaderiv(fragmentShader2, GL_COMPILE_STATUS, &success);
    if(!success){
        glGetShaderInfoLog(fragmentShader2, 512, NULL, infoLog);
        std::cout << "ERROR: Fragment Shader Compilation Failed.\n" << infoLog << std::endl;
    }

    //* Creating, Linking and Error Handling a Shader Program Object
    shaderProgram1 = glCreateProgram();
    glAttachShader(shaderProgram1, vertexShader);
    glAttachShader(shaderProgram1, fragmentShader1);
    glLinkProgram(shaderProgram1);
    glGetProgramiv(shaderProgram1, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram1, 512, NULL, infoLog);
        std::cout << "ERROR: Shader Program Objec Linking Failed.\n" << infoLog << std::endl;
    }

    shaderProgram2= glCreateProgram();
    glAttachShader(shaderProgram2, vertexShader);
    glAttachShader(shaderProgram2, fragmentShader2);
    glLinkProgram(shaderProgram2);
    glGetProgramiv(shaderProgram2, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(shaderProgram2, 512, NULL, infoLog);
        std::cout << "ERROR: Shader Program Objec Linking Failed.\n" << infoLog << std::endl;
    }

    //* Our Objects Vertecies (Its a Triangle)
    float triforceOutter[] = {
    // first triangle
     0.375f,  0.0f,  0.0f,  // top
     0.75f, -0.75f,  0.0f,  // bottom right
     0.0f, -0.75f,  0.0f,  // bottom left
    // second triangle
    -0.375f,  0.0f,  0.0f,  // top
    -0.75f, -0.75f,  0.0f,  // bottom left
     0.0f, -0.75f,  0.0f,  // bottom right
    // third triangle
     0.0f,  0.75f,  0.0f,  // top
    -0.375f,  0.0f,  0.0f,  // bottom left
     0.375f,  0.0f,  0.0f,  // bottom right
    };

    float triforceInner[]= {  
    // first triangle  
     0.0f, -0.6f,  0.0f,        //6 bottom bottom
    -0.125f, -0.35f,  0.0f,     //7 top bottom right
     0.125f, -0.35f,  0.0f,     //8 top bottom left
    // second triangle
    -0.125f, -0.35f,  0.0f,     //7 top bottom right
     0.0f, -0.1f,  0.0f,        //9 top top middle
    -0.25f, -0.1f,  0.0f,       //10 top top right
    // third triangle
     0.125f, -0.35f,  0.0f,     //8 top bottom left
     0.0f, -0.1f,  0.0f,        //9 top top middle
     0.25f, -0.1f,  0.0f,       //11 top top left
    };
    

    //* Genrating And Binding To A Vertex Array Object
    glGenVertexArrays(2, VAO);
    glGenBuffers(2, VBO);

    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triforceOutter), triforceOutter, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAO[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triforceInner), triforceInner, GL_STATIC_DRAW);
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
        glUseProgram(shaderProgram1);
        glBindVertexArray(VAO[0]);
        glDrawArrays(GL_TRIANGLES, 0, 9);

        glUseProgram(shaderProgram2);
        glBindVertexArray(VAO[1]);
        glDrawArrays(GL_TRIANGLES, 0, 9);

        glBindVertexArray(0);

        //$ check and call events and swap the buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    //* Deleting The Vertex and Fragment Shaders
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader1); 
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
}
GLFWwindow* initProg(GLFWwindow* window){
    //* Init of glfw and GLAD
    if (!glfwInit()){
    //^ Init For glfw
        std::cout << "Failed to initialize glfw" << std::endl;
        exit(-1);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); 
    window= glfwCreateWindow(
        WINDOW_WIDTH_CUS, WINDOW_HEIGHT_CUS, "LearnOpenGL", NULL, NULL);
    if (window == NULL){
        std::cout << "Failed to create GLFW Window " << std:: endl;
        glfwTerminate();
        exit(-2);
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        exit(-3);
    }
    glViewport(0, 0, WINDOW_WIDTH_CUS, WINDOW_HEIGHT_CUS);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    return window;
}
