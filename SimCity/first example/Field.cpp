#include "Field.h"
#include "Road.h"
#include "SimCity.h"


	// light 1 definitions
	const float Field::ltamb1[4] = {0.4,0.3,0.3,0}; 
	const float Field::ltdiff1[4] = {0.7,0.5,0.5,0}; 
	const float Field::ltspec1[4] = {.6,.4,.4,0}; 
	const float Field::ltpos1[4] = {0.6,2,0.2,0}; // 0 means directional light
												// 1 means positional
	
	// light 2 definitions
	const float Field::ltamb2[4] = {0.4,0.4,0.3,0}; 
	const float Field::ltdiff2[4] = {0.6,0.6,0.5,0}; 
	const float Field::ltspec2[4] = {.6,.6,.6,0}; 
	const float Field::ltpos2[4] = {-0.6,0.2,0.4,0}; // 0 means directional light
												// 1 means positional

	// silver material
	const float Field::mamb1[4] = {0.2,0.2,0.2,0}; 
	const float Field::mdiff1[4] = {0.6,0.6,0.6,0}; 
	const float Field::mspec1[4] = {0.5,0.5,0.5,0};

//Field::Field(void)
//{
//}


Field::~Field(void)
{
}

void Field::mouseDown(Point p)
{
	if (simCity->selectedButton != NULL)
	{
		p.y = grid[(int)(-p.z)+GSIZE/2-1][(int)p.x+GSIZE/2-1];
		
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << "(x,y,z)=" << p.x << ",\t" << p.y << ",\t" << p.z << ")" << endl;
		
		simCity->selectedButton->action(p);
	}
}

void Field::mouseDownRight(Point p)
{
	if (simCity->selectedButton != NULL)
	{
		p.y = grid[(int)(-p.z)+GSIZE/2-1][(int)p.x+GSIZE/2-1];
		
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << "right click (x,y,z)=" << p.x << ",\t" << p.y << ",\t" << p.z << ")" << endl;
		
		simCity->selectedButton->actionRight(p);
	}
}

void Field::mouseUp(Point p)
{
	if (simCity->selectedButton != NULL)
	{
		p.y = grid[(int)(-p.z)+GSIZE/2-1][(int)p.x+GSIZE/2-1];
		
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << "(x,y,z)=" << p.x << ",\t" << p.y << ",\t" << p.z << ")" << endl;
		
		simCity->selectedButton->actionUp(p);
	}
}


//void drawCar()//DEBUG
//{
//	glTranslated(0,10,0);
//	glScaled(10,10,10);
//
//	
//	glEnable(GL_LIGHTING);//move outside of the cars loop
//	glEnable(GL_LIGHT0);
//
//	glLightfv(GL_LIGHT0,GL_AMBIENT,ltamb1);
//	glLightfv(GL_LIGHT0,GL_DIFFUSE,ltdiff1);
//	glLightfv(GL_LIGHT0,GL_SPECULAR,ltspec1);
//	glLightfv(GL_LIGHT0,GL_POSITION,ltpos1);
//	glLightf(GL_LIGHT0,GL_SHININESS,100);
//
//	
//	// material definitions
//	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mamb1);
//	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mdiff1);
//	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mspec1);
//	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,40);
//
//	glColor3d(0,0,0);//roof
//	glBegin(GL_POLYGON);
//		glNormal3d(0,1,0);
//		glVertex3d(-0.5,0.4,0.6);
//		glNormal3d(0,1,0);
//		glVertex3d(0.5,0.4,0.6);
//		glNormal3d(0,1,0);
//		glVertex3d(0.5,0.4,-0.6);
//		glNormal3d(0,1,0);
//		glVertex3d(-0.5,0.4,-0.6);
//	glEnd();
//
//	glColor3d(0.5,0.5,0.5);//front window
//	glBegin(GL_POLYGON);
//		glVertex3d(-0.5,0.4,0.6);
//		glVertex3d(0.5,0.4,0.6);
//		glVertex3d(0.5,0.25,0.7);
//		glVertex3d(-0.5,0.25,0.7);
//	glEnd();
//	
//	glColor3d(0.5,0.5,0.5);//rear window
//	glBegin(GL_POLYGON);
//		glVertex3d(-0.5,0.4,-0.6);
//		glVertex3d(0.5,0.4,-0.6);
//		glVertex3d(0.5,0.25,-0.7);
//		glVertex3d(-0.5,0.25,-0.7);
//	glEnd();
//		
//	glColor3d(0,0,0);//engine cover
//	glBegin(GL_POLYGON);
//		glVertex3d(0.5,0.25,0.7);
//		glVertex3d(-0.5,0.25,0.7);
//		glVertex3d(-0.5,0.2,1);
//		glVertex3d(0.5,0.2,1);
//	glEnd();
//			
//	glColor3d(0,0,0);//bagage cover
//	glBegin(GL_POLYGON);
//		glVertex3d(0.5,0.25,-0.7);
//		glVertex3d(-0.5,0.25,-0.7);
//		glVertex3d(-0.5,0.2,-1);
//		glVertex3d(0.5,0.2,-1);
//	glEnd();
//			
//	glColor3d(0,0,1);//right window
//	glBegin(GL_POLYGON);
//		glVertex3d(0.5,0.4,-0.6);
//		glVertex3d(0.5,0.4,0.6);
//		glVertex3d(0.5,0.25,0.7);
//		glVertex3d(0.5,0.25,-0.7);
//	glEnd();
//
//			
//	glColor3d(0,0,1);//left window
//	glBegin(GL_POLYGON);
//		glVertex3d(-0.5,0.4,-0.6);
//		glVertex3d(-0.5,0.4,0.6);
//		glVertex3d(-0.5,0.25,0.7);
//		glVertex3d(-0.5,0.25,-0.7);
//	glEnd();
//				
//	glColor3d(0,1,0);// right wing
//	glBegin(GL_POLYGON);
//		glVertex3d(0.5,0.2,1);
//		glVertex3d(0.5,0.25,0.7);
//		glVertex3d(0.5,0.25,-0.7);
//		glVertex3d(0.5,0.2,-1);
//		glVertex3d(0.5,0.1,-1);
//
//		//above back wheel
//		glVertex3d(0.5,0.1,-0.8);
//		glVertex3d(0.5,0.15,-0.8);
//		glVertex3d(0.5,0.15,-0.7);
//		glVertex3d(0.5,0.1,-0.7);
//		
//		//above front wheel
//		glVertex3d(0.5,0.1,0.7);
//		glVertex3d(0.5,0.15,0.7);
//		glVertex3d(0.5,0.15,0.8);
//		glVertex3d(0.5,0.1,0.8);
//
//		glVertex3d(0.5,0.1,1);
//	glEnd();
//
//
//	glColor3d(0,1,0);// left wing
//	glBegin(GL_POLYGON);
//		glVertex3d(-0.5,0.2,1);
//		glVertex3d(-0.5,0.25,0.7);
//		glVertex3d(-0.5,0.25,-0.7);
//		glVertex3d(-0.5,0.2,-1);
//		glVertex3d(-0.5,0.1,-1);
//
//		//above back wheel
//		glVertex3d(-0.5,0.1,-0.8);
//		glVertex3d(-0.5,0.15,-0.8);
//		glVertex3d(-0.5,0.15,-0.7);
//		glVertex3d(-0.5,0.1,-0.7);
//		
//		//above front wheel
//		glVertex3d(-0.5,0.1,0.7);
//		glVertex3d(-0.5,0.15,0.7);
//		glVertex3d(-0.5,0.15,0.8);
//		glVertex3d(-0.5,0.1,0.8);
//
//		glVertex3d(-0.5,0.1,1);
//	glEnd();
//
//
//	
//	glColor3d(0.6,1,0);// front pagosh
//	glBegin(GL_POLYGON);
//		glVertex3d(-0.5,0.2,1);
//		glVertex3d(-0.5,0.1,1);
//		glVertex3d(0.5,0.1,1);
//		glVertex3d(0.5,0.2,1);
//	glEnd();
//	
//	glColor3d(1,0.2,0.1);// back pagosh
//	glBegin(GL_POLYGON);
//		glVertex3d(-0.5,0.2,-1);
//		glVertex3d(-0.5,0.1,-1);
//		glVertex3d(0.5,0.1,-1);
//		glVertex3d(0.5,0.2,-1);
//	glEnd();
//
//
//	glDisable(GL_LIGHT0);
//	glDisable(GL_LIGHTING);//move outside of the cars loop
//
//}



void Field::draw2d()
{

	
	// sky
	glPushMatrix();
		glTranslated(0,120,0);
		glScaled(200,200,200);
		DrawTSphere(40,30,5,1,1);
	glPopMatrix();


	plane.draw2d();
	//vehicle.draw2d();

	glEnable(GL_LIGHTING);//move outside of the cars loop
	//glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_COLOR_MATERIAL);

	
	glLightfv(GL_LIGHT0,GL_AMBIENT,Field::ltamb1);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,Field::ltdiff1);
	glLightfv(GL_LIGHT0,GL_SPECULAR,Field::ltspec1);
	glLightfv(GL_LIGHT0,GL_POSITION,Field::ltpos1);
	glLightf(GL_LIGHT0,GL_SHININESS,100);

	
	glLightfv(GL_LIGHT1,GL_AMBIENT,Field::ltamb2);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,Field::ltdiff2);
	glLightfv(GL_LIGHT1,GL_SPECULAR,Field::ltspec2);
	glLightfv(GL_LIGHT1,GL_POSITION,Field::ltpos2);
	glLightf(GL_LIGHT1,GL_SHININESS,100);

	
	//floor
	glPushMatrix();
		DrawFloor();
	glPopMatrix();
		
	glPushMatrix();
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		for (int i=0; i<vehicles.size(); ++i)
		{
			vehicles[i]->draw2d();
		}
		glDisable(GL_BLEND);
	glPopMatrix();
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHTING);//move outside of the cars loop

	//// plane
	//glPushMatrix();
	//	glTranslated(planex,planey, planez);
	//	glRotated(plane_angle*180/PI,0,1,0);  // yaw
	//	glRotated(-plane_ang_speed*2000,1,0,0); // roll
	//	glRotated(pitch*180/PI,0,0,1);
	//	DrawPlane();
	//glPopMatrix();


	

	// field objects
	vector<FieldObject*>::iterator it;
	for (it = fieldObjects.begin(); it!=fieldObjects.end(); ++it)
	{
		(*it)->draw2d();
	}

	
	// mouse pointer:
	if (this->simCity->state == '1') //edit
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		
		// mouse cursor
		glPushMatrix();
			glTranslated(this->mouse_x, this->mouse_y, this->mouse_z);
			glColor4d(1,0.3,0,0.3);// half transparent red
			glutSolidSphere(8,10,10);
			//if (simCity->selectedButton != NULL) simCity->selectedButton->draw2d();
		glPopMatrix();
		
		// camera position (eye)
		glPushMatrix();
			glTranslated(this->simCity->eye->x, this->simCity->eye->y, this->simCity->eye->z);
			glColor4d(1,0,1,		0.6);// half transparent purple
			glutSolidSphere(10,10,10);
		glPopMatrix();

		// sight vector
		glPushMatrix();
			glBegin(GL_POLYGON);
				glColor4d(1,0,1,		0.9);
				//glLineWidth(4);//??check!
				glVertex3d(this->simCity->eye->x-2, /*this->simCity->eye->y*/7, this->simCity->eye->z);
				glVertex3d(this->simCity->lookAt->x-2, /*this->simCity->sight->y*/7, this->simCity->lookAt->z);
				glVertex3d(this->simCity->lookAt->x+2, /*this->simCity->sight->y*/7, this->simCity->lookAt->z);
				glVertex3d(this->simCity->eye->x+2, /*this->simCity->eye->y*/7, this->simCity->eye->z);
			glEnd();
		glPopMatrix();
		glDisable(GL_BLEND);
	}


		glPushMatrix();
		glEnable(GL_BLEND);
        glEnable(GL_LINE_SMOOTH);
        glLineWidth(2.0);
		glColor4d(0.1,0.1,0.3,		0.6);// half transparent 
        output(-20, 20, 50,0.05,0.05,0.05,"The SimCity!");
		output(-22, 15, 50,0.02,0.02,0.02,"by Shahar Zigman & Elad Dotan.");
		glDisable(GL_BLEND);
	glPopMatrix();



}
void Field::output(GLfloat x, GLfloat y,GLfloat z,GLfloat xSzize, GLfloat ySize,GLfloat zSize, char *text)
{
	char *p;

	glPushMatrix();
	glTranslatef(x, y, z);
	glScaled(xSzize,ySize,zSize);
	for (p = text; *p; p++)
		glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
	glPopMatrix();
}

void Field::addFieldObject(FieldObject* fieldObject)
{
	fieldObjects.push_back(fieldObject);
}


// imported ---- used to be in "_first.cpp"


void Field::DrawFloor()
{
	int i,j;
	double a[3],b[3],c[3];
	double ba[3],bc[3],n[3];
	double len;


	for(i=2;i<GSIZE;i++)
		for(j=2;j<GSIZE;j++)
		{
			b[0] = j; b[1] = grid[i][j]; b[2] = i;
			a[0] = j; a[1] = grid[i-1][j]; a[2] = i-1;
			c[0] = j-1; c[1] = grid[i][j-1]; c[2] = i;

			ba[0] = 0; ba[1] = a[1] - b[1]; ba[2] = -1;
			bc[0] = -1; bc[1] = c[1] - b[1]; bc[2] = 0;

			n[0] = bc[1]; 			n[1] = 1; 			n[2] = ba[1];
			len = sqrt(n[0]*n[0] + n[2]*n[2]+1);
			n[0]/=len;  n[1] /=len;  n[2]/=len;

			glBegin(GL_POLYGON);
					SetColor(grid[i][j]);
				glNormal3d(n[0],n[1],n[2]);
				glVertex3d(j-GSIZE/2,grid[i][j],-i+GSIZE/2);
					SetColor(grid[i][j-1]);

			b[1] = grid[i][j-1];
			a[1] = grid[i-1][j-1];
			c[1] = grid[i][j-2];

			bc[1] = c[1] - b[1];			ba[1] = a[1] - b[1];
			n[0] = bc[1]; 			n[1] = 1; 			n[2] = ba[1];
			len = sqrt(n[0]*n[0] + n[2]*n[2]+1);
			n[0]/=len;  n[1] /=len;  n[2]/=len;

				glNormal3d(n[0],n[1],n[2]);
				glVertex3d(j-GSIZE/2-1,grid[i][j-1],-i+GSIZE/2);
					SetColor(grid[i-1][j-1]);

			b[1] = grid[i-1][j-1];
			a[1] = grid[i-2][j-1];
			c[1] = grid[i-1][j-2];

			bc[1] = c[1] - b[1];			ba[1] = a[1] - b[1];
			n[0] = bc[1]; 			n[1] = 1; 			n[2] = ba[1];
			len = sqrt(n[0]*n[0] + n[2]*n[2]+1);
			n[0]/=len;  n[1] /=len;  n[2]/=len;

				glNormal3d(n[0],n[1],n[2]);
				glVertex3d(j-GSIZE/2-1,grid[i-1][j-1],-i+GSIZE/2+1);
					SetColor(grid[i-1][j]);
			b[1] = grid[i-1][j];
			a[1] = grid[i-2][j];
			c[1] = grid[i-1][j-1];

			bc[1] = c[1] - b[1];			ba[1] = a[1] - b[1];
			n[0] = bc[1]; 			n[1] = 1; 			n[2] = ba[1];
			len = sqrt(n[0]*n[0] + n[2]*n[2]+1);
			n[0]/=len;  n[1] /=len;  n[2]/=len;

				glNormal3d(n[0],n[1],n[2]);
				glVertex3d(j-GSIZE/2,grid[i-1][j],-i+GSIZE/2+1);
			glEnd();
		}

// water
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4d(0,0,0.5,0.7);
	glBegin(GL_POLYGON);
			glVertex3d(-GSIZE/2,0,-GSIZE/2);
			glVertex3d(GSIZE/2,0,-GSIZE/2);
			glVertex3d(GSIZE/2,0,GSIZE/2);
			glVertex3d(-GSIZE/2,0,GSIZE/2);
	glEnd();
	glDisable(GL_BLEND);


/*	
	glColor3d(0,1,0);
	for(i=1;i<GSIZE;i++)
		for(j=1;j<GSIZE;j++)
		{
			glBegin(GL_LINE_LOOP);
				glVertex3d(j-GSIZE/2,1+grid[i][j],i-GSIZE/2);
				glVertex3d(j-1-GSIZE/2,1+grid[i][j-1],i-GSIZE/2);
				glVertex3d(j-1-GSIZE/2,1+grid[i-1][j-1],i-1-GSIZE/2);
				glVertex3d(j-GSIZE/2,1+grid[i-1][j],i-1-GSIZE/2);
			glEnd();
		}
		*/
}


void Field::SetColor(double h)
{
	if(h>-5)
	{
	h=fabs(h);
//	glColor3d((h+3)/10,(h+3)/10,(h+3)/6);
	if(h>0 && h<0.4) // sand
		glColor3d(0.8,0.8,0.5);
	else if(h<5)
		glColor3d(0.2+h/30,(5-h)/6,0);
	else glColor3d(h/11,h/11,h/10);
	}
	else glColor3d(0,0,0);
}


// low-pass filter
void Field::Smooth()
{
	double tmp[GSIZE][GSIZE] = {0};
	int i,j;
	for(i=1;i<GSIZE-1;i++)
		for(j=1;j<GSIZE-1;j++)
		{
			tmp[i][j] = (grid[i-1][j-1] + grid[i-1][j] +grid[i-1][j+1] +
				grid[i][j-1] + 4*grid[i][j] +grid[i][j+1]+
				grid[i+1][j-1] + grid[i+1][j] +grid[i+1][j+1])/12;
		}

	for(i=1;i<GSIZE-1;i++)
		for(j=1;j<GSIZE-1;j++)
			grid[i][j] = tmp[i][j];
}

void Field::UpdateTerrain1()
{
	double a,b,delta = 0.1;
	int x1,x2,y1,y2,x,y;

	x1 = rand()% GSIZE;
	y1 = rand()% GSIZE;
	x2 = rand()% GSIZE;
	y2 = rand()% GSIZE;

	if(rand()%2==0) delta = -delta;

	if(x1!=x2)
	{
		a = (y2-y1)/(double)(x2-x1) ;
		b = y1 - a*x1;
		for(y=0;y<GSIZE;y++)
			for(x=0;x<GSIZE;x++)
			{
				if(y>a*x+b) grid[y][x]+=delta;
				else grid[y][x] -= delta;
			}
	}
}

void Field::UpdateTerrain2()
{
	int x1,y1,points = 1500,direction;
	double delta = 0.1;
	x1 = rand()% GSIZE;
	y1 = rand()% GSIZE;
	if(rand()%2==0) delta = -delta;

	while(points>0)
	{
		grid[y1][x1] += delta;
		direction = rand()%4;
		switch(direction)
		{
		case 0: // up
			y1--;
			break;
		case 1: // right
			x1++;
			break;
		case 2: // down
			y1++;
			break;
		case 3: // left
			x1--;
			break;
		} 
		x1 = (x1+GSIZE) % GSIZE;
		y1 = (y1+GSIZE) % GSIZE;
		points--;
	}
}

void Field::UpdateTerrain3()
{
	int x,y,r;
	int i,j;
	double dist,alpha;
	double delta = 1;

	x = rand()% GSIZE;
	y = rand()% GSIZE;
	r = 1 +rand()%30 ;
	if(rand()%2==0) delta = -delta;

	for(i=y-r;i<=y+r;i++)
		for(j = x-r;j<=x+r;j++)
		{
			if(i>=0 && j>=0 && i<GSIZE && j<GSIZE)
			{
				dist = sqrt(((double)x-j)*(x-j) + (i-y)*(i-y));
				if(dist<r)
				{
					alpha = acos(dist/r);
					grid[i][j] += delta * 0.03* r*sin(alpha);
				}
			}
		}


}


//---------------------------------------------------------

void Field::DrawColorCube()
{
	// top
	glBegin(GL_POLYGON);
			glColor3d(1,0,0);//red
		glVertex3d(1,1,1);
			glColor3d(1,0,1);// magenta
		glVertex3d(-1,1,1);
			glColor3d(0,0,1);//blue
		glVertex3d(-1,1,-1);
			glColor3d(1,1,1);// white
		glVertex3d(1,1,-1);
	glEnd();
	// bottom
	glBegin(GL_POLYGON);
			glColor3d(1,1,0);// yellow
		glVertex3d(1,-1,1);
			glColor3d(0,0,0); // black
		glVertex3d(-1,-1,1);
			glColor3d(0,1,1); // cyan
		glVertex3d(-1,-1,-1);
			glColor3d(0,1,0); // green
		glVertex3d(1,-1,-1);
	glEnd();
	// front
	glBegin(GL_POLYGON);
			glColor3d(1,0,0);
		glVertex3d(1,1,1);
			glColor3d(1,1,1);
		glVertex3d(1,1,-1);
			glColor3d(0,1,0);
		glVertex3d(1,-1,-1);
			glColor3d(1,1,0);
		glVertex3d(1,-1,1);
	glEnd();

	glBegin(GL_POLYGON);
			glColor3d(1,0,1);// magenta
		glVertex3d(-1,1,1);
			glColor3d(0,0,1);//blue
		glVertex3d(-1,1,-1);
			glColor3d(0,1,1); // cyan
		glVertex3d(-1,-1,-1);
			glColor3d(0,0,0); // black
		glVertex3d(-1,-1,1);
	glEnd();
	// left
	glBegin(GL_POLYGON);
			glColor3d(1,0,0);//red
		glVertex3d(1,1,1);
			glColor3d(1,0,1);// magenta
		glVertex3d(-1,1,1);
			glColor3d(0,0,0); // black
		glVertex3d(-1,-1,1);
			glColor3d(1,1,0);// yellow
		glVertex3d(1,-1,1);
	glEnd();
	// right
	glBegin(GL_POLYGON);
			glColor3d(0,0,1);//blue
		glVertex3d(-1,1,-1);
			glColor3d(1,1,1);// white
		glVertex3d(1,1,-1);
			glColor3d(0,1,0); // green
		glVertex3d(1,-1,-1);
			glColor3d(0,1,1); // cyan
		glVertex3d(-1,-1,-1);
	glEnd();

}

void Field::DrawCilynder(int n)
{
	double teta, alpha;

	teta = 2*PI/n;
	for(alpha = 0; alpha<=2*PI;alpha+=teta)
	{
		glBegin(GL_POLYGON);
//				glColor3d(fabs(sin(2*alpha)), fabs(cos(2*alpha)),0);
			glNormal3d(sin(alpha),0,cos(alpha));
			glVertex3d(sin(alpha), 1, cos(alpha));
//				glColor3d(fabs(sin(alpha+teta)), fabs(cos(alpha+teta)),1);
			glNormal3d(sin(alpha+teta),0,cos(alpha+teta));
			glVertex3d(sin(alpha+teta), 1, cos(alpha+teta));
//				glColor3d(fabs(sin(alpha)), fabs(cos(alpha)),0.8);
			glNormal3d(sin(alpha+teta),0,cos(alpha+teta));
			glVertex3d(sin(alpha+teta), 0, cos(alpha+teta));
//				glColor3d(fabs(sin(alpha-teta)), fabs(cos(alpha-teta)),0.5);
			glNormal3d(sin(alpha),0,cos(alpha));
			glVertex3d(sin(alpha), 0, cos(alpha));
		glEnd();
	}
}

void Field::DrawCilynder1(int n,double topr, double bottomr)
{
	double teta, alpha;
	double newy;

	teta = 2*PI/n;
	for(alpha = 0; alpha<=2*PI;alpha+=teta)
	{
		newy = bottomr*(bottomr-topr);
		glBegin(GL_POLYGON);
//				glColor3d(fabs(sin(2*alpha)), fabs(cos(2*alpha)),0);
			glNormal3d(bottomr*sin(alpha),newy,bottomr*cos(alpha));
			glVertex3d(topr*sin(alpha), 1, topr*cos(alpha));
//				glColor3d(fabs(sin(alpha+teta)), fabs(cos(alpha+teta)),1);
			glNormal3d(bottomr*sin(alpha+teta),newy,bottomr*cos(alpha+teta));
			glVertex3d(topr*sin(alpha+teta), 1, topr*cos(alpha+teta));
//				glColor3d(fabs(sin(alpha)), fabs(cos(alpha)),0.8);
			glNormal3d(bottomr*sin(alpha+teta),newy,bottomr*cos(alpha+teta));
			glVertex3d(bottomr*sin(alpha+teta), 0, bottomr*cos(alpha+teta));
//				glColor3d(fabs(sin(alpha-teta)), fabs(cos(alpha-teta)),0.5);
			glNormal3d(bottomr*sin(alpha),newy,bottomr*cos(alpha));
			glVertex3d(bottomr*sin(alpha), 0, bottomr*cos(alpha));
		glEnd();
	}
}

void Field::DrawConus(int n)
{
	double teta, alpha;

	teta = 2*PI/n;
	for(alpha = 0; alpha<2*PI;alpha+=teta)
	{
		glBegin(GL_POLYGON);
//				glColor3d(fabs(sin(2*alpha)), fabs(cos(2*alpha)),0);
			glNormal3d(sin(alpha+teta/2),1,cos(alpha+teta/2));
			glVertex3d(0, 1, 0);
//				glColor3d(fabs(sin(alpha+teta)), fabs(cos(alpha+teta)),1);
//				glColor3d(fabs(sin(alpha)), fabs(cos(alpha)),0.8);

			glNormal3d(sin(alpha+teta),1,cos(alpha+teta));
			glVertex3d(sin(alpha+teta), 0, cos(alpha+teta));
//				glColor3d(fabs(sin(alpha-teta)), fabs(cos(alpha-teta)),0.5);
			glNormal3d(sin(alpha),1,cos(alpha));
			glVertex3d(sin(alpha), 0, cos(alpha));
		glEnd();
	}
}

void Field::DrawSphere(int n, int slices)
{
	double delta,alpha;
	delta = PI/slices;
	int i;

	for(alpha = -PI/2,i=0; alpha< PI/2; alpha+=delta,i++)
	{
		if(i%2==0)
		{
		glPushMatrix();
		glTranslated(0,sin(alpha),0);
		glScaled(1,sin(alpha+delta)-sin(alpha),1);
		DrawCilynder1(n,cos(alpha+delta),cos(alpha));
		glPopMatrix();
		}
	}

}

// th is how many textures we have on cilynder
void Field::DrawTCilynder(int n, int tx,int th,double topr, double bottomr, 
							double vt, double vb)
{
	double teta, alpha,dt,dr;
	int tcount;

	teta = 2*PI/n;

	dt = th/(double)n;
	//dr = fabs(bottomr - topr)/2;
	dr=0;

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,tx);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);

	if(topr<=bottomr)
	{

	for(alpha = 0, tcount=0; alpha<=2*PI;alpha+=teta,tcount++)
	{
		glBegin(GL_POLYGON);
//			glNormal3d(sin(alpha),0,cos(alpha));
			glTexCoord2d(dr+tcount*dt,vt);      glVertex3d(topr*sin(alpha), vt, topr*cos(alpha));
//			glNormal3d(sin(alpha+teta),0,cos(alpha+teta));
			glTexCoord2d((tcount+1)*dt-dr,vt);      glVertex3d(topr*sin(alpha+teta), vt,topr* cos(alpha+teta));
//			glNormal3d(sin(alpha+teta),0,cos(alpha+teta));
			glTexCoord2d((tcount+1)*dt,vb);      glVertex3d(bottomr*sin(alpha+teta), vb,bottomr* cos(alpha+teta));
//			glNormal3d(sin(alpha),0,cos(alpha));
			glTexCoord2d(tcount*dt,vb);      glVertex3d(bottomr*sin(alpha), vb, bottomr*cos(alpha));
		glEnd();
	}
	} // if
	else
	{
	for(alpha = 0, tcount=0; alpha<=2*PI;alpha+=teta,tcount++)
	{
		glBegin(GL_POLYGON);
//			glNormal3d(sin(alpha),0,cos(alpha));
			glTexCoord2d(tcount*dt,vt);      glVertex3d(topr*sin(alpha), 1, topr*cos(alpha));
//			glNormal3d(sin(alpha+teta),0,cos(alpha+teta));
			glTexCoord2d((tcount+1)*dt,vt);      glVertex3d(topr*sin(alpha+teta), 1,topr* cos(alpha+teta));
//			glNormal3d(sin(alpha+teta),0,cos(alpha+teta));
			glTexCoord2d((tcount+1)*dt-dr,vb);      glVertex3d(bottomr*sin(alpha+teta), 0,bottomr* cos(alpha+teta));
//			glNormal3d(sin(alpha),0,cos(alpha));
			glTexCoord2d(dr+tcount*dt,vb);      glVertex3d(bottomr*sin(alpha), 0, bottomr*cos(alpha));
		glEnd();
	}
	} // if

	glDisable(GL_TEXTURE_2D);
}

void Field::DrawTSphere(int n, int slices,int tx,int th,int tv)
{
	double delta,alpha;
	double vt,vb,dv;
	int i;
	dv = tv/(double) slices;
	delta = PI/slices;
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,tx);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);

	for(alpha = -PI/2,i=0; alpha< PI/2; alpha+=delta,i++)
	{
		vt = (i+1)*dv;
		vb = i*dv;
		glPushMatrix();
		glTranslated(0,sin(alpha),0);
		glScaled(1,sin(alpha+delta)-sin(alpha),1);
		DrawTCilynder(n,tx,th,cos(alpha+delta),cos(alpha),vt,vb);
		glPopMatrix();
		}
	glDisable(GL_TEXTURE_2D);
}

void Field::DrawWall()
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D,1);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	// bottum level
	glBegin(GL_POLYGON);
		glTexCoord2d(0,0);    glVertex3d(-10,5,-5);
		glTexCoord2d(0,3); 	glVertex3d(-10,10,-5);
		glTexCoord2d(4,3); 	glVertex3d(10,10,-5);
		glTexCoord2d(4,0); 	glVertex3d(10,5,-5);
	glEnd();

	// upper level
	glBegin(GL_POLYGON);
		glTexCoord2d(0,0);    glVertex3d(-10,15,-5);
		glTexCoord2d(0,3); 	glVertex3d(-10,20,-5);
		glTexCoord2d(4,3); 	glVertex3d(10,20,-5);
		glTexCoord2d(4,0); 	glVertex3d(10,15,-5);
	glEnd();
	// left middle level
	glBegin(GL_POLYGON);
		glTexCoord2d(0,0);    glVertex3d(-10,10,-5);
		glTexCoord2d(0,3); 	glVertex3d(-10,15,-5);
		glTexCoord2d(1,3); 	glVertex3d(-5,15,-5);
		glTexCoord2d(1,0); 	glVertex3d(-5,10,-5);
	glEnd();
	// right mid level
	glBegin(GL_POLYGON);
		glTexCoord2d(0,0);    glVertex3d(5,10,-5);
		glTexCoord2d(0,3); 	glVertex3d(5,15,-5);
		glTexCoord2d(1,3); 	glVertex3d(10,15,-5);
		glTexCoord2d(1,0); 	glVertex3d(10,10,-5);
	glEnd();
	// window

	glBindTexture(GL_TEXTURE_2D,2);
	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
	glBegin(GL_POLYGON);
		glTexCoord2d(0,0);    glVertex3d(-5,10,-5);
		glTexCoord2d(0,1); 		glVertex3d(-5,15,-5);
		glTexCoord2d(1,1); 		glVertex3d(5,15,-5);
		glTexCoord2d(1,0); 		glVertex3d(5,10,-5);
	glEnd();
	glDisable(GL_TEXTURE_2D);


}

//----------------------------------------------------

//
//void Field::ReadBmp(char *fname)
//{
//	BITMAPFILEHEADER bf;
//	BITMAPINFOHEADER bi;
//	int size;
//	FILE* pf;
//	pf = fopen(fname,"rb");
//
//	fread(&bf,sizeof(BITMAPFILEHEADER),1,pf);
//	fread(&bi,sizeof(BITMAPINFOHEADER),1,pf);
//	size = bi.biWidth*bi.biHeight*3;
//	bmp = (unsigned char*) malloc(size);
//	fread(bmp,1,size,pf);
//
//	fclose(pf);
//}
//
//void Field::CreateTexture(int tnum)
//{
//	int i,j,k;
//
//	switch(tnum)
//	{
//	case 1:
//		for(i=0;i<TH;i++)
//			for(j=0;j<TW;j++)
//			{
//				if((j<TW/3 || j>2*TW/3)&& i >= TH/2-10 && i<=TH/2+10)
//				{
//					tx1[i][j][0] = 220; // red
//					tx1[i][j][1] = 220; // green
//					tx1[i][j][2] = 220; // blue
//					tx1[i][j][3] = 0; // alpha
//				}
//				else
//				{
//					k = -10+rand()%20;
//					tx1[i][j][0] = 100+k; // red
//					tx1[i][j][1] = 100+k; // green
//					tx1[i][j][2] = 100+k; // blue
//					tx1[i][j][3] = 0; // alpha
//				}
//			}
//		break;
//	case 2: // bricks
//		for(i=0;i<TH;i++)
//			for(j=0;j<TW;j++)
//			{
//
//				if(i<=5|| i>=TH/2-2 && i<=TH/2+2 || (i<TH/2 && j>=TW/2-2 && j<=TW/2+2) ||
//					 (i<TH/2 && j<5)||
//				(i>TH/2&& ((j>=TW/4-2 && j<=TW/4+2)||(j>=3*TW/4-2 && j<=3*TW/4+2))))
//				{
//					tx2[i][j][0] = 50; // red
//					tx2[i][j][1] = 50; // green
//					tx2[i][j][2] = 50; // blue
//					tx2[i][j][3] = 0; // alpha
//				}
//				else
//				{
//					k = -20+rand()%40;
//					tx2[i][j][0] = 170+k; // red
//					tx2[i][j][1] = 70+k; // green
//					tx2[i][j][2] = 0; // blue
//					tx2[i][j][3] = 0; // alpha
//				}
//			}
//		break;
//	case 3: // window
//		k=0;
//		for(i=0;i<TH;i++)
//			for(j=0;j<TW;j++)
//			{
//				tx3[i][j][0] = bmp[k+2]; //red
//				tx3[i][j][1] = bmp[k+1];  // green
//				tx3[i][j][2] = bmp[k];    // blue
//				tx3[i][j][3] = 0;
//				k+=3;
//			}
//		break;
//	case 4: // roof
//		k=0;
//		for(i=0;i<TH;i++)
//			for(j=0;j<TW;j++)
//			{
//				tx4[i][j][0] = bmp[k+2]; //red
//				tx4[i][j][1] = bmp[k+1];  // green
//				tx4[i][j][2] = bmp[k];    // blue
//				tx4[i][j][3] = 0;
//				k+=3;
//			}
//		break;
//	case 5: // wall with window
//		k=0;
//		for(i=0;i<TH;i++)
//			for(j=0;j<TW*2;j++)
//			{
//				tx5[i][j][0] = bmp[k+2]; //red
//				tx5[i][j][1] = bmp[k+1];  // green
//				tx5[i][j][2] = bmp[k];    // blue
//				tx5[i][j][3] = 0;
//				k+=3;
//			}
//		break;
//	case 6: // sky
//		k=0;
//		for(i=0;i<1024;i++)
//			for(j=0;j<2048;j++)
//			{
//				tx6[i][j][0] = bmp[k+2]; //red
//				tx6[i][j][1] = bmp[k+1];  // green
//				tx6[i][j][2] = bmp[k];    // blue
//				tx6[i][j][3] = 0;
//				k+=3;
//			}
//		break;
//	}// switch
//}
//
////void Field::initTextureDef()
////{
////	glEnable(GL_DEPTH_TEST);
////	glEnable(GL_SMOOTH);
////
////	glEnable(GL_NORMALIZE);
////
////	// texture definitions
////	CreateTexture(1);
////	glBindTexture(GL_TEXTURE_2D,0);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
////	glTexImage2D(GL_TEXTURE_2D,0,4,TW,TH,0,GL_RGBA,
////		GL_UNSIGNED_BYTE,tx1);
////
////		CreateTexture(2);
////	glBindTexture(GL_TEXTURE_2D,1);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
////	glTexImage2D(GL_TEXTURE_2D,0,4,TW,TH,0,GL_RGBA,
////		GL_UNSIGNED_BYTE,tx2);
////
////	ReadBmp("window3.bmp");
////	CreateTexture(3);
////	glBindTexture(GL_TEXTURE_2D,2);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
////	glTexImage2D(GL_TEXTURE_2D,0,4,TW,TH,0,GL_RGBA,
////		GL_UNSIGNED_BYTE,tx3);
////
////	ReadBmp("roof.bmp");
////	CreateTexture(4);
////	glBindTexture(GL_TEXTURE_2D,3);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
////	glTexImage2D(GL_TEXTURE_2D,0,4,TW,TH,0,GL_RGBA,
////		GL_UNSIGNED_BYTE,tx4);
////
////	ReadBmp("house1.bmp");
////	CreateTexture(5);
////	glBindTexture(GL_TEXTURE_2D,4);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
////	glTexImage2D(GL_TEXTURE_2D,0,4,TW*2,TH,0,GL_RGBA,
////		GL_UNSIGNED_BYTE,tx5);
////
////	ReadBmp("sky.bmp");
////	CreateTexture(6);
////	glBindTexture(GL_TEXTURE_2D,5);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
////	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
////	glTexImage2D(GL_TEXTURE_2D,0,4,2048,1024,0,GL_RGBA,
////		GL_UNSIGNED_BYTE,tx6);
////
////}

