#include <iostream>
#include "intersect.h"
#include "line.h"
#include <vector>

using namespace std;

vector<struct Position> points;

int main()
{
	Line line1(0,0,1,1);
	Line Line2(1,0,0,1);

	struct Position res = line1.intersect(Line2);
	std::cout << res.x << std::endl;
	std::cout << res.y << std::endl;
}
