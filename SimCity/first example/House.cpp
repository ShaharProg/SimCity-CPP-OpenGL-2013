#include "House.h"

#include "Field.h"


//House::House(void)
//{
//}


House::~House(void)
{
}


void House::draw2d()
{
	glPushMatrix();
		glTranslated(p.x,p.y,p.z);
		
		switch (type)
		{
		case 1:
			glScaled(0.2,0.2,0.2);
			DrawHouse1(floors,5,6,3);
			break;
		case 2:
			glTranslated(0,-1.5,0);
			glScaled(0.1,0.1,0.1);
			DrawHouse2(floors);
			break;
		default:
			DrawHouse1(5,5,6,3);
			break;
		}
		
	glPopMatrix();
}

	
void House::DrawHouse()
{
}

void House::DrawHouse2(int floors)
{
	int i;

	glPushMatrix();
	for(i=0;i<floors;i++)
	{
		glTranslated(0,10,0);
		Field::DrawWall();
		glPushMatrix();
			glTranslated(0,0,-20);
			Field::DrawWall();
		glPopMatrix();
		glPushMatrix();
			glTranslated(-10,0,-15);
			glRotated(90,0,1,0);
			glTranslated(0,0,5);
			Field::DrawWall();
			glTranslated(0,0,20);
			Field::DrawWall();
		glPopMatrix();
	}
	// roof
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,3);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);

	glTranslated(0,15,0);

	glBegin(GL_POLYGON);
		glTexCoord2d(0,0);    glVertex3d(-10,5,-5);
		glTexCoord2d(0.5,1); 		glVertex3d(0,20,-15);
		glTexCoord2d(1,0); 		glVertex3d(10,5,-5);
	glEnd();
	glBegin(GL_POLYGON);
		glTexCoord2d(0,0);    glVertex3d(-10,5,-25);
		glTexCoord2d(0.5,1); 		glVertex3d(0,20,-15);
		glTexCoord2d(1,0); 		glVertex3d(10,5,-25);
	glEnd();
	glBegin(GL_POLYGON);
		glTexCoord2d(0,0);    glVertex3d(-10,5,-5);
		glTexCoord2d(0.5,1); 		glVertex3d(0,20,-15);
		glTexCoord2d(1,0); 		glVertex3d(-10,5,-25);
	glEnd();
	glBegin(GL_POLYGON);
		glTexCoord2d(0,0);    glVertex3d(10,5,-5);
		glTexCoord2d(0.5,1); 		glVertex3d(0,20,-15);
		glTexCoord2d(1,0); 		glVertex3d(10,5,-25);
	glEnd();
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void House::DrawHouse1(int floors, int tx, int n,int th)
{
	int i;
	glPushMatrix();
	for(i=0;i<floors;i++)
	{
	glPushMatrix();
		glTranslated(0,i*5,0);
		glScaled(5,5,5);
		glRotated(45,0,1,0);
		Field::DrawTCilynder(n,4,th,1,1,1,0);
	glPopMatrix();
	}
	glPopMatrix();

	glPushMatrix();
		glTranslated(0,i*5,0);
		glScaled(5,5,5);
		glRotated(45,0,1,0);
		Field::DrawTCilynder(n,3,n,0,1,1,0);
	glPopMatrix();


}