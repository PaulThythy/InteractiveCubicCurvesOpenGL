#include <iostream>

#include <GL/glut.h>

void menuCallback(int value){
	switch (value){
		case 1:
			std::cout << "option 1" << std::endl;
			break;
		case 2:
			std::cout << "option 2" << std::endl;
			break;
		case 3:
			std::cout << "option 3" << std::endl;
			break;
		case 4:
			std::cout << "Quitter" << std::endl;
			exit(0);
			break;
	}
}

void createMenu(){
	glutCreateMenu(menuCallback);
	glutAddMenuEntry("Option 1", 1);
	glutAddMenuEntry("Option 2", 2);
	glutAddMenuEntry("Option 3", 3);
	glutAddMenuEntry("Quitter", 4);

	glutAttachMenu(GLUT_RIGHT_BUTTON);
}