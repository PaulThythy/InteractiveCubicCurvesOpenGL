#pragma once

#include <iostream>

#include "vector2.h"
#include "matrix.h"

struct CubicBezier {

    Matrix m{4, 4};

    inline CubicBezier(){
        m.mat[0][0] = -1;   m.mat[0][1] = 3;    m.mat[0][2] = -3; m.mat[0][3] = 1;
        m.mat[1][0] = 3;    m.mat[1][1] = -6;   m.mat[1][2] = 3;
        m.mat[2][0] = -3;   m.mat[2][1] = 3;
        m.mat[3][0] = 1;
    }

    inline Matrix getMat() { return this->m; }

    // to use de Casteljau's algorithm
    inline Vector2 interpolate(Vector2 p0, Vector2 p1, Vector2 p2, Vector2 p3, double t){
        double u = 1-t;
        double uu = u*u;
        double uuu = uu*u;
        double tt = t*t;
        double ttt = tt*t;

        Vector2 p;
        p.m_x = p0.m_x * uuu + 3 * p1.m_x * t * uu + 3 * p2.m_x * tt * u + p3.m_x * ttt;
        p.m_y = p0.m_y * uuu + 3 * p1.m_y * t * uu + 3 * p2.m_y * tt * u + p3.m_y * ttt;
        return p;
    }
};