#pragma once
#include "Menu.h"
#include "Field.h"
//class Menu;//forward declaration
//class Field;//forward declaration

class SimCity
{
public:
	MenuButton* selectedButton;
	Menu* menu;
	Field* field;
	Point *eye, *sight, *lookAt;
	double angle;
	
	char state;//comb


	SimCity(void);
	~SimCity(void);

	void draw2d();

	void draw3d();

	void mouseDown(Point p);
	void mouseUp(Point p);

	void setEye(Point &p)
	{
		this->eye->x = p.x;
		this->eye->y = p.y;
		this->eye->z = p.z;
	}

	void setLookAt(Point &p)
	{
		this->lookAt->x = p.x;
		this->lookAt->y = p.y;
		this->lookAt->z = p.z;
	}

	void setAngle(double angle)
	{
		this->angle = angle;
	}


};

