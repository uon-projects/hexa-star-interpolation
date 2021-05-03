// interpolation.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <Windows.h>
#include <iostream>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "glut.h"
#include "shapes.h"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "UnusedLocalVariable"

using namespace std;

void display();

void idle();

void reshape(int, int);

float timelapse = 0.0;

Pentagon p;
Star s;
Point m[5];
Star ibt;
float timeSpeed = .0001;
int screenSize[] = {
        500,
        500
};
bool finished = false;

float beginColour[3] = {
        .015,
        .015,
        .015
};
float endColour[3] = {
        .15,
        .15,
        .15
};
float currentColour[3];
const float colourAnimationSpeed = .00001;
bool colourAnimationReverse = false;


int main(int argc, char *argv[])
{

    memcpy(beginColour, currentColour, sizeof(beginColour));

    glutInit(&argc, argv);
    glutInitWindowPosition(300, 100);
    glutInitWindowSize(screenSize[0], screenSize[1]);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Graphics 2 | UoN 20/21");
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutReshapeFunc(reshape);

    init();
    write();

    glutMainLoop();

    return 0;
}

float widthAnimation = 6;
void display()
{
    glClearColor(currentColour[0], currentColour[1], currentColour[2], 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLineWidth(6.0);
    p.draw();
    glLineWidth(1.0);
    s.draw();

    Star tmp;
    tmp.setColour(ibt);
    glLineWidth(widthAnimation);
    for (int i = 0; i < 10; i++)
    {
        tmp.vertices[i] = ibt.vertices[i] * (1.0f - timelapse) + s.vertices[i] * timelapse;
    }
    tmp.draw();

    glutSwapBuffers();
}

void idle()
{
    timelapse += finished ? (timeSpeed * -1) : timeSpeed;

    if (timelapse > 1.0)
    {
        finished = true;
    } else if (timelapse < 0)
    {
        finished = false;
    }
    if(finished)
    {
        widthAnimation += timelapse / 1000;
    } else {
        widthAnimation -= timelapse / 1000;
    }

    currentColour[0] += colourAnimationReverse ? -colourAnimationSpeed : colourAnimationSpeed;
    currentColour[1] += colourAnimationReverse ? -colourAnimationSpeed : colourAnimationSpeed;
    currentColour[2] += colourAnimationReverse ? -colourAnimationSpeed : colourAnimationSpeed;
    if (currentColour[0] >= endColour[0])
    {
        colourAnimationReverse = true;
    } else if (currentColour[0] <= beginColour[0])
    {
        colourAnimationReverse = false;
    }

    glutPostRedisplay();
}

void reshape(int w, int h)
{
    glutReshapeWindow(screenSize[0], screenSize[1]);
}

#pragma clang diagnostic pop