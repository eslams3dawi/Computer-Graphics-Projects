#include <GL/glut.h>
#include <math.h>

float tx = 0;
float ty = 0;
float angle = 0;
float scale = 1;

void drawCircle(float cx, float cy, float r)
{
    glBegin(GL_POLYGON);

    for(int i = 0; i < 360; i++)
    {
        float theta = i * 3.14159f / 180;

        float x = r * cos(theta);
        float y = r * sin(theta);

        glVertex2f(x + cx, y + cy);
    }

    glEnd();
}

void myInit()
{
    glClearColor(1,1,1,1);

    gluOrtho2D(-600,600,-400,400);
}

void displayFunction()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    // ÇáÍÑßÉ æÇáÏæÑÇä æÇáÊßÈíÑ
    glTranslatef(tx, ty, 0);
    glRotatef(angle, 0,0,1);
    glScalef(scale, scale, 1);

    // ====================
    // ÌÓã ÇáÚÑÈíÉ
    // ====================
    glColor3f(1,0,0);

    glBegin(GL_POLYGON);
        glVertex2i(-150,-50);
        glVertex2i(150,-50);
        glVertex2i(150,50);
        glVertex2i(-150,50);
    glEnd();

    // ====================
    // ÓÞÝ ÇáÚÑÈíÉ
    // ====================
    glColor3f(0,0,1);

    glBegin(GL_POLYGON);
        glVertex2i(-80,50);
        glVertex2i(80,50);
        glVertex2i(40,120);
        glVertex2i(-40,120);
    glEnd();

    // ====================
    // ÇáÚÌáÉ ÇáÔãÇá
    // ====================
    glColor3f(0,0,0);
    drawCircle(-90, -70, 40);

    // ====================
    // ÇáÚÌáÉ Çáíãíä
    // ====================
    drawCircle(90, -70, 40);

    glPopMatrix();

    glFlush();
}

void keyPress(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'w':
        scale += 0.1;
        break;

    case 's':
        scale -= 0.1;
        break;
    }

    glutPostRedisplay();
}

void specialKey(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_LEFT:
        tx -= 20;
        break;

    case GLUT_KEY_RIGHT:
        tx += 20;
        break;

    case GLUT_KEY_UP:
        ty += 20;
        break;

    case GLUT_KEY_DOWN:
        ty -= 20;
        break;
    }

    glutPostRedisplay();
}

void mouseClick(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        angle += 10;
    }

    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        angle -= 10;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(640,480);
    glutCreateWindow("Car");

    glutDisplayFunc(displayFunction);
    glutKeyboardFunc(keyPress);
    glutSpecialFunc(specialKey);
    glutMouseFunc(mouseClick);

    myInit();

    glutMainLoop();

    return 0;
}
