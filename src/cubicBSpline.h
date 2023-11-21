#pragma once

#include <iostream>

#include "vector2.h"
#include "matrix.h"

struct CubicBSpline {

    Matrix m{4, 4};

    inline CubicBSpline(){
        m.mat[0][0] = -1;   m.mat[0][1] = 3;    m.mat[0][2] = -3; m.mat[0][3] = 1;
        m.mat[1][0] = 3;    m.mat[1][1] = -6;   m.mat[1][2] = 3;
        m.mat[2][0] = -3;   m.mat[2][2] = 3;
        m.mat[3][0] = 1;    m.mat[3][1] = 4;    m.mat[3][2] = 1; 
    }

    inline Matrix getMat() { return this->m; }
};