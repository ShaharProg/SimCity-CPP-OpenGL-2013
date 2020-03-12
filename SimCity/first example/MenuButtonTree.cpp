#include "MenuButtonTree.h"

#include "SimCity.h"

//MenuButtonTree::MenuButtonTree(void)
//{
//}


MenuButtonTree::~MenuButtonTree(void)
{
}


void MenuButtonTree::action(Point& p)
{
	this->simCity->field->addFieldObject((FieldObject*)(new Tree(p)));
	//glPushMatrix();
	//	glTranslated(p->x,p->y,0);
	//	glScaled(0.1,0.1,1);
	//	DrawTree(0.6,0);
	//glPopMatrix();
}