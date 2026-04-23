#include <Gl/glut.h>
#include <math.h>
#include <windows.h>

void myInit()
{
    glClearColor(1,1,1,0);
    glColor3f(1,0,0);
    glPointSize(5);
    gluOrtho2D(-600,600,-400,400);
}

void displayFunction()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
    glVertex2i(100,100);
    glVertex2i(-100,100);
    glVertex2i(-100,-100);
    glVertex2i(100,-100);
    glEnd();

    glFlush();
}

void keyPress(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'w': //scale up
        glScalef(2,2,0);//x,y,z
        glutPostRedisplay(); //rendering the shape
        break;
    case 's': //scale down
        glScalef(0.5,0.5,0);
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

void specialKey(int key, int x, int y)
{
    switch(key)
    {
    case GLUT_KEY_LEFT:
        glTranslatef(-50,0,0);
        glutPostRedisplay();
        break;
    case GLUT_KEY_RIGHT:
        glTranslatef(50,0,0);
        glutPostRedisplay();
        break;
    case GLUT_KEY_UP:
        glTranslatef(0,50,0);
        glutPostRedisplay();
        break;
    case GLUT_KEY_DOWN:
        glTranslatef(0,-50,0);
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

void mouseClick(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON & state == GLUT_DOWN)
    {
        glRotatef(10,0,0,1);
        glutPostRedisplay();
    }
    if(button == GLUT_RIGHT_BUTTON & state == GLUT_DOWN)
    {
        glRotatef(-10,0,0,1);
        glutPostRedisplay();
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(640,480);
    glutInitWindowPosition(300,150);
    glutCreateWindow("keyboard Interaction");

    glutDisplayFunc(displayFunction);

    glutKeyboardFunc(keyPress);
    glutSpecialFunc(specialKey);
    glutMouseFunc(mouseClick);

    myInit();
    glutMainLoop();
    return 0;
}
