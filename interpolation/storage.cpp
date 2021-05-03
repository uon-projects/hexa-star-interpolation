//
// Created by Teodor on 12/02/2021.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "storage.h"

using namespace std;

Storage::Storage() = default;

Storage::~Storage() = default;

void Storage::write(const std::string& data)
{
    verticesBuilder += data;
}

void Storage::createFile()
{
    // open a file for writing pentagon vertices
    ofstream writeVertices("vertices.txt");

    writeVertices << verticesBuilder;
    verticesBuilder = "";

    writeVertices.close();
}

void Storage::readPentagon(Point *points)
{
    readShape(points, "PENTAGON_VERTICES");
}

void Storage::readStar(Point *points)
{
    readShape(points, "STAR_VERTICES");
}

void Storage::readAnimatedStar(Point *points)
{
    readShape(points, "ANIMATED_STAR_VERTICES");
}

void Storage::readShape(Point *points, const std::string& tag)
{
    ifstream readVertices("vertices.txt");
    std::string line;

    bool found = false;
    int index = 0;
    while (std::getline(readVertices, line))
    {
        if (line == "#BEGIN " + tag)
        {
            found = true;
            continue;
        } else if (line == "#END " + tag)
        {
            break;
        }
        if (!found)
        {
            continue;
        }
        std::istringstream iss(line);
        float x, y, z;
        if (!(iss >> x >> y >> z))
        {
            x = 0;
            y = 0;
            z = 0;
        }
        points[index].x = x;
        points[index].y = y;
        points[index].z = z;
        index++;
    }
}
