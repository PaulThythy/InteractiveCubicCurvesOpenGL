#include <iostream>

struct Vector2 {
    double m_x, m_y;

    inline Vector2(double x, double y): m_x(x), m_y(y) { }
    inline Vector2(): m_x(0.0), m_y(0.0) { }

    inline void set(double x, double y) { m_x = x; m_y = y; }
};