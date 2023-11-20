#pragma once

#include <iostream>

#include "vector2.h"
#include "matrix.h"

struct CubicBezier {

    inline CubicBezier(){}

    // to use de Casteljau algorithm
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