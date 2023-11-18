#include <iostream>
#include <cmath>

struct Vector2 {
    double m_x, m_y;

    inline Vector2(double x, double y): m_x(x), m_y(y) { }
    inline Vector2() {}

    inline void set(double x, double y) { m_x = x; m_y = y; }

    inline static float distance(const Vector2& v1, const Vector2& v2) {
        return sqrt(pow(v2.m_x - v1.m_x, 2) + pow(v2.m_y - v1.m_y, 2));
    }
};