#include "MenuButtonHouse.h"
#include "SimCity.h"


//MenuButtonHouse::MenuButtonHouse(void)
//{
//}


MenuButtonHouse::~MenuButtonHouse(void)
{
}



void MenuButtonHouse::action(Point& p)
{
	this->simCity->field->addFieldObject((FieldObject*)(new House(p)));
}