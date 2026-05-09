#include <GL/glut.h>

float tx = 0.0f, ty = 0.0f, tz = 0.0f;
float angle = 0.0f;
float scale = 1.0f;

void init()
{
    glClearColor(0,0,0,1);

    glEnable(GL_DEPTH_TEST);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45,1,1,1000);

    glMatrixMode(GL_MODELVIEW);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();

    gluLookAt(300,300,300,
              0,0,0,
              0,1,0);

    glTranslatef(tx,ty,tz);
    glRotatef(angle,1,1,1);
    glScalef(scale,scale,scale);

    // ======================
    // «·ÊÃÂ «·√„«„Ì
    // ======================
    glBegin(GL_LINE_LOOP);

    glColor3f(1,0,0);

    glVertex3f(0,100,0);
    glVertex3f(-100,-100,100);
    glVertex3f(100,-100,100);

    glEnd();

    // ======================
    // «·ÊÃÂ «·Ì„Ì‰
    // ======================
    glBegin(GL_POLYGON);

    glColor3f(0,1,0);

    glVertex3f(0,100,0);
    glVertex3f(100,-100,100);
    glVertex3f(100,-100,-100);

    glEnd();

    // ======================
    // «·ÊÃÂ «·Œ·›Ì
    // ======================
    glBegin(GL_POLYGON);

    glColor3f(0,0,1);

    glVertex3f(0,100,0);
    glVertex3f(100,-100,-100);
    glVertex3f(-100,-100,-100);

    glEnd();

    // ======================
    // «·ÊÃÂ «·‘„«·
    // ======================
    glBegin(GL_POLYGON);

    glColor3f(1,1,0);

    glVertex3f(0,100,0);
    glVertex3f(-100,-100,-100);
    glVertex3f(-100,-100,100);

    glEnd();

    // ======================
    // «·ﬁ«⁄œ…
    // ======================
    glBegin(GL_POLYGON);

    glColor3f(1,0,1);

    glVertex3f(-100,-100,100);
    glVertex3f(100,-100,100);
    glVertex3f(100,-100,-100);
    glVertex3f(-100,-100,-100);

    glEnd();

    glutSwapBuffers();
}

void specialKey(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_LEFT:
            tx -= 5;
            break;

        case GLUT_KEY_RIGHT:
            tx += 5;
            break;

        case GLUT_KEY_UP:
            angle += 5;
            break;

        case GLUT_KEY_DOWN:
            angle -= 5;
            break;
    }

    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowSize(800,800);

    glutCreateWindow("3D Pyramid");

    init();

    glutDisplayFunc(display);
    glutSpecialFunc(specialKey);

    glutMainLoop();

    return 0;
}
