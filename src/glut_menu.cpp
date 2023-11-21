#include <iostream>
#include <GL/glut.h>

#include "glut_menu.h"

bool DISP_CATMULLROM = false;
bool DISP_BEZIER = false;
bool DISP_BSPLINE = false;
bool GLUTMENU_SELECTED = false;

void menuCallback(int value){
	switch (value){
		case 1:
            DISP_CATMULLROM = !DISP_CATMULLROM; 
			DISP_BEZIER = false;
			DISP_BSPLINE = false;
			break;
		case 2:
            DISP_BEZIER = !DISP_BEZIER;
			DISP_CATMULLROM = false;
			DISP_BSPLINE = false;
			break;
		case 3:
            DISP_BSPLINE = !DISP_BSPLINE;
			DISP_BEZIER = false;
			DISP_CATMULLROM = false;
			break;
		case 4:
			exit(0);
			break;
	}

	GLUTMENU_SELECTED = true;
    
}

void createMenu(){
	glutCreateMenu(menuCallback);
    
    glutAddMenuEntry("Display/Hide Catmull-Rom Cubic", 1);
    glutAddMenuEntry("Display/Hide Bezier Cubic", 2);
    glutAddMenuEntry("Display/Hide B-Spline Cubic", 3);
    glutAddMenuEntry("Quitter", 4);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}