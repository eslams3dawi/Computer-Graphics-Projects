#include <GL/glut.h>

float tx = 0.0f, ty = 0.0f; //For translation
float angle = 0.0f;
float scale = 1.0f;

void myInit()
{
    glClearColor(0,0,0,1);
    gluOrtho2D(-350, 350, -350, 350);
}

void drawTriangle()
{
    glBegin(GL_TRIANGLES);
    glVertex2i(0,200);
    glVertex2i(200,0);
    glVertex2i(-200,0);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,1,1);
    drawTriangle();

    //Translation
    glPushMatrix();
    glTranslatef(tx - 1.0f, ty, 0);
    glColor3f(1,0,0);
    drawTriangle();
    glPopMatrix();

    //Rotation
    glPushMatrix();
    glTranslatef(1.0f, 0.0f, 0);
    glRotatef(angle, 0, 0, 1);
    glColor3f(0,1,0);
    drawTriangle();
    glPopMatrix();

    //Scaling
    glPushMatrix();
    glTranslatef(0.0f, 1.0f, 0);
    glScalef(scale, scale, 0);
    glColor3f(0,0,1);
    drawTriangle();
    glPopMatrix();

    //Reflection
    glPushMatrix();
    glTranslatef(1.0f, -1.0f, 0);
    glScalef(1,-1,1);
    glColor3f(1,1,0);
    drawTriangle();
    glPopMatrix();

    glFlush();
}

//For rotation and scaling control
void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'r': angle += 5; break;
    case 'R':  angle -= 5; break;
    case 's': scale += 0.1f; break;
    case 'S': scale -= 0.1f; break;
    default: break;
    }
    glutPostRedisplay();
}

//For translation control
void specialKeys(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_LEFT: tx -= 5; break;
        case GLUT_KEY_RIGHT: tx += 5; break;
        case GLUT_KEY_UP: ty += 5; break;
        case GLUT_KEY_DOWN: ty -= 5; break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(700,700);
    glutInitWindowPosition(250,100);
    glutCreateWindow("Triangle");

    myInit();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
    return 0;
}





