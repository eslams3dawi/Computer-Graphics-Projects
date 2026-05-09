#include <GL/glut.h>

float tx = 0.0f, ty = 0.0f, tz = 0.0f;
float angle = 0.0f;
float scale = 1.0f;

void init()
{
    glClearColor(0,0,0,1); //sets background to black
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_PROJECTION);

    glLoadIdentity();
    gluPerspective(45, 1, 1, 100); //view angle, aspect ratio, z-near, z-far
    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    gluLookAt(20,20,20, //Camera position
              0,0,0, //Looking at (origin)
              0,1,0); //Up direction (y)

    glTranslatef(tx, ty, tz);
    glRotatef(angle, 1,1,1);
    glScalef(scale, scale, scale);

    glBegin(GL_QUADS);

    //Front (Red)
    glColor3f(1,0,0);
    glVertex3f(0,0,0);
    glVertex3f(5,0,0);
    glVertex3f(5,5,0);
    glVertex3f(0,5,0);
    //Right (Blue)
    glColor3f(0,0,1);
    glVertex3f(5,0,0);
    glVertex3f(5,5,0);
    glVertex3f(5,5,-5);
    glVertex3f(5,0,-5);
    //Top (yellow)
    glColor3f(1,1,0);
    glVertex3f(0,5,0);
    glVertex3f(5,5,0);
    glVertex3f(5,5,-5);
    glVertex3f(0,5,-5);

    //Left (Green)
    glColor3f(0,1,0);
    glVertex3f(0,0,0);
    glVertex3f(0,5,0);
    glVertex3f(0,5,-5);
    glVertex3f(0,0,-5);
    //Bottom (magenta)
    glColor3f(1,0,1);
    glVertex3f(0,0,0);
    glVertex3f(5,0,0);
    glVertex3f(5,0,-5);
    glVertex3f(0,0,-5);
    //back (cyan)
    glColor3f(0,1,1);
    glVertex3f(0,0,-5);
    glVertex3f(0,5,-5);
    glVertex3f(5,5,-5);
    glVertex3f(5,0,-5);

    glEnd();
    glutSwapBuffers();
}

void specialKeys(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_LEFT: tx -= 1.0f; tz -= 1.0f; break;
        case GLUT_KEY_RIGHT: tx += 1.0f; break;
        case GLUT_KEY_UP: ty += 1.0f; break;
        case GLUT_KEY_DOWN: ty -= 1.0f; break;
    }
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'r': angle += 5; break;
        case 'R': angle -= 5; break;
        case 's': scale += 1.0f; break;
        case 'S': scale -= 1.0f; break;
        case 'z': tz += 1.0f; break;
        case 'Z': tz -= 1.0f; break;
        case 27: exit(0);
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("3D Cube");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    glutMainLoop();
}
