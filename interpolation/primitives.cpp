//#include "stdafx.h"
//#include <Windows.h>
//#include <math.h>
//#include <gl/GL.h>
//#include <gl/GLU.h>
//#include "primitives.h"
//
//
//void Pentagon::draw() {
//	glColor3f(1.0, 0.0, 0.0);
//	glBegin(GL_LINE_LOOP);
//	for (int i = 0; i < 5; i++) {
//		glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
//	}
//	glEnd();
//}
//
//void Star::draw() {
//	glColor3f(1.0, 0.0, 0.0);
//	glBegin(GL_LINE_LOOP);
//	for (int i = 0; i < 10; i++) {
//		glVertex3f(vertices[i].x, vertices[i].y, vertices[i].z);
//	}
//	glEnd();
//}
//
//void init() {
//	// initialize pentagon
//	float a = 2.0 * 3.1415 / 5.0;
//	p.vertices[0].x = 0.0;
//	p.vertices[0].y = 1.0;
//	p.vertices[0].z = 0.0;
//
//	for (int i = 1; i < 5; i++) {
//		p.vertices[i].x = p.vertices[0].x * cos(a * i) - p.vertices[0].y * sin(a * i);
//		p.vertices[i].y = p.vertices[0].y * cos(a * i) + p.vertices[0].x * sin(a * i);
//		p.vertices[i].z = 0.0;
//	}
//
//	// initialize star, index 0, 2, 4, 6, 8
//	for (int i = 0; i < 5; i++) {
//		s.vertices[2*i].x = p.vertices[i].x;
//		s.vertices[2*i].y = p.vertices[i].y;
//		s.vertices[2*i].z = p.vertices[i].z;
//	}
//	// initialize star, index 1, 3, 5, 7, 9
//	float b = a / 2.0;
//	for (int i = 0; i < 5; i++) {
//		s.vertices[2*i + 1].x = (s.vertices[2*i].x * cos(b) - s.vertices[2*i].y * sin(b)) / 2.0;
//		s.vertices[2*i + 1].y = (s.vertices[2*i].y * cos(b) + s.vertices[2*i].x * sin(b)) / 2.0;
//		s.vertices[2*i + 1].z = 0.0;
//	}
//
//	// initialize 5 mid-points on the 5 edges of the pentagon
//	for (int i = 1; i <= 4; i++) {
//		m[i - 1].x = (p.vertices[i - 1].x + p.vertices[i].x) / 2.0;
//		m[i - 1].y = (p.vertices[i - 1].y + p.vertices[i].y) / 2.0;
//		m[i - 1].z = (p.vertices[i - 1].z + p.vertices[i].z) / 2.0;
//	}
//	m[4].x = (p.vertices[4].x + p.vertices[0].x) / 2.0;
//	m[4].y = (p.vertices[4].y + p.vertices[0].y) / 2.0;
//	m[4].z = (p.vertices[4].z + p.vertices[0].z) / 2.0;
//
//	// initialize the inbetween frame, which is a Star
//	for (int i = 0; i < 5; i++) {
//		ibt.vertices[2*i].x = p.vertices[i].x;
//		ibt.vertices[2*i].y = p.vertices[i].y;
//		ibt.vertices[2*i].z = p.vertices[i].z;
//
//		ibt.vertices[2*i + 1].x = m[i].x;
//		ibt.vertices[2*i + 1].y = m[i].y;
//		ibt.vertices[2*i + 1].z = m[i].z;
//	}
//
//	float tgt[2] = {2, 2};
//}
//
//float[2] asdasd(float[1][2])
//{
//
//}

bool animationCompleted = false;

void main() {
    for (int i = 0; i < 5; i++) {
        // Takes the points of the star and interpolates them into a pentagon, i * 2 because there is 10 points, whereas the pentagon has 5
        // (i * 2) + 1 is the inside points of the star, i * 2 is the outer points
        Points points = Interpolation(
                star.vertices[(i * 2) + 1],
                !animationCompleted ? star.vertices[i * 2] : star.verticesStartPos[(i * 2) + 1],
                animationTimer
        );
        star.vertices[(i * 2) + 1][0] = points.x;
        star.vertices[(i * 2) + 1][1] = points.y;
    }
    animationCompleted = star.vertices[1][0] == star.vertices[0][0] && star.vertices[1][1] == star.vertices[0][1];
}