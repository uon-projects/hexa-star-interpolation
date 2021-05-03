#include "stdafx.h"
#include <Windows.h>
#include <cmath>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <iterator>
#include "shapes.h"
#include "storage.h"

void Shape::drawShape()
{
    glColor3f(strokeColour[0], strokeColour[1], strokeColour[2]);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<getTotalPoints(); i++)
    {
        Point vertex = getPoints()[i];
        glVertex3f(vertex.x, vertex.y, vertex.z);
    }
    glEnd();
}

void Shape::setStrokeColour(float r, float g, float b)
{
    strokeColour[0] = r;
    strokeColour[1] = g;
    strokeColour[2] = b;
}

void Shape::setStrokeColour(Shape s)
{
    strokeColour[0] = s.strokeColour[0];
    strokeColour[1] = s.strokeColour[1];
    strokeColour[2] = s.strokeColour[2];
}

Point *Shape::getPoints()
{
    return nullptr;
}

int Shape::getTotalPoints()
{
    return 0;
}

void Pentagon::draw()
{
    drawShape();
}

Point *Pentagon::getPoints()
{
    return vertices;
}

int Pentagon::getTotalPoints()
{
    return 5;
}

void Star::draw()
{
    drawShape();
}

Point *Star::getPoints()
{
    return vertices;
}

int Star::getTotalPoints()
{
    return 10;
}

void init()
{
    Storage::readPentagon(pentagon.vertices);
    Storage::readStar(star.vertices);
    Storage::readAnimatedStar(animatedStar.vertices);

    pentagon.setStrokeColour(.007, .095, .237);
    star.setStrokeColour(.237, .210, .007);
    animatedStar.setStrokeColour(.007, .237, .088);
}

void write()
{
    Storage storage;

    storage.write("#BEGIN SHAPES_CONTENT\n\n");
    storage.write("#BEGIN PENTAGON_VERTICES\n");
    for (auto & vertex : pentagon.vertices)
    {
        storage.write(
                std::to_string(vertex.x) + " " +
                std::to_string(vertex.y) + " " +
                std::to_string(vertex.z) + " " +
                "\n"
        );
    }
    storage.write("#END PENTAGON_VERTICES\n\n");

    storage.write("#BEGIN STAR_VERTICES\n");
    for (auto & vertex : star.vertices)
    {
        storage.write(
                std::to_string(vertex.x) + " " +
                std::to_string(vertex.y) + " " +
                std::to_string(vertex.z) + " " +
                "\n"
        );
    }
    storage.write("#END STAR_VERTICES\n\n");

    storage.write("#BEGIN ANIMATED_STAR_VERTICES\n");
    for (auto & vertex : animatedStar.vertices)
    {
        storage.write(
                std::to_string(vertex.x) + " " +
                std::to_string(vertex.y) + " " +
                std::to_string(vertex.z) + " " +
                "\n"
        );
    }
    storage.write("#END ANIMATED_STAR_VERTICES\n\n");
    storage.write("#END SHAPES_CONTENT\n");

    storage.createFile();
}


