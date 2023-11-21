#pragma once

#include <iostream>
#include <stdexcept>
#include <cmath>

#include "matrix.h"

struct Vector2 {
    double m_x, m_y;

    inline Vector2(double x, double y): m_x(x), m_y(y) { }
    inline Vector2() {}
    inline Vector2(const Matrix& m) { 
        if(m.cols != 2 && m.rows != 1) {
            throw std::invalid_argument("Invalid Matrix size for Vector2 conversion");
        }

        this->m_x = m.mat[0][0]; this->m_y = m.mat[0][1];
    }

    inline void set(double x, double y) { m_x = x; m_y = y; }

    inline void display() {
        std::cout << "(" << m_x << ", " << m_y << ")" << std::endl;
    }

    inline static double distance(const Vector2& v1, const Vector2& v2) {
        return sqrt(pow(v2.m_x - v1.m_x, 2) + pow(v2.m_y - v1.m_y, 2));
    }
};