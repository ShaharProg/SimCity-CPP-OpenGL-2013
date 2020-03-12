#pragma once
#include "MenuButton.h"


class SimCity;//forward declaration


class MenuButtonSetCamera :
	public MenuButton
{
	//vector<Point> vec;
	// vector of points of unfinished Road
	// when finished -> add Road to fieldObjects and clean vec

public:
	MenuButtonSetCamera(char* name) : MenuButton(name){}
	

	~MenuButtonSetCamera(void);
	virtual void action(Point& p);
	virtual void actionUp(Point& p);
	virtual void actionMove(Point& p);

	virtual void draw2d()
	{
		glPushMatrix();
			glTranslated(0,1,0);
			glRotated(180,0,0,1);
			DrawMenuButtonSetCamera();
		glPopMatrix();

		MenuButton::draw2d();
	}

	
	void DrawMenuButtonSetCamera()
	{
		glPushMatrix();


			glEnable(GL_LINE_SMOOTH);
			glLineWidth(0.6*0.2);

			// zoom
			glColor3d(0,0,0);// black
			glBegin(GL_LINE_LOOP);
				glVertex2d(-0.1, -0.1);// left bottom
				glVertex2d(0, -0.15);// middle bottom
				glVertex2d(0.1, -0.1);// right bottom
				glVertex2d(0.15, 0);// right middle
				glVertex2d(0.1, 0.1);// right top
				glVertex2d(0, 0.15);// middle top
				glVertex2d(-0.1, 0.1);// left top
				glVertex2d(-0.15, 0);// left middle
			glEnd();

			// eyebball
			glColor3d(0.95,0.95,0.95);// white
			glBegin(GL_POLYGON);
				glVertex2d(-0.1, -0.1);// left bottom
				glVertex2d(0, -0.15);// middle bottom
				glVertex2d(0.1, -0.1);// right bottom
				glVertex2d(0.15, 0);// right middle
				glVertex2d(0.1, 0.1);// right top
				glVertex2d(0, 0.15);// middle top
				glVertex2d(-0.1, 0.1);// left top
				glVertex2d(-0.15, 0);// left middle
			glEnd();
		glPopMatrix();


		
			// camera body
			glColor3d(0.6,0.6,0.6);// grey
			glBegin(GL_POLYGON);
				glVertex2d(-0.6, -0.4);// left bottom
				glVertex2d(0.6, -0.4);// right bottom
				glVertex2d(0.6, 0.4);// right top
				glVertex2d(0.1, 0.4);//  top
				glVertex2d(0.1, 0.5);//  top
				glVertex2d(-0.1, 0.5);//  top
				glVertex2d(-0.1, 0.4);//  top
				glVertex2d(-0.4, 0.4);// left top
				glVertex2d(-0.6, 0.2);// left top
			glEnd();
	}

};

