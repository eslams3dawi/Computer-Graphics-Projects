#include <GL/glut.h>
#include <windows.h>
#include <iostream>

void myInit()
{
    glClearColor(1,0,0,0);
    glPointSize(5);
    gluOrtho2D(0,800,0,600);
}

void displayFunction()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);

    glBegin(GL_LINE_LOOP);
    glVertex2d(200,200);
    glVertex2d(400,200);
    glVertex2d(400,400);
    glVertex2d(200,400);
    glEnd();

    glFlush();
}

void mouseFunction(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        glRotatef(10,0,0,1);
        glutPostRedisplay();
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        glRotatef(-10,0,0,1);
        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(800,600);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Square");

    glutDisplayFunc(displayFunction);
    glutMouseFunc(mouseFunction);
    myInit();
    glutMainLoop();

    return 0;
}
