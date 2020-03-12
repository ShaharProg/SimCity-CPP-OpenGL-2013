#pragma once
#include "MenuButton.h"
#include "Hill.h"


class SimCity;//forward declaration


class MenuButtonHill :
	public MenuButton
{
	//vector<Point> vec;
	// vector of points of unfinished Road
	// when finished -> add Road to fieldObjects and clean vec

public:
	MenuButtonHill(char* name) : MenuButton(name){}
	

	~MenuButtonHill(void);
	virtual void action(Point& p);

	virtual void draw2d()
	{
		glPushMatrix();
			glTranslated(0,1,0);
			DrawHill();
		glPopMatrix();
		MenuButton::draw2d();
	}

	
void DrawHill()
{
	int radius;
	double pi = 3.14159;
	//for (radius=0.01; radius < 0.5; radius+=0.01)
	{
		
			glColor4d(0,1,0, 0.2);
			glBegin(GL_POLYGON);
			for(double i = 0; i < 2 * pi; i += pi / 6) //<-- Change this Value
 					glVertex3f(cos(i) * 0.5, sin(i) * 0.5, 0.0);
			glEnd();
	}
}


//---------------------------------------
//{
//	int i,j,r=70;
//	double dist,alpha,ca,h;
//	double red,green,blue;
//
//	for(i=p.y-r+1; i<p.y+r; i++)
//	{
//		for(j=p.x-r+1; j<p.x+r; j++)
//		{
//			if(i>0 && i<HEIGHT && j>=0 && j< WIDTH)	// in field ranges
//			{
//				dist = sqrt(double(p.x-j)*(p.x-j)+(p.y-i)*(p.y-i));
//				if(dist<r)	// in circle
//				{
//					ca = dist/r;
//					alpha = acos(ca);
//					h = (double)r*sin(alpha)*(1.0/70.0)*0.1;// problem!!! we need to take care of the range -5..
//					
//					
//
//					this->simCity->field->level_0_heights[i][j] += h;
//					
//					if (dist==0)cout<<this->simCity->field->level_0_heights[i][j]<<endl;
//
//				}
//			}
//		}
//	}
//}
//---------------------------------------


};

