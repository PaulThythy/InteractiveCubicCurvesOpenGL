#pragma once

#include <iostream>

#include "vector2.h"
#include "matrix.h"

struct CubicBSpline {

    Matrix T{1, 4};
    Matrix M{4, 4};
    Matrix P{4, 2};

    inline CubicBSpline(){
        M.mat[0][0] = -1;   M.mat[0][1] = 3;    M.mat[0][2] = -3; M.mat[0][3] = 1;
        M.mat[1][0] = 3;    M.mat[1][1] = -6;   M.mat[1][2] = 3;
        M.mat[2][0] = -3;   M.mat[2][2] = 3;
        M.mat[3][0] = 1;    M.mat[3][1] = 4;    M.mat[3][2] = 1; 
    }

    inline Matrix getMatM() { return this->M; }
    inline Matrix getMatT() { return this->T; }
    inline Matrix getMatP() { return this->P; }

    inline void setMatT(float t) {
        float tt = t*t;
        float ttt = tt*t;

        T.mat[0][0] = ttt; T.mat[0][1] = tt; T.mat[0][2] = t; T.mat[0][3] = 1;
    }

    inline void setMatP(const Vector2& p0, const Vector2& p1, const Vector2& p2, const Vector2& p3) {
        P.mat[0][0] = p0.m_x; P.mat[0][1] = p0.m_y;
        P.mat[1][0] = p1.m_x; P.mat[1][1] = p1.m_y;
        P.mat[2][0] = p2.m_x; P.mat[2][1] = p2.m_y;
        P.mat[3][0] = p3.m_x; P.mat[3][1] = p3.m_y;
    }
};