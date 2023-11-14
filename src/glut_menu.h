#ifndef GLUT_MENU_H
#define GLUT_MENU_H

extern bool DISP_CATMULLROM;
extern bool DISP_BEZIER;
extern bool DISP_BSPLINE;
extern bool GLUTMENU_SELECTED;

void menuCallback(int value);
void createMenu();

#endif // GLUT_MENU_H