//
// Created by Teodor on 12/02/2021.
//

#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include "point.h"
#include <list>

class Shape
{
public:
    /**
     * draws the pentagon
     */
    void drawShape();

    /**
     * sets the strokeColour of the pentagon'star stroke
     *
     * @param r the value for red
     * @param g the value for green
     * @param b the value for blue
     */
    void setStrokeColour(float r, float g, float b);

    /**
     * sets the strokeColour of the star based on
     * the strokeColour of another star
     *
     * @param s the star that we want to copy
     * its strokeColour
     */
    void setStrokeColour(Shape s);

    /**
     * Virtual method to get the points based
     * on the class that extends the shape
     *
     * @return the points array
     */
    virtual Point *getPoints();

    /**
     * Virtual method to get the total number
     * of points
     *
     * @return the number of points
     */
    virtual int getTotalPoints();

private:
    float strokeColour[3] = {
            1.0,
            0,
            0
    };

};

/**
 * Pentagon shape class
 *
 * a pentagon has 5 vertices
 */
class Pentagon : public Shape
{
public:
    Pentagon() = default;

    /**
     * draws the pentagon
     */
    void draw();

    Point * getPoints() override;

    int getTotalPoints() override;

public:
    Point vertices[5];
};

class Star : public Shape
{
public:
    Star() = default;

    /**
     * draws the star
     */
    void draw();

    Point * getPoints() override;

    int getTotalPoints() override;

public:
    Point vertices[10];
};

extern Pentagon pentagon;
extern Star star;
extern Star animatedStar;

void init();

void write();

#endif
