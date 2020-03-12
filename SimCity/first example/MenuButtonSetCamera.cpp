#include "MenuButtonSetCamera.h"
#include "SimCity.h"


//MenuButtonSetCamera::MenuButtonSetCamera(void)
//{
//}


MenuButtonSetCamera::~MenuButtonSetCamera(void)
{
}



void MenuButtonSetCamera::action(Point& p)
{
	//this->simCity->field->addFieldObject((FieldObject*)(new House(p)));
	if (this->onDrag == false)
	{
		p.y += 10;
		this->simCity->setEye(p);
		this->onDrag = true;
	}
	//else // onDrag==true
	//{
	//	//this->simCity->setLookAt(p);
	//}
}

void MenuButtonSetCamera::actionUp(Point& p)
{
	//this->simCity->field->addFieldObject((FieldObject*)(new House(p)));
	//p.y += 10;
	this->onDrag = false;
	this->simCity->setLookAt(p);
	double r = sqrt( (p.x-this->simCity->eye->x)*(p.x-this->simCity->eye->x) + (p.y-this->simCity->eye->y)*(p.y-this->simCity->eye->y) + (p.z-this->simCity->eye->z)*(p.z-this->simCity->eye->z) );

	int angleSidewiseFlip = (this->simCity->eye->z < p.z) ? 1 : -1 ;//problam - down
	double angleSidewise = asin( (p.x-this->simCity->eye->x)/r );
	angleSidewise += (angleSidewiseFlip == 1) ? 0 : (1.57-angleSidewise)*2 ; // 1.57rad * 180/PI = 90 deg
	this->simCity->setAngle(angleSidewise);
}


void MenuButtonSetCamera::actionMove(Point& p)
{
	if (this->onDrag == true)
		this->simCity->setLookAt(p);
}


