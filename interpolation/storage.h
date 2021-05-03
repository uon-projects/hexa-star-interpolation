//
// Created by Teodor on 12/02/2021.
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
    /**
     * Writes the passed string into the current
     * string builder.
     *
     * @param data the string that should be written
     * inside the file
     */
    void write(const std::string& data);

    /**
     * Creates the file based on the current string
     * builder.
     */
    void createFile();

    /**
     * Reads the pentagon's points from the storage.
     *
     * @param points represents the array of points
     * where the values read should be written
     */
    static void readPentagon(Point points[5]);

    /**
     * Reads the star's points from the storage.
     *
     * @param points represents the array of points
     * where the values read should be written
     */
    static void readStar(Point points[10]);

    /**
     * Reads the animated star's points from the storage.
     *
     * @param points represents the array of points
     * where the values read should be written
     */
    static void readAnimatedStar(Point points[10]);

private:
    /**
     * Read the shape values from storages based on a tag
     *
     * @param points the array points
     * @param tag the tag that represents the object
     */
    static void readShape(Point points[], const std::string& tag);

private:
    std::string verticesBuilder;
};

#endif //INTERPOLATION_STORAGE_H
