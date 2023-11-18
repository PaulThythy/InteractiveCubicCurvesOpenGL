#include <iostream>
#include <new>
#include <math.h>
#include <GL/glut.h>

#include "vector2.h"
#include "glut_menu.h"

const float PI = 3.1415926535;

// global variables for OpenGL
int window, width, height;
// number max of points in the window
const int NMAX = 100;
// number of points in the window
int N = 0;

// mp : current point, right, left: mouse buttons pressed or not
int mp = -1, right = 0, left = 0;

Vector2 V[NMAX];

//-----------------------------------------------
void drawPoints()
{
	glBegin(GL_POINTS);
	for (int i = 0; i < N; i++)
	{
		glVertex2f(V[i].m_x, V[i].m_y);
	}
	glEnd();
}

//-----------------------------------------------
void drawLineStipple(){
	glColor3f(1.0, 1.0, 1.0);

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(1, 0xAAAA);

	glBegin(GL_LINES);
	for(int i = 0; i < N-1; i++){
		glVertex2f(V[i].m_x, V[i].m_y); 
        glVertex2f(V[i + 1].m_x, V[i + 1].m_y); 
	}
	glEnd();
	glDisable(GL_LINE_STIPPLE);
}

// callback function for managing window size changes
void main_reshape(int newWidth, int newHeight)
{
	width = newWidth;
	height = newHeight;

	GLint viewport[4];
	glViewport(0, 0, width, height);
	glGetIntegerv(GL_VIEWPORT, viewport);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, viewport[2], 0.0, viewport[3], -50.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// callback function for managing screen display
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

	drawLineStipple();

	glutPostRedisplay();

	glutSwapBuffers();
}

// callback function for managing mouse events
void Mouse(int button, int state, int x, int y)
{
	GLint viewport[4];

	glutSetCursor(GLUT_CURSOR_CROSSHAIR);
	glGetIntegerv(GL_VIEWPORT, viewport);

	// to avoid to put a point in the window while menu is activated
	if (button == GLUT_LEFT_BUTTON && !GLUTMENU_SELECTED)
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

	GLUTMENU_SELECTED = false;

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

// callback function for managing mouse motions
void Motion(int x, int y)
{
	GLint viewport[4];

	glGetIntegerv(GL_VIEWPORT, viewport);

	if ((right) && (mp != -1))
	{
		int i = mp;
		V[i].m_x = x;
		V[i].m_y = viewport[3] - y;
		drawPoints();
		glutPostRedisplay();
	}
}

// Init openGL and main loop
int main(int argc, char **argv)
{

	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInit(&argc, argv);
	glEnable(GL_DEPTH_TEST);

	width = glutGet(GLUT_WINDOW_WIDTH);
    height = glutGet(GLUT_WINDOW_HEIGHT);

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
