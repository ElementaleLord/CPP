#include <GL/glut.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "custom_opengl.h"

trigMap trigs= {
    {"triforceTop",  {{ 0.0,     0.75},{-0.375, 0.0 },{ 0.375, 0.0 }}},
    {"triforceLeft", {{-0.375,   0.0 },{-0.75, -0.75},{ 0.0,  -0.75}}},
    {"triforceRight",{{ 0.375,   0.0 },{ 0.0,  -0.75},{ 0.75, -0.75}}},
};

void display() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_TRIANGLES);

    rgbTrig(trigs["triforceTop"], "red", "green", "blue");
    rgbTrig(trigs["triforceLeft"], "yellow", "cyan", "white");
    rgbTrig(trigs["triforceRight"], "orange", "black", "purple");

    glEnd();
    glFlush();
}

void handleInput(unsigned char key, int x, int y){
    std::cout << key;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GL RGB Triangle");
    glutDisplayFunc(display);
    glutSetCursor(GLUT_CURSOR_HELP);
    glutKeyboardFunc(handleInput);
    glutMainLoop();
    return 0;
}