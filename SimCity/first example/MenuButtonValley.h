#pragma once
#include "MenuButton.h"
#include "Valley.h"


class SimCity;//forward declaration


class MenuButtonValley :
	public MenuButton
{
	//vector<Point> vec;
	// vector of points of unfinished Road
	// when finished -> add Road to fieldObjects and clean vec

public:
	MenuButtonValley(char* name) : MenuButton(name){}
	

	~MenuButtonValley(void);
	virtual void action(Point& p);

	virtual void draw2d()
	{
		glPushMatrix();
			glTranslated(0,1,0);
			DrawValley();
		glPopMatrix();

		MenuButton::draw2d();
	}

	
	

	void DrawValley()
	{
		int radius;
		double pi = 3.14159;
		//for (radius=0.01; radius < 0.5; radius+=0.01)
		{
		
				glColor4d(0,1,1, 0.2);
				glBegin(GL_POLYGON);
				for(double i = 0; i < 2 * pi; i += pi / 6) //<-- Change this Value
 						glVertex3f(cos(i) * 0.5, sin(i) * 0.5, 0.0);
				glEnd();
		}
	}

};

