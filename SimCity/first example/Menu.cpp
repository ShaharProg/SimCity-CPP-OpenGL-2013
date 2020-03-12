#include "Menu.h"

#include "SimCity.h"

//Menu::Menu(void)
//{
//}

void Menu::addButton(MenuButton* menuButton)
{
	menuButton->setSimCity(this->simCity);
	menuButtons.push_back(menuButton);
}

void Menu::draw2d()
{

	// menu buttons
	int i=0;
	vector<MenuButton*>::iterator it;
	for (it = menuButtons.begin(); it!=menuButtons.end(); ++it,++i)
	{
		glPushMatrix();
			glTranslated(0,i*2,0);
			(*it)->draw2d();
		glPopMatrix();
	}

		// menu background
	glColor3d(0.31,0.59,0.75);
	glBegin(GL_POLYGON);
		glVertex2d(-1,0);//tl
		glVertex2d(1,0);//tr
		glVertex2d(1,20);//br
		glVertex2d(-1,20);//bl
	glEnd();

	/*
	
	// menu buttons
	int i=0;
	for (; i<5; i++)
	{
		glPushMatrix();
			glTranslated(0,i*2,0);
			glColor4d(1,1,0,0.6);
			glBegin(GL_POLYGON);
				glVertex2d(-0.9,0.1); // tl
				glVertex2d(0.9,0.1); // tr
				glVertex2d(0.9,1.9); // br
				glVertex2d(-0.9,1.9); // bl
			glEnd();
		glPopMatrix();
	}
	*/



}

Menu::~Menu(void)
{
}

void Menu::mouseDown(Point p)
{
	int buttonNum = p.z/2;
	if (buttonNum < menuButtons.size() )
	{
		simCity->selectedButton = (simCity->selectedButton != menuButtons[buttonNum]) ? (menuButtons[buttonNum]) : (NULL) ;
	}
}
