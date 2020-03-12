#pragma once
#include "MenuButton.h"
#include "Tree.h"


class SimCity;//forward declaration


class MenuButtonTree :
	public MenuButton
{
	//vector<Point> vec;
	// vector of points of unfinished Road
	// when finished -> add Road to fieldObjects and clean vec

public:
	MenuButtonTree(char* name) : MenuButton(name){}
	

	~MenuButtonTree(void);
	virtual void action(Point& p);

	virtual void draw2d()
	{
		glPushMatrix();
			glTranslated(0,1.8,0);
			glRotated(180,0,0,1);
			DrawTree(0.6,0);
		glPopMatrix();

		MenuButton::draw2d();
	}

	
	void DrawTree(double len,int a)
	{
		if(len>0.003)
		{
			glLineWidth(5*len);
			glColor3d(len,0.2+ 0.8*(1-len),0);
			glBegin(GL_LINES);
				glVertex2d(0,0);
				glVertex2d(0,len);
			glEnd();
			// top
			glPushMatrix();
				glTranslated(0,len,0);
				glRotated(a,0,0,1);
				DrawTree(len*0.6,-5+rand()%10);
			glPopMatrix();
			glPushMatrix();
				glTranslated(0,len,0);
				glRotated(-80,0,0,1);
				DrawTree(len*0.5,0);
			glPopMatrix();
			glPushMatrix();
				glTranslated(0,len,0);
				glRotated(80,0,0,1);
				DrawTree(len*0.5,0);
			glPopMatrix();
		}
	}

};

