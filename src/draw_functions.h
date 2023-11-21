#ifndef DRAW_FUNCTIONS_H
#define DRAW_FUNCTIONS_H

#include "vector2.h"

const int NB_POINTS_INTERPOLATION = 10;

void drawPoints(Vector2* V, int N);
void drawLineStipple(Vector2* V, int N);
void drawLine(const Vector2& v1, const Vector2& v2);

void drawBezier(Vector2* V, int N);
void drawCatmullRom(Vector2* V, int N);
void drawBSpline(Vector2*, int N);

#endif // DRAW_FUNCTIONS_H