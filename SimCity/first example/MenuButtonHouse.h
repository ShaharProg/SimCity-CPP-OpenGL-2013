//#pragma once
//#include "menubutton.h"
//class MenuButtonHouse :
//	public MenuButton
//{
//public:
//	MenuButtonHouse(void);
//	~MenuButtonHouse(void);
//};

#pragma once
#include "MenuButton.h"
#include "House.h"


class SimCity;//forward declaration


class MenuButtonHouse :
	public MenuButton
{
	//vector<Point> vec;
	// vector of points of unfinished Road
	// when finished -> add Road to fieldObjects and clean vec

public:
	MenuButtonHouse(char* name) : MenuButton(name){}
	

	~MenuButtonHouse(void);
	virtual void action(Point& p);

	virtual void draw2d()
	{
		glPushMatrix();
			glTranslated(0,1,0);
			glRotated(180,0,0,1);
			DrawHouse();
		glPopMatrix();

		MenuButton::draw2d();
	}

	
	void DrawHouse()
	{
				glPushMatrix();
				glTranslated(0.2,0.4,0);
					DrawWindow();
				glPopMatrix();
				glPushMatrix();
				glTranslated(0.2,0.1,0);
					DrawWindow();
				glPopMatrix();
				glPushMatrix();
				glTranslated(-0.2,0.4,0);
					DrawWindow();
				glPopMatrix();
				glPushMatrix();
				glTranslated(-0.2,0.1,0);
					DrawWindow();
				glPopMatrix();
			
			// door
			glColor3d(0.4,0.4,0);// white
			glBegin(GL_POLYGON);
				glVertex2d(-0.15, -0.6);// left bottom
				glVertex2d(0.15, -0.6);// right bottom
				glVertex2d(0.15, -0.2);// right top
				glVertex2d(-0.15, -0.2);// left top
			glEnd();

		
			// walls
			glColor3d(0.85,0.85,0.85);// grey
			glBegin(GL_POLYGON);
				glVertex2d(-0.5, -0.6);// left bottom
				glVertex2d(0.5, -0.6);// right bottom
				glVertex2d(0.5, 0.6);// right top
				glVertex2d(-0.5, 0.6);// left top
			glEnd();
	}

	void DrawWindow()
	{
		glPushMatrix();
		
		
			//glColor3d(0,0,0);// black
			//glBegin(GL_LINE_LOOP);
			//	glVertex2d(-0.1, 0);// left bottom
			//	glVertex2d(0.1, 0);// right bottom
			//	glVertex2d(0.1, 0);// right top
			//	glVertex2d(-0.1, 0);// left top
			//glEnd();

			// frame
			glColor3d(0,0,0);// black
			glBegin(GL_LINE_LOOP);
				glVertex2d(-0.1, -0.1);// left bottom
				glVertex2d(0.1, -0.1);// right bottom
				glVertex2d(0.1, 0.1);// right top
				glVertex2d(-0.1, 0.1);// left top
			glEnd();

			// glasses
			glColor3d(1,1,0);// yellow
			glBegin(GL_POLYGON);
				glVertex2d(-0.1, -0.1);// left bottom
				glVertex2d(0.1, -0.1);// right bottom
				glVertex2d(0.1, 0.1);// right top
				glVertex2d(-0.1, 0.1);// left top
			glEnd();
		glPopMatrix();

	}

};

