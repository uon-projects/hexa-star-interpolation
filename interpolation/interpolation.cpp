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

void mouseClick(int mouseButton, int state, int x, int y);

void mouseMotion(int x, int y);

void mouseMovement(int x, int y);

void reshape(int, int);

float timelapse = 0.0;

Pentagon pentagon;
Star star;
Star animatedStar;

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
float widthAnimation = 6;

int mouseButton;
float dx = 0.0;
float dy = 0.0;
float dz = 0.0;
int clickMouseX;
int clickMouseY;
int mouseX;
int mouseY;
bool idleState = true;

/**
 * Main function
 *
 * @param argc
 * @param argv
 * @return
 */
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
    glutMouseFunc(mouseClick);
    glutMotionFunc(mouseMotion);
    glutPassiveMotionFunc(mouseMovement);
    glutReshapeFunc(reshape);

    init();
    write();

    glutMainLoop();

    return 0;
}

float idleAngle = 0.02;
float pentagonAngle = 0;
float pentagonScale = 1.0;

/**
 * Display the shapes and the background
 */
void display()
{
    glClearColor(currentColour[0], currentColour[1], currentColour[2], 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glLineWidth(6.0);
    glRotatef(pentagonAngle, 0.0, 0.0, 1.0);
    glScalef(pentagonScale, pentagonScale, pentagonScale);
    pentagon.draw();
    glLineWidth(1.0);
    glPopMatrix();

    star.draw();

    Star tmp;
    tmp.setStrokeColour(animatedStar);
    glLineWidth(widthAnimation);
    for (int i = 0; i < 10; i++)
    {
        tmp.vertices[i] = animatedStar.vertices[i] * (1.0f - timelapse) + star.vertices[i] * timelapse;
    }
    tmp.draw();

    glutSwapBuffers();
}

/**
 * on each frame do some stuff
 *
 * - increase the timelapse
 * - change the width of the animated star
 * - change the background strokeColour
 */
void idle()
{
    timelapse += finished ? (timeSpeed * -1) : timeSpeed;

    if (idleState)
    {
        mouseX < 600 ? (pentagonAngle += idleAngle) : (pentagonAngle -= idleAngle);
    }

    if (timelapse > 1.0)
    {
        finished = true;
    } else if (timelapse < 0)
    {
        finished = false;
    }
    if (finished)
    {
        widthAnimation += timelapse / 1000;
    } else
    {
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

/**
 * set the size of the screen at launch
 *
 * @param w represents the width of the screen
 * @param h represents the height of the screen
 */
void reshape(int w, int h)
{
    glutReshapeWindow(screenSize[0], screenSize[1]);
}

/**
 * method to handle the mouse clicks
 *
 * @param mouseButton represents the mouse button that
 * was clicked
 * @param state represents the current state of mouse
 * @param x the value where the mouse was clicked relative
 * to the width
 * @param y the value where the mouse was clicked relative
 * to the height
 */
void mouseClick(int mouseButton, int state, int x, int y)
{
    // store the idle state
    idleState = state != GLUT_DOWN;

    // assign the value of the button interacted
    // -1 means there is no button
    (state == GLUT_DOWN) ? (::mouseButton = mouseButton) : (::mouseButton = -1);

    // if the button was pressed
    if (state == GLUT_DOWN)
    {
        // the mouse coordinate is stored
        clickMouseX = x;
        clickMouseY = y;
    }
}

/**
 * method to handle the mouse motion
 *
 * @param x the value where the mouse is located relative
 * to the width
 * @param y the value where the mouse is located relative
 * to the height
 */
void mouseMotion(int x, int y)
{
    double mvMatrix[16];
    double projMatrix[16];
    int viewport[4];
    glGetIntegerv(GL_VIEWPORT, viewport);
    glGetDoublev(GL_MODELVIEW_MATRIX, mvMatrix);
    glGetDoublev(GL_PROJECTION_MATRIX, projMatrix);

    auto curY = double(viewport[3] - y);
    double objCurY, objCurX, objCurZ;
    gluUnProject((double) x, curY, 0.5, mvMatrix, projMatrix, viewport, &objCurX, &objCurY, &objCurZ);

    auto preY = double(viewport[3] - clickMouseY);
    double objPreY, objPreX, objPreZ;
    gluUnProject((double) clickMouseX, preY, 0.5, mvMatrix, projMatrix, viewport, &objPreX, &objPreY, &objPreZ);

    switch (mouseButton)
    {
        case GLUT_LEFT_BUTTON:
            dx += (float) (objCurX - objPreX) * 2.5f;
            dy -= (float) (objPreY - objCurY) * 2.5f;
            break;
        case GLUT_RIGHT_BUTTON:
            pentagonAngle -= (float) (clickMouseX - x);
            break;
        case GLUT_MIDDLE_BUTTON:
            pentagonScale -= (float) (clickMouseX - x) * 0.02f;
            break;
        default:
            break;
    }

    // stores the values of the mouse when it was clicked
    clickMouseX = x;
    clickMouseY = y;
}

/**
 * method to handle the mouse movement
 *
 * @param x the value where the mouse is located relative
 * to the width
 * @param y the value where the mouse is located relative
 * to the height
 */
void mouseMovement(int x, int y)
{
    mouseX = x;
    mouseY = y;
}

#pragma clang diagnostic pop