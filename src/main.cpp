#include <iostream>
#include "intersect.h"
#include "line.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>

using namespace std;

vector<struct Position> points;
vector<Line> lines;

int main(int argc, char** argv)
{
	ifstream input;
	ofstream output;
	int n;
	char flag;
	long long x1, y1, x2, y2;
	int line_num = 0;

	input.open("input.txt");
	
	for (int index = 0; index < argc; index++) {
		if ((string)argv[index] == "-i") {
			input.open(argv[index + 1]);
			index++;
		} else if ((string)argv[index] == "-o") {
			output.open(argv[index + 1]);
			index++;
		}
	}
	
	input >> n;
	for (int i = 0; i < n; i++) {
		input >> flag;
		if (flag == 'L') {
			input >> x1 >> y1 >> x2 >> y2;
			Line tmpLine(x1, y1, x2, y2);
			lines.push_back(tmpLine);
			line_num++;
		}
	}
	cout << line_num << endl;

	for (int i = 0; i < line_num; i++) {
		for (int j = i + 1; j < line_num; j++) {
			Line& line1 = lines[i];
			Line& line2 = lines[j];
			long long denominator = line1.a * line2.b - line1.b * line2.a;
			if (denominator != 0) {
				points.push_back(line1.intersect(line2));
			} else {
			}
			
		}
	}
	

	// delete the repeat points
	sort(points.begin(), points.end(), posCompare);
	auto points_end = unique(points.begin(), points.end(), posEqual);
	cout << points_end - points.begin() << endl;

	return 0;
}
