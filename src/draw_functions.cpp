#include <GL/glut.h>

#include "vector2.h"

void drawPoints(Vector2* V, int N) {
    glBegin(GL_POINTS);
    for (int i = 0; i < N; i++){
        glVertex2f(V[i].m_x, V[i].m_y);
    }
    glEnd();
}

void drawLineStipple(Vector2* V, int N) {
    glColor3f(1.0, 1.0, 1.0);

    glEnable(GL_LINE_STIPPLE);
    glLineStipple(1, 0xAAAA);

    glBegin(GL_LINES);
    for (int i = 0; i < N - 1; i++) {
        glVertex2f(V[i].m_x, V[i].m_y);
        glVertex2f(V[i + 1].m_x, V[i + 1].m_y);
    }
    glEnd();

    glDisable(GL_LINE_STIPPLE);
}
