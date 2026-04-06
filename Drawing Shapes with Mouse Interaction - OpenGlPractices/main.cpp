#include <windows.h>
#include <GL/glut.h>

void myInit(void)
{
    glClearColor(1,1,1,0);
    glColor3f(1,0,0);
    glPointSize(5.0);
    gluOrtho2D(-320,320,-180,180);
}

void displayFunction(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2d(10,10);
    glVertex2d(-10,10);
    glVertex2d(10,-10);
    glVertex2d(-10,-10);
    glEnd();

    glFlush();
    //--------//
    glColor3f(0,0,1);
    glBegin(GL_LINE_LOOP);
    glVertex2d(20,40);
    glVertex2d(40,40);
    glVertex2d(60,20);
    glVertex2d(20,20);
    glEnd();

    glFlush();
}

void mouseFunction(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        glRotatef(10,0,0,1);//(angle, x, y, z) → angle = 10 & z = 1 means the shape is rotated along itself by 10 degrees
        glutPostRedisplay();//Render again after changes
    }
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
        glRotatef(-10,0,0,1);
        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);   //to show the drawing screen result

    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Mouse Project");

    glutDisplayFunc(displayFunction);
    glutMouseFunc(mouseFunction);

    myInit();
    glutMainLoop();
    return 0;
}
