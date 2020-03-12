#pragma once

#include "MenuButton.h"
#include "Road.h"

class SimCity;//forward declaration

class MenuButtonRoad :
	public MenuButton
{
public:
	Road* road;
	Vertex* lastVertex;//, *existingVertex;

	MenuButtonRoad(char* name) : MenuButton(name), road(NULL) {}
	~MenuButtonRoad(void);

	virtual void action(Point& p);
	virtual void actionRight(Point& p);

	virtual void draw2d()
	{
		glPushMatrix();
			glTranslated(0,1,0);
			DrawRoad();
		glPopMatrix();
		MenuButton::draw2d();
	}

	
	void DrawRoad()
	{
		glPushMatrix();


			glEnable(GL_LINE_SMOOTH);
			glLineWidth(0.6*0.2);
			// sidelines
			glColor3d(1,0.9,0);// yellow
			glBegin(GL_LINES);
				glVertex2d(-0.4, -0.6);// left bottom
				glVertex2d(-0.4, 0.6);// left top
				glVertex2d(0.4, -0.6);// right bottom
				glVertex2d(0.4, 0.6);// right top
			glEnd();


			
			// striplines
			glColor3d(0.95,0.95,0.95);// white
			glBegin(GL_LINES);
				glVertex2d(0,-0.4);
				glVertex2d(0, -0.1 );

				glVertex2d(0,0.1);
				glVertex2d(0, 0.4 );
			glEnd();
		glPopMatrix();

		
			// asphalt
			glColor3d(0.6,0.6,0.6);// grey
			glBegin(GL_POLYGON);
				glVertex2d(-0.6, -0.6);// left bottom
				glVertex2d(0.6, -0.6);// right bottom
				glVertex2d(0.6, 0.6);// right top
				glVertex2d(-0.6, 0.6);// left top
			glEnd();
	}

};

