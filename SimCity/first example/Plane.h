#pragma once
#include "fieldobject.h"
#include "Point.h"
#include "GLUT.H"


class Field;//forward declaration

class Plane :
	public FieldObject
{
public:
	Point p;

	//double planex=0,planey=8,planez=15;
	double plane_angle,plane_speed,plane_ang_speed;
	double pitch;

	Plane(Point p) : p(p)
	{
		plane_angle=PI/2;
		plane_speed=0;
		plane_ang_speed=0;
		pitch = 0;
	}
	~Plane(void);

	virtual void draw2d();

	
	static void DrawPlane();

};