#include "Tree.h"

#include "Field.h"


//Tree::Tree(void)
//{
//}


Tree::~Tree(void)
{
}


void Tree::draw2d()
{
	glPushMatrix();
		glTranslated(p.x,p.y,p.z);
		glScaled(0.3,0.3,0.3);
		
		switch (type)
		{
		case 1:
			DrawTree1();
			break;
		case 2:
			DrawTree2();
			break;
		default:
			DrawTree2();
			break;
		}
	glPopMatrix();
}

	
void Tree::DrawTree1()
{
	
	glPushMatrix();
		glScaled(0.5,4,0.5);
		glColor3d(0.7,0.7,0);
		Field::DrawCilynder(20);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0,3.9,0);
		glScaled(2,2,2);
		glColor3d(0,0.7,0);
		glutSolidSphere(1,20,20);
	glPopMatrix();

}

void Tree::DrawTree2()
{
	
	glPushMatrix();
		glScaled(0.5,4,0.5);
		glColor3d(0.7,0.7,0);
		Field::DrawCilynder(20);
	glPopMatrix();

	glPushMatrix();
		glTranslated(0,3.9,0);
		glScaled(2,2,2);
		glColor3d(0,0.5,0);
		glPushMatrix();
			glRotated(-90,1,0,0);
			glutSolidCone(1,3,10,10);
		glPopMatrix();
	glPopMatrix();
}