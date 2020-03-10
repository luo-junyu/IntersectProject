#include "line.h"
/*
	Bulid a line (ax + by + c = 0)
	INPUT: 2 points: x1,y1,x2,y2
*/
Line::Line(int x1, int y1, int x2, int y2)
{
	int y2_y1 = y2 - y1;
	int x2_x1 = x2 - x1;
	this->a = y2_y1;
	this->b = -1 * (x2_x1);
	this->c = y1 * (x2_x1)-x1 * (y2_y1);
}

Line::~Line()
{
}

struct Position Line::intersect(Line& other_line) {
	int lower = this->a * other_line.b - this->b * other_line.a;
	int x_upper = this->b * other_line.c - this->c * other_line.b;
	int y_upper = this->c * other_line.a - this->a * other_line.c;
	double x = x_upper * 1.0 / lower;
	double y = y_upper * 1.0 / lower;
	struct Position res;
	res.x = x;
	res.y = y;
	return res;
}
