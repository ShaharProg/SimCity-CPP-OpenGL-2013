#pragma once
#include "fieldobject.h"
#include "Point.h"
#include "GLUT.H"


class Field;//forward declaration

class House :
	public FieldObject
{
public:
	static const int numOfHouseTypes = 2, minFloors=4,maxFloors= 12;

	Point p;
	int type,floors;
	House(Point p) : p(p)
	{
		type = rand() % numOfHouseTypes + 1;     // type in the range 1 to numOfHouseTypes
		floors = rand() % maxFloors + minFloors;     // type in the range minFloors to maxFloors
	}
	~House(void);

	virtual void draw2d();

	
	static void DrawHouse();
	static void DrawHouse2(int floors);
	static void DrawHouse1(int floors, int tx, int n,int th);

};

