#ifndef PRIMITIVES_H
#define PRIMITIVES_H

struct Point {
	float x;
	float y;
	float z;

	Point() {}

	Point (float a, float b, float c) {
		x = a;
		y = b;
		z = c;
	}

	Point operator * (float k) {
		return Point(x * k, y * k, z * k);
	}
	
	Point operator + (Point p) {
		return Point(x + p.x, y + p.y, z + p.z);
	}
};

class Pentagon {
public:
	Pentagon() {}
	Point vertices[5];
	void draw();
};

class Star {
public:
	Star() {}
	Point vertices[10];
	void draw();
};

extern Pentagon p;
extern Star s;
extern Star ibt;
extern Point m[5];

void init();
#endif
