#pragma once
#include "fieldobject.h"
#include "Point.h"
#include "GLUT.H"


class Field;//forward declaration

class Tree :
	public FieldObject
{

public:
	static const int numOfTreeTypes = 2;
	Point p;
	int type;
	Tree(Point p) : p(p)
	{
		type = rand() % numOfTreeTypes + 1;     // type in the range 1 to numOfTreeTypes
	}
	~Tree(void);

	virtual void draw2d();

	
	static void DrawTree1();
	static void DrawTree2();

};

