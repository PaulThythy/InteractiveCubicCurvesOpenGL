#include <iostream>
#include <new>
#include <math.h>
#include <GL/glut.h>

#include "vector2.h"

const float PI = 3.1415926535;

// global variables for OpenGL
int window, width, height;
const int NMAX = 100;
int N = 0;

int mp = -1, right = 0, left = 0;

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

Vector2 V[NMAX];

void drawLine()
{
	glBegin(GL_POINTS);
	for (int i = 0; i < N; i++)
	{
		glVertex2f(V[i].m_x, V[i].m_y);
	}
	glEnd();
}

void main_reshape(int width, int height)
{
	GLint viewport[4];
	glViewport(0, 0, width, height);
	glGetIntegerv(GL_VIEWPORT, viewport);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, viewport[2], 0.0, viewport[3], -50.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void main_display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glColor3f(0.0, 1.0, 0.0);
	glPointSize(3.0);
	glInitNames();
	glPushName(1);
	for (int i = 0; i < N; i++)
	{
		glLoadName(i);
		glBegin(GL_POINTS);
		glVertex2f(V[i].m_x, V[i].m_y);
		glEnd();
	}
	glutPostRedisplay();

	glutSwapBuffers();
}

void Mouse(int button, int state, int x, int y)
{
	GLint viewport[4];

	glutSetCursor(GLUT_CURSOR_CROSSHAIR);
	glGetIntegerv(GL_VIEWPORT, viewport);

	if (button == GLUT_LEFT_BUTTON)
	{
		right = 0;
		left = 1;
		glColor3f(0.0, 1.0, 0.0);
		glPointSize(3.0);
		glInitNames();
		glPushName(1);

		V[N].m_x = x;
		V[N].m_y = viewport[3] - y;

		glLoadName(N);
		glBegin(GL_POINTS);
		glVertex2f(V[N].m_x, V[N].m_y);
		glEnd();

		if (state == GLUT_UP)
			N++;

		glutPostRedisplay();
	}

	if (button == GLUT_RIGHT_BUTTON)
	{
		left = 0;
		right = 1;
		if (state == GLUT_DOWN)
		{
			GLuint *selectBuf = new GLuint[200];
			GLuint *ptr;
			GLint hits;

			glSelectBuffer(200, selectBuf);
			glRenderMode(GL_SELECT);

			glPushMatrix();
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPickMatrix(x, viewport[3] - y, 5.0, 5.0, viewport);
			glOrtho(0.0, viewport[2], 0.0, viewport[3], -50.0, 50.0);

			glColor3f(0.0, 1.0, 0.0);
			glPointSize(3.0);
			glInitNames();
			glPushName(1);

			for (int i = 0; i < N; i++)
			{
				glLoadName(i);
				glBegin(GL_POINTS);
				glVertex2f(V[i].m_x, V[i].m_y);
				glEnd();
			}

			glPopMatrix();
			glFlush();

			hits = glRenderMode(GL_RENDER);
			if (hits)
			{
				ptr = (GLuint *)selectBuf;
				ptr += 3;
				mp = *ptr;
			}
		}

		if (state == GLUT_UP)
			mp = -1;

		main_reshape(viewport[2], viewport[3]);
		glutPostRedisplay();
	}
}

void Motion(int x, int y)
{
	GLint viewport[4];

	glGetIntegerv(GL_VIEWPORT, viewport);

	if ((right) && (mp != -1))
	{
		int i = mp;
		V[i].m_x = x;
		V[i].m_y = viewport[3] - y;
		drawLine();
		glutPostRedisplay();
	}
}

int main(int argc, char **argv)
{

	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInit(&argc, argv);
	glEnable(GL_DEPTH_TEST);

	window = glutCreateWindow("Select");
	glutReshapeFunc(main_reshape);
	glutDisplayFunc(main_display);
	glutMouseFunc(Mouse);
	glutMotionFunc(Motion);
	createMenu();

	glutPostRedisplay();
	glutMainLoop();

	return 0;
}
