#pragma once

#include <iostream>

#include "vector2.h"
#include "matrix.h"

struct CubicBezier {

    Matrix T{1, 4};
    Matrix M{4, 4};
    Matrix P{4, 2};

    inline CubicBezier() {
        M.mat[0][0] = -1;   M.mat[0][1] = 3;    M.mat[0][2] = -3; M.mat[0][3] = 1;
        M.mat[1][0] = 3;    M.mat[1][1] = -6;   M.mat[1][2] = 3;
        M.mat[2][0] = -3;   M.mat[2][1] = 3;
        M.mat[3][0] = 1;
    }
    
    inline Matrix getMatM() { return this->M; }
    inline Matrix getMatT() { return this->T; }
    inline Matrix getMatP() { return this->P; }

    inline void setMatT(double t) {
        double tt = t*t;
        double ttt = tt*t;

        T.mat[0][0] = ttt; T.mat[0][1] = tt; T.mat[0][2] = t; T.mat[0][3] = 1;
    }

    inline void setMatP(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3) {
        P.mat[0][0] = p0.m_x; P.mat[0][1] = p0.m_y;
        P.mat[1][0] = p1.m_x; P.mat[1][1] = p1.m_y;
        P.mat[2][0] = p2.m_x; P.mat[2][1] = p2.m_y;
        P.mat[3][0] = p3.m_x; P.mat[3][1] = p3.m_y;
    }

    // to use de Casteljau's algorithm
    /*inline Vector2 interpolate(Vector2 p0, Vector2 p1, Vector2 p2, Vector2 p3, double t) {
        double u = 1-t;
        double uu = u*u;
        double uuu = uu*u;
        double tt = t*t;
        double ttt = tt*t;

        Vector2 p;
        p.m_x = p0.m_x * uuu + 3 * p1.m_x * t * uu + 3 * p2.m_x * tt * u + p3.m_x * ttt;
        p.m_y = p0.m_y * uuu + 3 * p1.m_y * t * uu + 3 * p2.m_y * tt * u + p3.m_y * ttt;
        return p;
    }*/
};