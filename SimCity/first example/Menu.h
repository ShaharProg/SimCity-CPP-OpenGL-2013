#pragma once
#include <vector>
using namespace std;
#include "glut.h"

#include "Point.h"
#include "MenuButton.h"

class SimCity;//forward declaration

class Menu
{
public:
	SimCity* simCity;
	vector<MenuButton*> menuButtons;


	Menu(SimCity* simCity) : simCity(simCity)
	{
	}
	~Menu(void);

	void addButton(MenuButton* menuButton);

	void draw2d();

	//void draw3d();

	void mouseDown(Point p);
};

