#pragma once
#include "Point.h"
using namespace std;
#include <vector>
#include "GLUT.H"

//#define PI 3.14159

//typedef pair<Point,graph> neighbor;
//typedef vector<neighbor*> graph;

typedef struct vertex{
	Point p;
	vector<struct vertex*> neighbors;
} Vertex;

typedef vector<Vertex*>	Graph;

//typedef vector<neighbor*> graph;


class SimCity;//forward declaration

class Road
{
public:
	SimCity *simCity;

	vector<Point> vec;
	vector<int> roadType;// 0 - regular, 1 - bridge, 2 - tunnel


	static const double ROAD_WIDTH;

	Road(Point p, SimCity *simCity);
	//{
	//	vec.push_back(p);
	//	//*this += p;
	//};

	~Road(void);

	void operator+=(Point& point);
	int decideLegType(double x1, double h1, double z1, double x2=0, double h2=0, double z2=0, double ddx=0.0, double ddh=0.0, double ddz=0.0);

	virtual void draw2d();

};

