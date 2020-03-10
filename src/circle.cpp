#include "circle.h"

void Circle::lineIntersect(const Line& line, vector<struct Position>& res_vector) {
	struct Position res1;
	struct Position res2;

	long long delta_x1 = line.x2 - line.x1;
	long long delta_y1 = line.y2 - line.y1;
	long long delta_x2 = this->x - line.x1;
	long long delta_y2 = this->y - line.y1;
	long long cross = delta_x1 * delta_y2 - delta_x2 * delta_y1;
	long long norm = delta_x1 * delta_x1 + delta_y1 * delta_y1;
	double denominator = sqrt((double)norm);
	double distance = fabs(cross / denominator);
	if (distance - this->r * 1.0 < eps) {
		double r_ = (delta_x2 * delta_x1 + delta_y2 * delta_y1) * 1.0 / norm;
		double delta_x3 = line.x1 + delta_x1 * r_;
		double delta_y3 = line.y1 + delta_y1 * r_;
		double delta_x4 = delta_x1 / denominator;
		double delta_y4 = delta_y1 / denominator;
		double delta_x5 = delta_x3 - this->x;
		double delta_y5 = delta_y3 - this->y;

		if (fabs(distance - 1.0 * this->r) < eps) {
			res1.x = delta_x3;
			res1.y = delta_y3;
			res_vector.push_back(res1);
			return;
		}

		double base = sqrt(this->r * this->r - (delta_x5 * delta_x5 + delta_y5 * delta_y5));
		res1.x = delta_x3 + delta_x4 * base;
		res1.y = delta_y3 + delta_y4 * base;
		res2.x = delta_x3 - delta_x4 * base;
		res2.y = delta_y3 - delta_y4 * base;
		res_vector.push_back(res1);
		res_vector.push_back(res2);
	} 
}



void Circle::circleIntersect(const Circle& circle, vector<struct Position>& res_vector) {
	struct Position res1;
	struct Position res2;

	long long subs1 = this->x * this->x - 2 * this->x * circle.x + circle.x * circle.x + 
		this->y * this->y - 2 * this->y * circle.y + circle.y * circle.y;
	long long sigma = (this->r * this->r + 2 * this->r * circle.r + circle.r * circle.r - 
		this->x * this->x + 2 * this->x * circle.x - circle.x * circle.x - 
		this->y * this->y + 2 * this->y * circle.y - circle.y * circle.y) * 
		(-this->r * this->r + 2 * this->r * circle.r - circle.r * circle.r + subs1);
	if (subs1 == 0 || sigma < 0) {
		return;
	} else {
		double sigma1 = sqrt((double)sigma);
		long long subs2 = -this->r * this->r * this->x + this->r * this->r * circle.x + circle.r * circle.r * this->x - circle.r * circle.r * circle.x + this->x * this->x * this->x - this->x * this->x * circle.x - this->x * circle.x * circle.x + this->x * this->y * this->y - 2 * this->x * this->y * circle.y + this->x * circle.y * circle.y + circle.x * circle.x * circle.x + circle.x * this->y * this->y - 2 * circle.x * this->y * circle.y + circle.x * circle.y * circle.y;
		long long subs3 = -this->r * this->r * this->y + this->r * this->r * circle.y + circle.r * circle.r * this->y - circle.r * circle.r * circle.y + this->x * this->x * this->y + this->x * this->x * circle.y - 2 * this->x * circle.x * this->y - 2 * this->x * circle.x * circle.y + circle.x * circle.x * this->y + circle.x * circle.x * circle.y + this->y * this->y * this->y - this->y * this->y * circle.y - this->y * circle.y * circle.y + circle.y * circle.y * circle.y;
		res1.x = (subs2 - sigma1 * this->y + sigma1 * circle.y) / (2 * subs1);
		res2.x = (subs2 + sigma1 * this->y - sigma1 * circle.y) / (2 * subs1);
		res1.y = (subs3 + sigma1 * this->x - sigma1 * circle.x) / (2 * subs1);
		res2.y = (subs3 - sigma1 * this->x + sigma1 * circle.x) / (2 * subs1);
		res_vector.push_back(res1);
		res_vector.push_back(res2);
	}
}