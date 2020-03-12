#include "SimCity.h"

SimCity::SimCity(void) //: menu(this),field(this)
{
	menu	= new Menu(this);
	field	= new Field(this);
	state = '1';//edit
	eye		= new Point(1,10,20);//double eyex=1,eyey=10,eyez=20;
	sight	= new Point(0,-0.2,-1);//double sightx = 0,sighty= -0.2,sightz = -1;
	lookAt	= new Point(1,-0.2,60);
	angle = 0;
}


SimCity::~SimCity(void)
{
}


void SimCity::draw2d()
{
	this->field->draw2d();
	this->menu->draw2d();
}

void SimCity::mouseDown(Point p)
{
	//if (p.x < -0.8)		// menu
	//{
	//	this->menu->mouseDown(p);
	//}
	//else				// field
	//{
	//	this->field->mouseDown(p);
	//}
}

void SimCity::mouseUp(Point p)
{
	//
}

