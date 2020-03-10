#ifndef CIRCLE__H
#define CIRCLE__H

#include "intersect.h"
#include "line.h"
#include <math.h>
#include <vector>

class Circle 
{
public:
	Circle(long long x, long long y, long long r) {
		this->x = x;
		this->y = y;
		this->r = r;
	}
	Circle() {
		this->x = 0;
		this->y = 0;
		this->r = 0;
	}
	long long x, y, r;
	void lineIntersect(const Line&, vector<struct Position>&);
	void circleIntersect(const Circle&, vector<struct Position>&);
};



#endif // !CIRCLE__H
