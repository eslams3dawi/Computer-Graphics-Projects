#include <GL/glut.h>


float tx = 0.0f; ty = 0.0f; tz = 0.0f;
float angle = 0.0f;
float scale = 1.0f;


void init()
{
    glClearColor(0,0,0,1);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(45,1,1,100);
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(20,20,20,
              0,0,0,
              0,1,0);

    glTranslatef(tx, ty, tz);
    glRotatef(angle, 1,1,1);
    glScalef(scale,scale,scale);

    glBegin(GL_CUADS);

    glColor3f(1,0,0);
    glVertex3f();
    glVertex3f();
    glVertex3f();
    glVertex3f();

    glColor3f(0,1,0);
    glVertex3f();
    glVertex3f();
    glVertex3f();
    glVertex3f();

    glColor3f(0,0,1);
    glVertex3f();
    glVertex3f();
    glVertex3f();
    glVertex3f();

    glColor3f(1,0,1);
    glVertex3f();
    glVertex3f();
    glVertex3f();
    glVertex3f();

    glColor3f(1,1,0);
    glVertex3f();
    glVertex3f();
    glVertex3f();
    glVertex3f();

    glColor3f(0,1,1);
    glVertex3f();
    glVertex3f();
    glVertex3f();
    glVertex3f();

    glEnd();
    glutSwapBuffers();
}

