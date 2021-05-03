//
// Created by teo on 03/05/2021.
//

#ifndef INTERPOLATION_STORAGE_H
#define INTERPOLATION_STORAGE_H

#include <string>
#include "point.h"

class Storage
{
public:
    Storage();

    ~Storage();

public:
    void writeVertices();

    void writeD(const std::string& data);

    static void readPentagon(Point points[5]);

    static void readStar(Point points[10]);

    static void readAnimatedStar(Point points[10]);

private:
    static void readShape(Point points[], const std::string& tag);

private:
    std::string verticesBuilder;
};

#endif //INTERPOLATION_STORAGE_H
