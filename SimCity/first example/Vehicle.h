#pragma once
#include "fieldobject.h"
#include "Point.h"
#include "Road.h"
#include "GLUT.H"


class Field;//forward declaration

class Vehicle : public FieldObject
{
private:
	//static int idGenerator;
public:
	int vId;
	Point p;
	static const int numOfVehicleTypes = 2;
	int type;

	Vertex	*u,*v;
	double radiusFromU, legSize;

	//double Vehiclex=0,Vehicley=8,Vehiclez=15;
	double vehicle_angle,vehicle_speed,vehicle_ang_speed;
	double pitch,dx,dz,dh;

	Vehicle(Vertex* u,Vertex* v) : u(u),v(v),vId(0), radiusFromU(1.5*vId), p(0,0,0), dx(0), dz(0), dh(0)
	{
		type = rand() % numOfVehicleTypes + 1;     // type in the range 1 to numOfVehicleTypes
		this->setMovement(this->u->p,this->v->p);
		// chack the radiusFromU if it's not out of bounds... insert into a loop, calc offset.. add destination
	}
	~Vehicle(void);

	virtual void draw2d();

	void move();
	void setMovement(Point& p1,Point& p2)
	{
		legSize = sqrt( (p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y) + (p2.z-p1.z)*(p2.z-p1.z) );

		int angleSidewiseFlip		= (p1.z < p2.z) ? 1 : -1 ;

		vehicle_angle		= - angleSidewiseFlip*acos( (p2.x-p1.x)/legSize );
		pitch				= asin( (p2.y-p1.y)/legSize );
		vehicle_ang_speed	= 0;// ??
		vehicle_speed		= 0.5;

		dx					= cos(pitch)*cos(-vehicle_angle);
		dz					= cos(pitch)*sin(-vehicle_angle);
		dh					= (abs(sin(pitch))<0.01)?0:sin(pitch);

		p = Point(p1.x+dx,p1.y+dh,p1.z+dz);
	}

	
	static void DrawVehicle();
	static void DrawVehicle2();

};

//int Vehicle::idGenerator = 0;
