#include "Vehicle.h"
#include "Field.h"


//Vehicle::Vehicle(void)
//{
//}


Vehicle::~Vehicle(void)
{
}


void Vehicle::draw2d()
{
	glPushMatrix();
		glTranslated(p.x,p.y,p.z);
		//glScaled(0.1,0.1,0.1);
		glRotated(vehicle_angle*180/PI,0,1,0);  // yaw
		glRotated(-vehicle_ang_speed*2000,1,0,0); // roll
		glRotated(pitch*180/PI,0,0,1);

		switch (type)
		{
		case 1:
			DrawVehicle();
			break;
		case 2:
			DrawVehicle2();
			break;
		default:
			DrawVehicle();
			break;
		}

	glPopMatrix();
}

void Vehicle::move()
{
	p.x		+=	vehicle_speed * dx;
	p.z		+=	vehicle_speed * dz;
	p.y		+=	vehicle_speed * dh;

	radiusFromU += vehicle_speed;

	while (legSize < radiusFromU)
	{
		radiusFromU -= legSize;

		int neighborNum = rand()%( v->neighbors.size() );
		u = v;
		v = v->neighbors[neighborNum];

		this->setMovement(u->p,v->p);
	}

}
	
void Vehicle::DrawVehicle()
{
	glTranslated(0,0.25,-0.9);
	glScaled(2,2,2);
	glRotated(90,0,1,0);

	

	glEnable(GL_NORMALIZE);

	
	// material definitions
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,Field::mamb1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Field::mdiff1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Field::mspec1);
	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,100);

	//glutSolidSphere(0.5,20,20);

	glColor3d(1,1,1);//roof
	glBegin(GL_POLYGON);
		glNormal3d(0,1,0);
		glVertex3d(-0.5,0.4,0.6);
		glNormal3d(0,1,0);
		glVertex3d(0.5,0.4,0.6);
		glNormal3d(0,1,0);
		glVertex3d(0.5,0.4,-0.6);
		glNormal3d(0,1,0);
		glVertex3d(-0.5,0.4,-0.6);
	glEnd();

	glColor4d(0.2,0.2,1,0.5);//front window
	glBegin(GL_POLYGON);

		glNormal3d(0,0.4+0.25,0.6+0.7);
		glVertex3d(-0.5,0.4,0.6);
		glNormal3d(0,0.4+0.25,0.6+0.7);
		glVertex3d(0.5,0.4,0.6);
		glNormal3d(0,0.4+0.25,0.6+0.7);
		glVertex3d(0.5,0.25,0.7);
		glNormal3d(0,0.4+0.25,0.6+0.7);
		glVertex3d(-0.5,0.25,0.7);
	glEnd();
	
	glColor4d(0.2,0.2,1,0.5);//rear window
	glBegin(GL_POLYGON);
		glVertex3d(-0.5,0.4,-0.6);
		glVertex3d(0.5,0.4,-0.6);
		glVertex3d(0.5,0.25,-0.7);
		glVertex3d(-0.5,0.25,-0.7);
	glEnd();
		
	glColor3d(1,1,1);//engine cover
	glBegin(GL_POLYGON);
		glVertex3d(0.5,0.25,0.7);
		glVertex3d(-0.5,0.25,0.7);
		glVertex3d(-0.5,0.2,1);
		glVertex3d(0.5,0.2,1);
	glEnd();
			
	glColor3d(1,1,1);//bagage cover
	glBegin(GL_POLYGON);
		glVertex3d(0.5,0.25,-0.7);
		glVertex3d(-0.5,0.25,-0.7);
		glVertex3d(-0.5,0.2,-1);
		glVertex3d(0.5,0.2,-1);
	glEnd();
			
	glColor4d(0.2,0.2,1,0.5);//right window
	glBegin(GL_POLYGON);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.4,-0.6);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.4,0.6);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.25,0.7);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.25,-0.7);
	glEnd();

			
	glColor4d(0.2,0.2,1,0.5);//left window
	glBegin(GL_POLYGON);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.4,-0.6);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.4,0.6);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.25,0.7);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.25,-0.7);
	glEnd();
				
	glColor3d(1,1,1);// right wing
	glBegin(GL_POLYGON);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.2,1);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.25,0.7);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.25,-0.7);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.2,-1);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.1,-1);

		//above back wheel
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.1,-0.8);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.15,-0.8);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.15,-0.7);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.1,-0.7);
		
		//above front wheel
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.1,0.7);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.15,0.7);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.15,0.8);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.1,0.8);
		
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.1,1);
	glEnd();


	glColor3d(1,1,1);// left wing
	glBegin(GL_POLYGON);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.2,1);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.25,0.7);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.25,-0.7);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.2,-1);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.1,-1);

		//above back wheel
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.1,-0.8);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.15,-0.8);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.15,-0.7);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.1,-0.7);
		
		//above front wheel
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.1,0.7);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.15,0.7);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.15,0.8);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.1,0.8);
		
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.1,1);
	glEnd();


	
	glColor3d(1,1,1);// front pagosh
	glBegin(GL_POLYGON);
		glNormal3d(0,0,1);
		glVertex3d(-0.5,0.2,1);
		glNormal3d(0,0,1);
		glVertex3d(-0.5,0.1,1);
		glNormal3d(0,0,1);
		glVertex3d(0.5,0.1,1);
		glNormal3d(0,0,1);
		glVertex3d(0.5,0.2,1);
	glEnd();

			
	glColor3d(1,1,0);// front right flashlight
	glBegin(GL_POLYGON);
		glNormal3d(0,0,1);
		glVertex3d(-0.5,0.2,1.01);
		glNormal3d(0,0,1);
		glVertex3d(-0.5,0.1,1.01);
		glNormal3d(0,0,1);
		glVertex3d(-0.25,0.1,1.01);
		glNormal3d(0,0,1);
		glVertex3d(-0.25,0.2,1.01);
	glEnd();
	
	
	glColor3d(1,1,0);// front left flashlight
	glBegin(GL_POLYGON);
		glNormal3d(0,0,1);
		glVertex3d(0.5,0.2,1.01);
		glNormal3d(0,0,1);
		glVertex3d(0.5,0.1,1.01);
		glNormal3d(0,0,1);
		glVertex3d(0.25,0.1,1.01);
		glNormal3d(0,0,1);
		glVertex3d(0.25,0.2,1.01);
	glEnd();

	glColor3d(1,1,1);// back pagosh
	glBegin(GL_POLYGON);
		glNormal3d(0,0,-1);
		glVertex3d(-0.5,0.2,-1);
		glNormal3d(0,0,-1);
		glVertex3d(-0.5,0.1,-1);
		glNormal3d(0,0,-1);
		glVertex3d(0.5,0.1,-1);
		glNormal3d(0,0,-1);
		glVertex3d(0.5,0.2,-1);
	glEnd();

				
	glColor3d(1,0,0);// back right flashlight
	glBegin(GL_POLYGON);
		glNormal3d(0,0,-1);
		glVertex3d(-0.5,0.2,-1.01);
		glNormal3d(0,0,-1);
		glVertex3d(-0.5,0.1,-1.01);
		glNormal3d(0,0,-1);
		glVertex3d(-0.25,0.1,-1.01);
		glNormal3d(0,0,-1);
		glVertex3d(-0.25,0.2,-1.01);
	glEnd();
	
	
	glColor3d(1,0,0);// back left flashlight
	glBegin(GL_POLYGON);
		glNormal3d(0,0,-1.01);
		glVertex3d(0.5,0.2,-1.01);
		glNormal3d(0,0,-1);
		glVertex3d(0.5,0.1,-1.01);
		glNormal3d(0,0,-1);
		glVertex3d(0.25,0.1,-1.01);
		glNormal3d(0,0,-1);
		glVertex3d(0.25,0.2,-1.01);
	glEnd();


	
	
	glColor4d(0,0,0,0);// bottom
	glBegin(GL_POLYGON);
		glNormal3d(0,-1,0);
		glVertex3d(-0.5,0.1,-1);
		glNormal3d(0,-1,0);
		glVertex3d(0.5,0.1,-1);
		glNormal3d(0,-1,0);
		glVertex3d(0.5,0.1,1);
		glNormal3d(0,-1,0);
		glVertex3d(-0.5,0.1,1);
	glEnd();





 // LINES -------------------------------------------------
	glLineWidth(0.5);
	glColor3d(0,0,0);//roof
	glBegin(GL_LINE_LOOP);
		glNormal3d(0,1,0);
		glVertex3d(-0.5,0.4,0.6);
		glNormal3d(0,1,0);
		glVertex3d(0.5,0.4,0.6);
		glNormal3d(0,1,0);
		glVertex3d(0.5,0.4,-0.6);
		glNormal3d(0,1,0);
		glVertex3d(-0.5,0.4,-0.6);
	glEnd();

	glColor3d(0,0,0);//front window
	glBegin(GL_LINE_LOOP);
		glColor3d(0,0,0);

		glNormal3d(0,0.4+0.25,0.6+0.7);
		glVertex3d(-0.5,0.4,0.6);
		glNormal3d(0,0.4+0.25,0.6+0.7);
		glVertex3d(0.5,0.4,0.6);
		glNormal3d(0,0.4+0.25,0.6+0.7);
		glVertex3d(0.5,0.25,0.7);
		glNormal3d(0,0.4+0.25,0.6+0.7);
		glVertex3d(-0.5,0.25,0.7);
	glEnd();
	
	glColor3d(0,0,0);//rear window
	glBegin(GL_LINE_LOOP);
		glVertex3d(-0.5,0.4,-0.6);
		glVertex3d(0.5,0.4,-0.6);
		glVertex3d(0.5,0.25,-0.7);
		glVertex3d(-0.5,0.25,-0.7);
	glEnd();
		
	glColor3d(0,0,0);//engine cover
	glBegin(GL_LINE_LOOP);
		glVertex3d(0.5,0.25,0.7);
		glVertex3d(-0.5,0.25,0.7);
		glVertex3d(-0.5,0.2,1);
		glVertex3d(0.5,0.2,1);
	glEnd();
			
	glColor3d(0,0,0);//bagage cover
	glBegin(GL_LINE_LOOP);
		glVertex3d(0.5,0.25,-0.7);
		glVertex3d(-0.5,0.25,-0.7);
		glVertex3d(-0.5,0.2,-1);
		glVertex3d(0.5,0.2,-1);
	glEnd();
			
	glColor3d(0,0,0);//right window
	glBegin(GL_LINE_LOOP);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.4,-0.6);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.4,0.6);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.25,0.7);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.25,-0.7);
	glEnd();

			
	glColor3d(0,0,0);//left window
	glBegin(GL_LINE_LOOP);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.4,-0.6);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.4,0.6);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.25,0.7);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.25,-0.7);
	glEnd();
				
	glColor3d(0,0,0);// right wing
	glBegin(GL_LINE_LOOP);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.2,1);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.25,0.7);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.25,-0.7);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.2,-1);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.1,-1);

		//above back wheel
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.1,-0.8);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.15,-0.8);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.15,-0.7);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.1,-0.7);
		
		//above front wheel
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.1,0.7);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.15,0.7);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.15,0.8);
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.1,0.8);
		
		glNormal3d(1,0,0);
		glVertex3d(0.5,0.1,1);
	glEnd();


	glColor3d(0,0,0);// left wing
	glBegin(GL_LINE_LOOP);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.2,1);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.25,0.7);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.25,-0.7);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.2,-1);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.1,-1);

		//above back wheel
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.1,-0.8);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.15,-0.8);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.15,-0.7);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.1,-0.7);
		
		//above front wheel
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.1,0.7);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.15,0.7);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.15,0.8);
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.1,0.8);
		
		glNormal3d(-1,0,0);
		glVertex3d(-0.5,0.1,1);
	glEnd();


	
	glColor3d(0,0,0);// front pagosh
	glBegin(GL_LINE_LOOP);
		glNormal3d(0,0,1);
		glVertex3d(-0.5,0.2,1);
		glNormal3d(0,0,1);
		glVertex3d(-0.5,0.1,1);
		glNormal3d(0,0,1);
		glVertex3d(0.5,0.1,1);
		glNormal3d(0,0,1);
		glVertex3d(0.5,0.2,1);
	glEnd();
	
	glColor3d(0,0,0);// back pagosh
	glBegin(GL_LINE_LOOP);
		glNormal3d(0,0,-1);
		glVertex3d(-0.5,0.2,-1);
		glNormal3d(0,0,-1);
		glVertex3d(-0.5,0.1,-1);
		glNormal3d(0,0,-1);
		glVertex3d(0.5,0.1,-1);
		glNormal3d(0,0,-1);
		glVertex3d(0.5,0.2,-1);
	glEnd();






}


void Vehicle::DrawVehicle2()
{
	glTranslated(0,1,-0.9);
	glRotated(90,0,1,0);

	// material definitions
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,Field::mamb1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,Field::mdiff1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,Field::mspec1);
	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,100);

	
	glPushMatrix();
		glScaled(1,0.6,1);

		glPushMatrix();//body
			glScaled(1,1,3);
			glColor3d(1,1,1);
			glutSolidSphere(1,20,20);
		glPopMatrix();

	
		glPushMatrix();//windows
			glTranslated(0,0.01,0);
			glScaled(1,1,3);
			glColor3d(0.5,0.5,1);
			glutSolidSphere(1,20,20);
		glPopMatrix();

	
		glPushMatrix();//roof
			glTranslated(0,0.2,0);
			glScaled(0.9,0.9,2.5);
			glColor3d(1,1,1);
			glutSolidSphere(1,20,20);
		glPopMatrix();

	glPopMatrix();

	glPushMatrix();//front right flashlight
		glTranslated(0.4,0,2.9);
		glColor3d(1,1,0);
		glutSolidSphere(0.2,20,20);
	glPopMatrix();

		glPushMatrix();//front left flashlight
		glTranslated(-0.4,0,2.9);
		glColor3d(1,1,0);
		glutSolidSphere(0.2,20,20);
	glPopMatrix();

		
	glPushMatrix();//back right flashlight
		glTranslated(0.4,0,-2.9);
		glColor3d(1,0,0);
		glutSolidSphere(0.2,20,20);
	glPopMatrix();

		glPushMatrix();//back left flashlight
		glTranslated(-0.4,0,-2.9);
		glColor3d(1,0,0);
		glutSolidSphere(0.2,20,20);
	glPopMatrix();

		glPushMatrix();//front right wheel
		glTranslated(0.4,-0.5,2);
		glColor3d(0,0,0);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

		glPushMatrix();//front left wheel
		glTranslated(-0.4,-0.5,2);
		glColor3d(0,0,0);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

		
	glPushMatrix();//back right wheel
		glTranslated(0.4,-0.5,-2);
		glColor3d(0,0,0);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();

		glPushMatrix();//back left wheel
		glTranslated(-0.4,-0.5,-2);
		glColor3d(0,0,0);
		glutSolidSphere(0.3,20,20);
	glPopMatrix();
}

