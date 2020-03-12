#include "Plane.h"

#include "Field.h"


//Plane::Plane(void)
//{
//}


Plane::~Plane(void)
{
}


void Plane::draw2d()
{
	glPushMatrix();
		glTranslated(p.x,p.y,p.z);
		//glScaled(0.1,0.1,0.1);
		glRotated(plane_angle*180/PI,0,1,0);  // yaw
		glRotated(-plane_ang_speed*2000,1,0,0); // roll
		glRotated(pitch*180/PI,0,0,1);
		DrawPlane();
	glPopMatrix();
}

	
void Plane::DrawPlane()
{
	// front
	glColor3d(0,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex3d(2.3,0.3,0);
		glVertex3d(1.5,0.3,0.4);
		glVertex3d(1.5,0.5,0);
	glEnd();
	glColor3d(0,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex3d(2.3,0.3,0);
		glVertex3d(1.5,0.3,-0.4);
		glVertex3d(1.5,0.5,0);
	glEnd();

	glBegin(GL_POLYGON);
			glColor3d(1,1,1);
		glVertex3d(3.2,0,0);
			glColor3d(0.7,0.7,0.7);
		glVertex3d(1.5,0,0.5);
			glColor3d(0.6,0.6,0.6);
		glVertex3d(1.5,0.3,0.4);
		glVertex3d(2.3,0.3,0);
	glEnd();
	glBegin(GL_POLYGON);
			glColor3d(1,1,1);
		glVertex3d(3.2,0,0);
			glColor3d(0.7,0.7,0.7);
		glVertex3d(1.5,0,-0.5);
			glColor3d(0.6,0.6,0.6);
		glVertex3d(1.5,0.3,-0.4);
		glVertex3d(2.3,0.3,0);
	glEnd();
	// middle
	glBegin(GL_POLYGON);
			glColor3d(0.7,0.7,0.7);
		glVertex3d(1.5,0,0.5);
			glColor3d(0.8,0.8,0.8);
		glVertex3d(1.5,0.3,0.4);
			glColor3d(0.5,0.5,0.5);
		glVertex3d(-3.5,0,0);
	glEnd();

	glBegin(GL_POLYGON);
			glColor3d(0.8,0.8,0.8);
		glVertex3d(1.5,0.3,0.4);
			glColor3d(0.5,0.5,0.8);
		glVertex3d(1.5,0.5,0);
			glVertex3d(-3.5,0,0);
	glEnd();

	glBegin(GL_POLYGON);
			glColor3d(0.7,0.7,0.7);
		glVertex3d(1.5,0,-0.5);
			glColor3d(0.8,0.8,0.8);
		glVertex3d(1.5,0.3,-0.4);
			glColor3d(0.5,0.5,0.5);
		glVertex3d(-3.5,0,0);
	glEnd();

	glBegin(GL_POLYGON);
			glColor3d(0.8,0.8,0.8);
		glVertex3d(1.5,0.3,-0.4);
			glColor3d(0.5,0.5,0.8);
		glVertex3d(1.5,0.5,0);
			glVertex3d(-3.5,0,0);
	glEnd();
	// wings
	glBegin(GL_POLYGON);
			glColor3d(0.6,0.6,0.6);
		glVertex3d(1.5,0.2,0);
		glVertex3d(-0.5,0.2,2.5);
		glVertex3d(-1,0.2,2.5);
		glVertex3d(-0.5,0.1,0);
	glEnd();
	glBegin(GL_POLYGON);
			glColor3d(0.6,0.6,0.6);
		glVertex3d(1.5,0.2,0);
		glVertex3d(-0.5,0.2,-2.5);
		glVertex3d(-1,0.2,-2.5);
		glVertex3d(-0.5,0.1,0);
	glEnd();
	// back

	glBegin(GL_POLYGON);
			glColor3d(0.6,0.6,0.6);
		glVertex3d(-1,0,0);
			glColor3d(0.6,0.6,1);
		glVertex3d(-3.3,1,0);
		glVertex3d(-3.6,1,0);
			glColor3d(0.6,0.6,0.6);
		glVertex3d(-3.2,0,0);
	glEnd();
	// back wings
	glBegin(GL_POLYGON);
			glColor3d(0.6,0.6,0.6);
		glVertex3d(-1.5,0,0);
		glVertex3d(-2.5,0,1);
		glVertex3d(-2.7,0,1);
		glVertex3d(-2.7,0,-1);
		glVertex3d(-2.5,0,-1);
	glEnd();
}