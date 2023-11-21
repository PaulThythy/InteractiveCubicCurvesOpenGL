#pragma once

#include <iostream>

#include "vector2.h"
#include "matrix.h"

struct CubicCatmullRom {

    Matrix m{4, 4};

    inline CubicCatmullRom(){
        m.mat[0][0] = 1;
        m.mat[1][0] = -3;   m.mat[2][0] = 3;
        m.mat[2][0] = 3;    m.mat[2][1] = -6;   m.mat[2][2] = 3;
        m.mat[3][0] = -1;   m.mat[3][1] = 3;    m.mat[3][2] = -3; m.mat[3][3] = 1;

        this->m = (1/2) * this->m;
    }

    inline Matrix getMat() { return this->m; }
};