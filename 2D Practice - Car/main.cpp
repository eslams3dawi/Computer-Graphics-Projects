#include <GL/glut.h>
#include <math.h>

float tx = 0.0f, ty = 0.0f;
float angle = 0.0f;
float scale = 1.0f;

void init()
{
    glClearColor(0,0,0,1);
    gluOrtho2D(-500, 500, -500, 500);
}

void drawCircle(float cx, float cy, float r)
{
    glColor3f(1,0,0);

    float x, y, i;
    glBegin(GL_POLYGON);
    for(i = 0; i <= 2 * M_PI; i+= 0.001)
    {
        x = r * cos(i);
        y = r * sin(i);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    glTranslatef(tx, ty, 0);
    glRotatef(angle,0,0,1);
    glScalef(scale,scale,scale);
    glScalef(-1,1,1);

    glColor3f(0,1,0);

    glBegin(GL_POLYGON);
    glVertex2f(100,0);
    glVertex2f(100,100);
    glVertex2f(-100,100);
    glVertex2f(-100,0);
    glEnd();

    glColor3f(0,0,1);
    glBegin(GL_POLYGON);
    glVertex2f(-50,100);
    glVertex2f(-35,125);
    glVertex2f(35,125);
    glVertex2f(50,100);
    glEnd();

    //Circle
    glColor3f(1,0,1);
    drawCircle(-50,-5,30);

    glColor3f(1,0,1);
    drawCircle(50,-5,30);

    glPopMatrix();
    glFlush();
}

void specialKey(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_LEFT: tx -= 5.0f; break;
        case GLUT_KEY_RIGHT: tx += 5.0f; break;
        case GLUT_KEY_UP: ty += 5.0f; break;
        case GLUT_KEY_DOWN: ty -= 5.0f; break;
    }
    glutPostRedisplay();
}

void keyPress(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 's': scale -= 1.0f; break;
        case 'S': scale += 1.0f; break;
        case 27: exit(0); break;
    }
    glutPostRedisplay();
}

void mouseClick(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        angle += 5;
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        angle -= 5;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Shape");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyPress);
    glutSpecialFunc(specialKey);
    glutMouseFunc(mouseClick);

    glutMainLoop();
}
