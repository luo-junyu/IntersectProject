#ifndef LINE__H
#define LINE__H

#include "intersect.h"

class Line
{
public:
	Line(int x1, int y1, int x2, int y2);
	struct Position intersect(Line&);
	int a, b, c;
	Line();
	~Line();
private:
	
};



#endif // !LINE__H
