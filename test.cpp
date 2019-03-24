#include "GL/freeglut.h"
#include "GL/gl.h"
#include <math.h>

/* Credits to Carmine at https://community.khronos.org/t/how-to-draw-a-pentagon/69776/3 */
void renderFunction()
{
    int v;
    float pent[6][2];

    float ang, da = 6.2832 / 5.0;    // central angle between vertices in radians

    // Compute vertex coordinates.

    for (v = 0; v < 5; v++)  {
        ang = v * da;
        pent[v][0] = cos (ang);
        pent[v][1] = sin (ang);
    }

    // Draw loop.
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.5, 1.0, 0.0);
    glRotatef(27.0f,1.0f,1.0f,1.0f);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glBegin (GL_POLYGON);
    for (v = 0; v < 5; v++) {
        glVertex2fv(pent[v]);
    }
    glEnd();
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("OpenGL - Green Polygon");
    glutDisplayFunc(renderFunction);
    glutMainLoop();    
    return 0;
}