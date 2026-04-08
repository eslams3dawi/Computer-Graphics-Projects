#include <iostream>
#include <GL/glut.h>
#include <math.h>

void myInit()
{
    glClearColor(1,0,0,0);
    glPointSize(3);
    gluOrtho2D(0,800,0,600);//
}

void displayFunction()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0,0,0.5);

    float x,y,i;
    glBegin(GL_POLYGON);
    for(i=0; i <= 2*M_PI; i+= 0.001)
    {
        x = 200 * cos(i);
        y = 200 * sin(i);
        glVertex2f(x+300, y+250);
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(800,600);//
    glutInitWindowPosition(500,200);//
    glutCreateWindow("Circle");

    glutDisplayFunc(displayFunction);
    myInit();
    glutMainLoop();

    return 0;
}









