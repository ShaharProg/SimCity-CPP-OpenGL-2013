#include "MenuButton.h"

#include "SimCity.h"

void MenuButton::draw2d()
{
	if (this != (MenuButton*)(this->simCity->selectedButton))	// not selected
	{
		// black rectangle
		glColor4d(0,0,0,0.6);
		glBegin(GL_POLYGON);
			glVertex2d(-0.9,0.1); // tl
			glVertex2d(0.9,0.1); // tr
			glVertex2d(0.9,1.9); // br
			glVertex2d(-0.9,1.9); // bl
		glEnd();
	}
	else										// selected
	{
		// yellow rectangle
		glColor4d(1,1,0,0.6);
		glBegin(GL_POLYGON);
			glVertex2d(-0.9,0.1); // tl
			glVertex2d(0.9,0.1); // tr
			glVertex2d(0.9,1.9); // br
			glVertex2d(-0.9,1.9); // bl
		glEnd();
	}
}

//MenuButton::MenuButton(void)
//{
//}
//
//void MenuButton::draw()
//{
//	//(*(this->drawFunc))();
//	this->drawFunc();
//}
//
//void MenuButton::action(double x, double y)
//{
//	//
//}

//MenuButton::~MenuButton(void)
//{
//}
