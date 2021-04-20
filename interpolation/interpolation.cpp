// interpolation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glut.h"
#include "primitives.h"

using namespace std;
void display();
void idle();
void reshape(int, int);
void lineMorphSnapshot(Point p0, Point p1, Point q0, Point q1, float time);

float time = 0.0;

Pentagon p;
Star s;
Point m[5];
Star ibt;

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitWindowPosition(10, 10);
	glutInitWindowSize(800, 800);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE| GLUT_DEPTH);
	glutCreateWindow("A simple glut window");	
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutReshapeFunc(reshape);

	init();

	glutMainLoop();

	return 0;
}

void display() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLineWidth(4.0);

	p.draw();
	s.draw();

	Star tmp;

	if (time > 1.0) time = 1.0;

	for (int i = 0; i < 10; i++) {
		/*tmp.vertices[i].x = ibt.vertices[i].x * (1.0 - time) + s.vertices[i].x * time; 
		tmp.vertices[i].y = ibt.vertices[i].y * (1.0 - time) + s.vertices[i].y * time; 
		tmp.vertices[i].z = ibt.vertices[i].z * (1.0 - time) + s.vertices[i].z * time; */
		tmp.vertices[i] = ibt.vertices[i] * (1.0 - time) + s.vertices[i] * time;
	}
	tmp.draw();

	glutSwapBuffers();
}

void idle() {
	time += 0.001;  // => time = time + 0.01;
	glutPostRedisplay();
}

void lineMorphSnapshot(Point p0, Point p1, Point q0, Point q1, float time) {

	Point a, b;

	a.x = (1.0 - time) * p0.x + time * q0.x;
	a.y = (1.0 - time) * p0.y + time * q0.y;
	a.z = (1.0 - time) * p0.z + time * q0.z;

	b.x = (1.0 - time) * p1.x + time * q1.x;
	b.y = (1.0 - time) * p1.y + time * q1.y;
	b.z = (1.0 - time) * p1.z + time * q1.z;

	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	glBegin(GL_LINES);
		glVertex3f(a.x, a.y, a.z);
		glVertex3f(b.x, b.y, b.z);
	glEnd();
	glPopMatrix();
}

void reshape(int w, int h) {
	glutReshapeWindow(800, 800);
}


