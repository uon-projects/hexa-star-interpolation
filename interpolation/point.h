//
// Created by teo on 03/05/2021.
//

#ifndef INTERPOLATION_POINT_H
#define INTERPOLATION_POINT_H

struct Point
{
    float x;
    float y;
    float z;

    Point() = default;

    Point(float a, float b, float c)
    {
        x = a;
        y = b;
        z = c;
    }

    Point operator*(float k) const
    {
        return {x * k, y * k, z * k};
    }

    Point operator+(Point p) const
    {
        return {x + p.x, y + p.y, z + p.z};
    }
};

#endif //INTERPOLATION_POINT_H
