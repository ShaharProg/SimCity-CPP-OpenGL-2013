#pragma once

#define PI 3.14

class Point
{
public:
	double x, y, z;
	Point() : x(0), y(0), z(0){}
	Point(double x, double z): x(x), y(0), z(z) {}
	Point(double x, double y, double z): x(x), y(y), z(z) {}
	~Point(void);
};

