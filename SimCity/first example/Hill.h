#pragma once
#include "fieldobject.h"
#include "Point.h"
#include "GLUT.H"
#include <math.h>

class Hill :
	public FieldObject
{
public:

	Point p;
	Hill(Point p) : p(p)
	{
		
	}
	~Hill(void);

	virtual void draw2d()
	{
		glPushMatrix();
			glTranslated(p.x,p.y,0);
			glScaled(0.3,0.3,1);
			DrawHill();
		glPopMatrix();
	}

	
static void DrawHill()
{
	double radius;
	double pi = 3.14159;
	for (radius=0.01; radius < 0.5; radius+=0.01)
	{
		
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			glColor4d(0,1,0, 0.01);
			glBegin(GL_POLYGON);
			for(double i = 0; i < 2 * pi; i += pi / 6) //<-- Change this Value
 					glVertex3f(cos(i) * radius, sin(i) * radius, 0.0);
			glEnd();
	glDisable(GL_BLEND);
	}
}

};

