#pragma once
#include "MenuButton.h"
//#include "City.h"


class SimCity;//forward declaration


class MenuButtonCity :
	public MenuButton
{
	static const int B_SIZE = 20;

	vector<Point> prevCityCorners;

public:
	MenuButtonCity(char* name) : MenuButton(name){}


	~MenuButtonCity(void);
	virtual void action(Point& p);

	virtual void draw2d()
	{
		glPushMatrix();
			glTranslated(0,1,0);
			DrawCity();
		glPopMatrix();

		MenuButton::draw2d();
	}


	void DrawCity()
	{

		glPushMatrix();
			
			// main streat
			glPushMatrix();
				glScaled(0.35,1.45,1.45);
				DrawRoad();
			glPopMatrix();

			// right top house
			glPushMatrix();
				glTranslated(0.5,0.5,0);
				glRotated(180,0,0,1);
				glScaled(0.4,0.4,1);
				DrawHouse();
			glPopMatrix();
			
			// left top house
			glPushMatrix();
				glTranslated(-0.5,0.3,0);
				glRotated(180,0,0,1);
				glScaled(0.4,0.4,1);
				DrawHouse();
			glPopMatrix();
			
			// right bottom house
			glPushMatrix();
				glTranslated(0.5,-0.6,0);
				glRotated(180,0,0,1);
				glScaled(0.4,0.4,1);
				DrawHouse();
			glPopMatrix();
			
			// left bottom house
			glPushMatrix();
				glTranslated(-0.5,-0.35,0);
				glRotated(180,0,0,1);
				glScaled(0.4,0.4,1);
				DrawHouse();
			glPopMatrix();

		glPopMatrix();
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




