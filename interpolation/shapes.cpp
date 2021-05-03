#include "stdafx.h"
#include <Windows.h>
#include <cmath>
#include <gl/GL.h>
#include <gl/GLU.h>
#include "shapes.h"
#include "storage.h"

void Pentagon::draw()
{
    glColor3f(colour[0], colour[1], colour[2]);
    glBegin(GL_LINE_LOOP);
    for (auto &vertex : vertices)
    {
        glVertex3f(vertex.x, vertex.y, vertex.z);
    }
    glEnd();
}

void Pentagon::setColour(float r, float g, float b)
{
    colour[0] = r;
    colour[1] = g;
    colour[2] = b;
}

void Star::draw()
{
    glColor3f(colour[0], colour[1], colour[2]);
    glBegin(GL_LINE_LOOP);
    for (auto &vertex : vertices)
    {
        glVertex3f(vertex.x, vertex.y, vertex.z);
    }
    glEnd();
}

void Star::setColour(float r, float g, float b)
{
    colour[0] = r;
    colour[1] = g;
    colour[2] = b;
}

void Star::setColour(Star s)
{
    colour[0] = s.colour[0];
    colour[1] = s.colour[1];
    colour[2] = s.colour[2];
}

void init()
{
    Storage::readPentagon(p.vertices);
    Storage::readStar(s.vertices);
    Storage::readAnimatedStar(ibt.vertices);

    p.setColour(.007, .095, .237);
    s.setColour(.237, .210, .007);
    ibt.setColour(.007, .237, .088);
}

void write()
{
    Storage storage;

    storage.writeD("#BEGIN SHAPES_CONTENT\n\n");
    storage.writeD("#BEGIN PENTAGON_VERTICES\n");
    for (auto & vertex : p.vertices)
    {
        storage.writeD(
                std::to_string(vertex.x) + " " +
                std::to_string(vertex.y) + " " +
                std::to_string(vertex.z) + " " +
                "\n"
        );
    }
    storage.writeD("#END PENTAGON_VERTICES\n\n");

    storage.writeD("#BEGIN STAR_VERTICES\n");
    for (auto & vertex : s.vertices)
    {
        storage.writeD(
                std::to_string(vertex.x) + " " +
                std::to_string(vertex.y) + " " +
                std::to_string(vertex.z) + " " +
                "\n"
        );
    }
    storage.writeD("#END STAR_VERTICES\n\n");

    storage.writeD("#BEGIN ANIMATED_STAR_VERTICES\n");
    for (auto & vertex : ibt.vertices)
    {
        storage.writeD(
                std::to_string(vertex.x) + " " +
                std::to_string(vertex.y) + " " +
                std::to_string(vertex.z) + " " +
                "\n"
        );
    }
    storage.writeD("#END ANIMATED_STAR_VERTICES\n\n");
    storage.writeD("#END SHAPES_CONTENT\n");

    storage.writeVertices();
}


