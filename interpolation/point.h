//
// Created by Teodor on 12/02/2021.
//

#ifndef INTERPOLATION_POINT_H
#define INTERPOLATION_POINT_H

/**
 * Point struct to store the coordinates of the vertices
 * for each shape
 *
 * coordinates in 3D format stored inside x, y and z
 */
struct Point
{
    float x;
    float y;
    float z;

    Point() = default;

    /**
     * Creates a new point with assigned coordinates
     *
     * @param x the x coordinate
     * @param y the y coordinate
     * @param z the z coordinate
     */
    Point(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    /**
     * Util operator function to multiply the point by
     * a value
     *
     * @param k the value that the point must be multiplied
     * @return the current point with the values multiplied
     */
    Point operator*(float k) const
    {
        return {x * k, y * k, z * k};
    }

    /**
     * Util operator function to increase a point by a
     * point
     *
     * @param p the point that should be added to the
     * current point
     * @return the current point with the additions from
     * the added point
     */
    Point operator+(Point p) const
    {
        return {x + p.x, y + p.y, z + p.z};
    }
};

#endif //INTERPOLATION_POINT_H
