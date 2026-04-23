#include <math.h>
#include <GL/glut.h>

float angle = 0.0f;
float scale = 1.0f;
float tx = 0.0f;
float ty = 0.0f;

void myInit()
{
    glClearColor(1,0,0,1);
    glPointSize(5);
    glColor3f(1,1,1);
    gluOrtho2D(-640,640,-480,480);
}

void displayFunction()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glVertex2f(-320,0);
    glVertex2f(0,440);
    glVertex2f(320,0);
    glEnd();
    glFlush();

    glBegin(GL_POLYGON);
    glVertex2f(-320,0);
    glVertex2f(320,0);
    glVertex2f(0,-440);
    glEnd();
    glFlush();

    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2f(-175,-175);
    glVertex2f(175,-175);
    glEnd();
    glFlush();

    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2f(-185,-185);
    glVertex2f(185,-185);
    glEnd();
    glFlush();

    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2f(-300, 0);
    glVertex2f(0, 420);
    glEnd();
    glFlush();

    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2f(0, 420);
    glVertex2f(300, 0);
    glEnd();
    glFlush();

    glColor3f(1,0,0);
    glBegin(GL_LINES);
    glVertex2f(-300, 0);
    glVertex2f(-170, -170);
    glEnd();
    glFlush();

    glColor3f(1,0,0);
    glBegin(GL_LINES);
   // glVertex2f(-300, 0);
    glVertex2f(300, 0);
    //glVertex2f(-170, -170);
    glVertex2f(170, -170);
    glEnd();
    glFlush();


}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'w':
        angle += 0.1f;
    case 's':
        angle -= 0.1f;
    case 'd':
        scale += 0.1f;
    case 'a':
        scale -= 0.1f;
    }
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitWindowSize(640,480);
    glutInitWindowPosition(50,50);
    glutCreateWindow("Practice");
    glutDisplayFunc(displayFunction);
    glutKeyboardFunc(keyboard);
    myInit();

    glutMainLoop();
}
