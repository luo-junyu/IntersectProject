#ifndef LINE__H
#define LINE__H

#include "intersect.h"

class Line
{
public:
	Line(long long x1, long long y1, long long x2, long long y2);
	struct Position intersect(Line&);
	long long a, b, c;
	Line();
	~Line();
private:
	
};



#endif // !LINE__H
