#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include "point.h"

class Pentagon
{
public:
    Pentagon() = default;

    Point vertices[5];

    void draw();

    void setColour(float r, float g, float b);

private:
    float colour[3] = {
         1.0,
         0,
         0
    };
};

class Star
{
public:
    Star() = default;

    Point vertices[10];

    void draw();

    void setColour(float r, float g, float b);

    void setColour(Star s);

private:
    float colour[3] = {
            1.0,
            0,
            0
    };
};

extern Pentagon p;
extern Star s;
extern Star ibt;
extern Point m[5];

void init();

void write();

#endif
