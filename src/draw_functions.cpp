#include <GL/glut.h>

#include "draw_functions.h"
#include "cubicBezier.h"
#include "cubicBSpline.h"
#include "cubicCatmullRom.h"

void drawPoints(Vector2* V, int N) {
    glColor3f(0.0, 1.0, 0.0);
    glPointSize(3.0);
    glInitNames();
    glPushName(1);
    for (int i = 0; i < N; i++){
        glLoadName(i);
        glBegin(GL_POINTS);
        glVertex2f(V[i].m_x, V[i].m_y);
        glEnd();
    }
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

void drawLine(const Vector2& v1, const Vector2& v2) {
    glBegin(GL_LINES);
    glVertex2f(v1.m_x, v1.m_y);
    glVertex2f(v2.m_x, v2.m_y);
    glEnd();
}

void drawBezier(Vector2* V, int N) {
    double tSteps = 1/static_cast<double>(NB_POINTS_INTERPOLATION);

    CubicBezier bezier;
    if(N >= 4){
        for(int i = 0; i < N-3; i+=3){
            Vector2 p0 = V[i];
            Vector2 p1 = V[i+1];
            Vector2 p2 = V[i+2];
            Vector2 p3 = V[i+3];
            bezier.setMatP(p0, p1, p2, p3);

            double t = 0;
            while(t <= 1 - tSteps){
                bezier.setMatT(t);
                Matrix m1 = bezier.getMatT() * bezier.getMatM() * bezier.getMatP();
                Vector2 v(m1);

                t += tSteps;

                bezier.setMatT(t);
                Matrix m2 = bezier.getMatT() * bezier.getMatM() * bezier.getMatP();
                Vector2 v_next(m2);
                
                glColor3f(1.0, 0.0, 0.0);
                drawLine(v, v_next);
 
            }
        }
    }
}