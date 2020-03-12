// OpenGL
#include "glut.h"
#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

#include "MenuButtonTree.h"
#include "MenuButtonRoad.h"
#include "MenuButtonHill.h"
#include "MenuButtonHouse.h"
#include "MenuButtonValley.h"
#include "MenuButtonCity.h"
#include "MenuButtonSetCamera.h"
#include "FieldObject.h"
#include "SimCity.h"

//#define PI 3.14

#define WIN_WIDTH 600
#define WIN_HEIGHT 600
#define MENU_WIDTH 60


const int TW = 256;
const int TH = 256;
unsigned char tx1[TH][TW][4]; //  road
unsigned char tx2[TH][TW][4]; // bricks
unsigned char tx3[TH][TW][4]; // window
unsigned char tx4[TH][TW][4]; // roof
unsigned char tx5[TH][TW*2][4]; // wall with window
unsigned char tx6[2048][8192][4]; // sky

unsigned char* bmp;

void ReadBmp(char *fname);
void CreateTexture(int tnum);
void initTextureDef();



double /*angle=0.0,*/dangle=0.0,start=0;
//double eyex=1,eyey=10,eyez=20;
double dx=0,dy=0,dz=0;
//double sightx = 0,sighty= -0.2,sightz = -1;
double speed = 0;

//double planex=0,planey=8,planez=15;
//double plane_angle=PI/2,plane_speed=0,plane_ang_speed=0;
//double pitch = 0;
bool IsBuilding = false;

//// light 1 definitions
//float ltamb1[4] = {0.4,0.3,0.3,0}; 
//float ltdiff1[4] = {0.7,0.5,0.5,0}; 
//float ltspec1[4] = {.6,.4,.4,0}; 
//float ltpos1[4] = {0.6,2,0.2,0}; // 0 means directional light
//											// 1 means positional

//// light 2 definitions
//float ltamb2[4] = {0.3,0.4,0.3,0}; 
//float ltdiff2[4] = {0.5,0.7,0.5,0}; 
//float ltspec2[4] = {.6,.6,.6,0}; 
//float ltpos2[4] = {-0.6,0.2,0.4,0}; // 0 means directional light
//											// 1 means positional

//// silver
//float mamb1[4] = {0.2,0.2,0.2,0}; 
//float mdiff1[4] = {0.6,0.6,0.6,0}; 
//float mspec1[4] = {0.5,0.5,0.5,0}; 
// gold
//float mamb2[4] = {0.2,0.2,0.0,0}; 
//float mdiff2[4] = {0.8,0.6,0.2,0}; 
//float mspec2[4] = {0.6,.5,.4,0}; 



SimCity simCity;//constructor

void init()
{
	int i;
	glClearColor(0,0,0.4,0); // set background color
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_SMOOTH);

	glEnable(GL_NORMALIZE);

	// texture definitions
	initTextureDef();

	
	
	simCity.menu->addButton((MenuButton*) new MenuButtonTree("0"));
	simCity.menu->addButton((MenuButton*) new MenuButtonRoad("1"));
	simCity.menu->addButton((MenuButton*) new MenuButtonHill("2"));
	simCity.menu->addButton((MenuButton*) new MenuButtonValley("3"));
	simCity.menu->addButton((MenuButton*) new MenuButtonHouse("4"));
	simCity.menu->addButton((MenuButton*) new MenuButtonCity("5"));
	simCity.menu->addButton((MenuButton*) new MenuButtonSetCamera("6"));

}


//void DrawPlane()
//{
//	// front
//	glColor3d(0,0,0);
//	glBegin(GL_LINE_LOOP);
//		glVertex3d(2.3,0.3,0);
//		glVertex3d(1.5,0.3,0.4);
//		glVertex3d(1.5,0.5,0);
//	glEnd();
//	glColor3d(0,0,0);
//	glBegin(GL_LINE_LOOP);
//		glVertex3d(2.3,0.3,0);
//		glVertex3d(1.5,0.3,-0.4);
//		glVertex3d(1.5,0.5,0);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//			glColor3d(1,1,1);
//		glVertex3d(3.2,0,0);
//			glColor3d(0.7,0.7,0.7);
//		glVertex3d(1.5,0,0.5);
//			glColor3d(0.6,0.6,0.6);
//		glVertex3d(1.5,0.3,0.4);
//		glVertex3d(2.3,0.3,0);
//	glEnd();
//	glBegin(GL_POLYGON);
//			glColor3d(1,1,1);
//		glVertex3d(3.2,0,0);
//			glColor3d(0.7,0.7,0.7);
//		glVertex3d(1.5,0,-0.5);
//			glColor3d(0.6,0.6,0.6);
//		glVertex3d(1.5,0.3,-0.4);
//		glVertex3d(2.3,0.3,0);
//	glEnd();
//	// middle
//	glBegin(GL_POLYGON);
//			glColor3d(0.7,0.7,0.7);
//		glVertex3d(1.5,0,0.5);
//			glColor3d(0.8,0.8,0.8);
//		glVertex3d(1.5,0.3,0.4);
//			glColor3d(0.5,0.5,0.5);
//		glVertex3d(-3.5,0,0);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//			glColor3d(0.8,0.8,0.8);
//		glVertex3d(1.5,0.3,0.4);
//			glColor3d(0.5,0.5,0.8);
//		glVertex3d(1.5,0.5,0);
//			glVertex3d(-3.5,0,0);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//			glColor3d(0.7,0.7,0.7);
//		glVertex3d(1.5,0,-0.5);
//			glColor3d(0.8,0.8,0.8);
//		glVertex3d(1.5,0.3,-0.4);
//			glColor3d(0.5,0.5,0.5);
//		glVertex3d(-3.5,0,0);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//			glColor3d(0.8,0.8,0.8);
//		glVertex3d(1.5,0.3,-0.4);
//			glColor3d(0.5,0.5,0.8);
//		glVertex3d(1.5,0.5,0);
//			glVertex3d(-3.5,0,0);
//	glEnd();
//	// wings
//	glBegin(GL_POLYGON);
//			glColor3d(0.6,0.6,0.6);
//		glVertex3d(1.5,0.2,0);
//		glVertex3d(-0.5,0.2,2.5);
//		glVertex3d(-1,0.2,2.5);
//		glVertex3d(-0.5,0.1,0);
//	glEnd();
//	glBegin(GL_POLYGON);
//			glColor3d(0.6,0.6,0.6);
//		glVertex3d(1.5,0.2,0);
//		glVertex3d(-0.5,0.2,-2.5);
//		glVertex3d(-1,0.2,-2.5);
//		glVertex3d(-0.5,0.1,0);
//	glEnd();
//	// back
//
//	glBegin(GL_POLYGON);
//			glColor3d(0.6,0.6,0.6);
//		glVertex3d(-1,0,0);
//			glColor3d(0.6,0.6,1);
//		glVertex3d(-3.3,1,0);
//		glVertex3d(-3.6,1,0);
//			glColor3d(0.6,0.6,0.6);
//		glVertex3d(-3.2,0,0);
//	glEnd();
//	// back wings
//	glBegin(GL_POLYGON);
//			glColor3d(0.6,0.6,0.6);
//		glVertex3d(-1.5,0,0);
//		glVertex3d(-2.5,0,1);
//		glVertex3d(-2.7,0,1);
//		glVertex3d(-2.7,0,-1);
//		glVertex3d(-2.5,0,-1);
//	glEnd();
//
//	
//
//}
//


// display funcs: ----------------------------- begin:

void display(int viewport_x, int viewport_y, int viewport_width, int viewport_height, 
			 double lookat_eyex, double lookat_eyey, double lookat_eyez, double lookat_centerx, double lookat_centery, double lookat_centerz, double lookat_upx, double lookat_upy, double lookat_upz)
{
	glViewport(viewport_x, viewport_y, viewport_width, viewport_height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(1,-1,-1,1,1,300);
	gluLookAt(lookat_eyex, lookat_eyey, lookat_eyez, lookat_centerx, lookat_centery, lookat_centerz, lookat_upx, lookat_upy, lookat_upz);//diff

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	simCity.field->draw2d();

	//glutSwapBuffers();
}


void displayTop()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	display(0,0,WIN_WIDTH,WIN_HEIGHT,		simCity.eye->x,80,simCity.eye->z,simCity.eye->x,0,simCity.eye->z,simCity.sight->x,0,simCity.sight->z);

	glutSwapBuffers();
}


void displayPerspective()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	display(0,0,WIN_WIDTH,WIN_HEIGHT,		simCity.eye->x,simCity.eye->y,simCity.eye->z,simCity.eye->x+simCity.sight->x,simCity.eye->y+simCity.sight->y,simCity.eye->z+simCity.sight->z,0,1,0);
	
	glutSwapBuffers();
}

void displayComb()
{
	// fill the buffer with the background color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	
	display(0,WIN_HEIGHT/2,WIN_WIDTH/2,WIN_HEIGHT/2,
		simCity.eye->x,simCity.eye->y,simCity.eye->z,simCity.eye->x+simCity.sight->x,simCity.eye->y+simCity.sight->y,simCity.eye->z+simCity.sight->z,0,1,0);


	// top view
	display(WIN_WIDTH/2,WIN_HEIGHT/2,WIN_WIDTH/2,WIN_HEIGHT/2,
		simCity.eye->x,80,simCity.eye->z,simCity.eye->x,0,simCity.eye->z,simCity.sight->x,0,simCity.sight->z);


	// cockpit view
	display(0,0,WIN_WIDTH,WIN_HEIGHT/2,
		simCity.field->plane.p.x+2*sin(simCity.field->plane.plane_angle+PI/2),
		simCity.field->plane.p.y+2*sin(simCity.field->plane.pitch),simCity.field->plane.p.z+2*cos(simCity.field->plane.plane_angle+PI/2),
		simCity.field->plane.p.x+3*sin(simCity.field->plane.plane_angle+PI/2),
		simCity.field->plane.p.y+3*sin(simCity.field->plane.pitch),simCity.field->plane.p.z+3*cos(simCity.field->plane.plane_angle+PI/2),
		0,1,0);



	glutSwapBuffers();
}


void displayCockpit()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	display(0,0,WIN_WIDTH,WIN_HEIGHT,
		simCity.field->plane.p.x+2*sin(simCity.field->plane.plane_angle+PI/2),
		simCity.field->plane.p.y+2*sin(simCity.field->plane.pitch),simCity.field->plane.p.z+2*cos(simCity.field->plane.plane_angle+PI/2),
		simCity.field->plane.p.x+3*sin(simCity.field->plane.plane_angle+PI/2),
		simCity.field->plane.p.y+3*sin(simCity.field->plane.pitch),simCity.field->plane.p.z+3*cos(simCity.field->plane.plane_angle+PI/2),
		0,1,0);

	glutSwapBuffers();
}

void displayMenu(int viewport_x, int viewport_y, int viewport_width, int viewport_height)
{	
	glViewport(viewport_x, viewport_y, viewport_width, viewport_height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, 20, 0, 1, -1); // Setup an Ortho view
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//// menu background
	//glColor3d(0.31,0.59,0.75);
	//glBegin(GL_POLYGON);
	//	glVertex2d(-1,-1);
	//	glVertex2d(-0.8,-1);
	//	glVertex2d(-0.8,1);
	//	glVertex2d(-1,1);
	//glEnd();


	simCity.menu->draw2d();

}

void displayOrtho(int viewport_x, int viewport_y, int viewport_width, int viewport_height)
{	
	glViewport(viewport_x, viewport_y, viewport_width, viewport_height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100,100,100,-100,-100,100); // Setup an Ortho view
	gluLookAt(0,200/2,0,		0,0,0,		0,0,-1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	simCity.field->draw2d();

	//glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble near, GLdouble far);
}

void displayEdit()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	//display(MENU_WIDTH,0,WIN_WIDTH,WIN_HEIGHT,
	//	0,200/2,0,		0,0,0,		0,0,-1);//eye...center...up... (200/2 because the frustom near-far range is 200.

	displayOrtho(MENU_WIDTH,0,WIN_WIDTH,WIN_HEIGHT);

	displayMenu(0,0,MENU_WIDTH,WIN_WIDTH);

	glutSwapBuffers();

}



// texture funcs: ------------------begin

void ReadBmp(char *fname)
{
	BITMAPFILEHEADER bf;
	BITMAPINFOHEADER bi;
	int size;
	FILE* pf;
	pf = fopen(fname,"rb");

	fread(&bf,sizeof(BITMAPFILEHEADER),1,pf);
	fread(&bi,sizeof(BITMAPINFOHEADER),1,pf);
	size = bi.biWidth*bi.biHeight*3;
	bmp = (unsigned char*) malloc(size);
	fread(bmp,1,size,pf);

	fclose(pf);
}

void CreateTexture(int tnum)
{
	int i,j,k;

	switch(tnum)
	{
	case 1://road
		for(i=0;i<TH;i++)
			for(j=0;j<TW;j++)
			{
				if((j<TW/3 || j>2*TW/3)&& i >= TH/2-10 && i<=TH/2+10)
				{
					tx1[i][j][0] = 220; // red
					tx1[i][j][1] = 220; // green
					tx1[i][j][2] = 220; // blue
					tx1[i][j][3] = 0; // alpha
				}
				else
				{
					k = -10+rand()%20;
					tx1[i][j][0] = 100+k; // red
					tx1[i][j][1] = 100+k; // green
					tx1[i][j][2] = 100+k; // blue
					tx1[i][j][3] = 0; // alpha
				}
			}
		break;
	case 2: // bricks
		for(i=0;i<TH;i++)
			for(j=0;j<TW;j++)
			{

				if(i<=5|| i>=TH/2-2 && i<=TH/2+2 || (i<TH/2 && j>=TW/2-2 && j<=TW/2+2) ||
					 (i<TH/2 && j<5)||
				(i>TH/2&& ((j>=TW/4-2 && j<=TW/4+2)||(j>=3*TW/4-2 && j<=3*TW/4+2))))
				{
					tx2[i][j][0] = 50; // red
					tx2[i][j][1] = 50; // green
					tx2[i][j][2] = 50; // blue
					tx2[i][j][3] = 0; // alpha
				}
				else
				{
					k = -20+rand()%40;
					tx2[i][j][0] = 170+k; // red
					tx2[i][j][1] = 70+k; // green
					tx2[i][j][2] = 0; // blue
					tx2[i][j][3] = 0; // alpha
				}
			}
		break;
	case 3: // window
		k=0;
		for(i=0;i<TH;i++)
			for(j=0;j<TW;j++)
			{
				tx3[i][j][0] = bmp[k+2]; //red
				tx3[i][j][1] = bmp[k+1];  // green
				tx3[i][j][2] = bmp[k];    // blue
				tx3[i][j][3] = 0;
				k+=3;
			}
		break;
	case 4: // roof
		k=0;
		for(i=0;i<TH;i++)
			for(j=0;j<TW;j++)
			{
				tx4[i][j][0] = bmp[k+2]; //red
				tx4[i][j][1] = bmp[k+1];  // green
				tx4[i][j][2] = bmp[k];    // blue
				tx4[i][j][3] = 0;
				k+=3;
			}
		break;
	case 5: // wall with window
		k=0;
		for(i=0;i<TH;i++)
			for(j=0;j<TW*2;j++)
			{
				tx5[i][j][0] = bmp[k+2]; //red
				tx5[i][j][1] = bmp[k+1];  // green
				tx5[i][j][2] = bmp[k];    // blue
				tx5[i][j][3] = 0;
				k+=3;
			}
		break;
	case 6: // sky
		k=0;
		for(i=0;i<2048;i++)
			for(j=0;j<8192;j++)
			{
				tx6[i][j][0] = bmp[k+2]; //red
				tx6[i][j][1] = bmp[k+1];  // green
				tx6[i][j][2] = bmp[k];    // blue
				tx6[i][j][3] = 0;
				k+=3;
			}
		break;
	}// switch
}

void initTextureDef()
{
	// texture definitions
	CreateTexture(1);
	glBindTexture(GL_TEXTURE_2D,0);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D,0,4,TW,TH,0,GL_RGBA,
		GL_UNSIGNED_BYTE,tx1);

		CreateTexture(2);
	glBindTexture(GL_TEXTURE_2D,1);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D,0,4,TW,TH,0,GL_RGBA,
		GL_UNSIGNED_BYTE,tx2);

	ReadBmp("window3.bmp");
	CreateTexture(3);
	glBindTexture(GL_TEXTURE_2D,2);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D,0,4,TW,TH,0,GL_RGBA,
		GL_UNSIGNED_BYTE,tx3);

	ReadBmp("roof.bmp");
	CreateTexture(4);
	glBindTexture(GL_TEXTURE_2D,3);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D,0,4,TW,TH,0,GL_RGBA,
		GL_UNSIGNED_BYTE,tx4);

	ReadBmp("house1.bmp");
	CreateTexture(5);
	glBindTexture(GL_TEXTURE_2D,4);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D,0,4,TW*2,TH,0,GL_RGBA,
		GL_UNSIGNED_BYTE,tx5);

	ReadBmp("sky2.bmp");
	CreateTexture(6);
	glBindTexture(GL_TEXTURE_2D,5);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D,0,4,8192,2048,0,GL_RGBA,
		GL_UNSIGNED_BYTE,tx6);

}

// texture funcs: -----------------end!

// display funcs: ----------------------------- end!


void idle()
{
	switch (simCity.state)
	{
		case '1'://edit
			break;

		default:
			int i,j;
			double r;
			simCity.angle+=dangle;
			start+=0.4;
			simCity.sight->x = sin(simCity.angle);
			simCity.sight->z = cos(simCity.angle);

			simCity.eye->x+=simCity.sight->x*speed;
			simCity.eye->y+=dy;
			simCity.eye->z+=simCity.sight->z*speed;

			simCity.setLookAt(Point(simCity.eye->x+40*sin(simCity.angle),simCity.eye->y+7,simCity.eye->z+40*cos(simCity.angle)));

			// vehicles move
			simCity.field->moveAllVehicles();

			// plane move
			simCity.field->plane.plane_angle	+=	simCity.field->plane.plane_ang_speed;
			simCity.field->plane.p.x			+=	simCity.field->plane.plane_speed*sin(simCity.field->plane.plane_angle+PI/2);
			simCity.field->plane.p.z			+=	simCity.field->plane.plane_speed*cos(simCity.field->plane.plane_angle+PI/2);
			simCity.field->plane.p.y			+=	simCity.field->plane.plane_speed*sin(simCity.field->plane.pitch);
	}
	glutPostRedisplay();
}


void mouse(int button,int mouse_state,int x, int y)
{
	switch (simCity.state)
	{
		case '1'://edit

			if (mouse_state == GLUT_DOWN)
			{
				double x1,z1;
				//cout << "(x,y)=" <<x << "," << y << ")\t";
				
				if (x<MENU_WIDTH)
				{
					simCity.menu->mouseDown(Point(x1=	((double)((double)x / MENU_WIDTH) - 0.5)*2,z1=	(double)( (double)y / WIN_HEIGHT)*20	));
					//cout << "(x,y)=" <<x1 << "," << y1 << ")" << endl;
				}
				else
				{
					if (button == GLUT_LEFT_BUTTON)
					{
						simCity.field->mouseDown(Point(x1= ((double)(((double)x-MENU_WIDTH) / WIN_WIDTH) - 0.5)*Field::GSIZE,0,z1=	((double)((double)-y / WIN_HEIGHT) + 0.5)*Field::GSIZE	));
						//cout << "(x,y=0,z)=" <<x1 << "," << 0 << "," << y1 << ")" << endl;
					}
					else // right click on field
					{
						simCity.field->mouseDownRight(Point(x1= ((double)(((double)x-MENU_WIDTH) / WIN_WIDTH) - 0.5)*Field::GSIZE,0,z1=	((double)((double)-y / WIN_HEIGHT) + 0.5)*Field::GSIZE	));
					}
				}
			}
			else if (mouse_state == GLUT_UP)
			{
				double x1,z1;
				//cout << "(x,y)=" <<x << "," << y << ")\t";
				
				if (x<MENU_WIDTH)
				{
					//simCity.menu->mouseUp(Point(x1=	((double)((double)x / MENU_WIDTH) - 0.5)*2,z1=	(double)( (double)y / WIN_HEIGHT)*20	));
					//cout << "(x,y)=" <<x1 << "," << y1 << ")" << endl;
				}
				else
				{
					simCity.field->mouseUp(Point(x1= ((double)(((double)x-MENU_WIDTH) / WIN_WIDTH) - 0.5)*Field::GSIZE,0,z1=	((double)((double)-y / WIN_HEIGHT) + 0.5)*Field::GSIZE	));
					//cout << "(x,y=0,z)=" <<x1 << "," << 0 << "," << y1 << ")" << endl;
				}
			}
		break;


		default:
			break;
	}

}

void SpecialKey(int key,int x,int y)
{
	switch (simCity.state)
	{
		case '1'://edit
			break;


		default:
			switch(key)
			{
				case GLUT_KEY_LEFT:
					dangle-=0.001;
					break;
				case GLUT_KEY_RIGHT:
					dangle+=0.001;
					break;
				case GLUT_KEY_UP:
					speed+=0.01;
					break;
				case GLUT_KEY_DOWN:
					speed-=0.01;
					break;
				case GLUT_KEY_PAGE_UP:
					dy+=0.01;
					break;
				case GLUT_KEY_PAGE_DOWN:
					dy-=0.01;
					break;
			}
	}
}

void Keyboard(unsigned char key, int x, int y)
{
	if (key>='1' && key<='5')
	{
		if (key=='1' && simCity.state!='1')					glutReshapeWindow(WIN_WIDTH +MENU_WIDTH	,WIN_HEIGHT);
		else if (key>'1' && key<='5' && simCity.state=='1')	glutReshapeWindow(WIN_WIDTH				,WIN_HEIGHT);

		switch(key)
		{
		case '1':
			glutDisplayFunc(displayEdit);
			break;
		case '2':
			glutDisplayFunc(displayPerspective);
			break;
		case '3':
			glutDisplayFunc(displayTop);
			break;
		case '4':
			glutDisplayFunc(displayCockpit);
			break;
		case '5':
			glutDisplayFunc(displayComb);
			break;
		}
		simCity.state = key;
	}
	else
	{

		switch( key)
		{

			case 'a':
					simCity.field->plane.plane_ang_speed-=0.002;
				break;
			case 'd':
					simCity.field->plane.plane_ang_speed+=0.002;
				break;
			case 'w':
					simCity.field->plane.plane_speed+=0.01;
				break;
			case 's':
					simCity.field->plane.plane_speed-=0.01;
				break;


		
			case 'r':   // up
					simCity.field->plane.pitch+=0.02;
				break;
			case 'f':   // down
					simCity.field->plane.pitch-=0.02;
				break;



			
			// vehicle
			case 'v':   // place vehicle on the 1st road

				if (simCity.field->g.size()<2) return;

				Vertex* startVertex = simCity.field->g[ rand() % simCity.field->g.size() ];
				Vertex* toVertex = startVertex->neighbors[ rand() % startVertex->neighbors.size() ];

				simCity.field->vehicles.push_back(new Vehicle(startVertex,toVertex));




				//if (simCity.field->roads.empty()) return;

				//double r,angleSidewiseFlip,angleSidewise,angleElevation;
				////vector<Point>::iterator	p1,p2;

				//Point p1( simCity.field->roads[0]->vec[0]);
				//Point p2( simCity.field->roads[0]->vec[1]);

				//simCity.field->vehicle.p = p1;
				//
				//r = sqrt( (p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y) + (p2.z-p1.z)*(p2.z-p1.z) );

				//angleSidewiseFlip = (p1.z < p2.z) ? 1 : -1 ;//problam - right
				//angleSidewise = angleSidewiseFlip*acos( (p2.x-p1.x)/r );//*180/PI;
				//angleElevation = asin( (p2.y-p1.y)/r );//*180/PI;

				//simCity.field->vehicle.vehicle_angle = -angleSidewise;
				//simCity.field->vehicle.pitch = angleElevation;
				//simCity.field->vehicle.vehicle_ang_speed = 0;
				//simCity.field->vehicle.vehicle_speed = 0;

				//simCity.field->vehicle.dx=cos(angleElevation)*cos(angleSidewise);
				//simCity.field->vehicle.dz=cos(angleElevation)*sin(angleSidewise);
				//simCity.field->vehicle.dh=sin(angleElevation);
				//simCity.field->vehicle.dh = (abs(simCity.field->vehicle.dh)<0.01)?0:simCity.field->vehicle.dh;

				break;

		}
	}
}

void onMouseMove(int x, int y)
{
	simCity.field->mouse_x = ((x*1.0-MENU_WIDTH)/WIN_WIDTH-0.5)*Field::GSIZE;
	simCity.field->mouse_y = simCity.field->grid[int(y*1.0/WIN_HEIGHT*Field::GSIZE)][int((x*1.0-MENU_WIDTH)/WIN_WIDTH*Field::GSIZE)];
	simCity.field->mouse_z = ((-y*1.0)/WIN_HEIGHT+0.5)*Field::GSIZE;
	//cout << "(x,y)=" << x << "," << y << ")" << endl;
	if (simCity.selectedButton != NULL){
		simCity.selectedButton->actionMove(Point(simCity.field->mouse_x,simCity.field->mouse_y,simCity.field->mouse_z));
	}
}

void main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WIN_WIDTH+MENU_WIDTH,WIN_HEIGHT);
	glutInitWindowPosition(70,150);
	glutCreateWindow("simCity");
	
	HWND hWnd = GetConsoleWindow();
    if( hWnd == NULL)
    {
        cout << "Error getting console window handle\n";
        return;
    }
	MoveWindow(hWnd,100+650,150,WIN_WIDTH+MENU_WIDTH,WIN_HEIGHT,TRUE);


	// onPaint
	glutDisplayFunc(displayEdit);//simCity.state='1'
	// onTimer
	glutIdleFunc(idle);
	glutMouseFunc(mouse);
	glutPassiveMotionFunc(onMouseMove);
	glutMotionFunc(onMouseMove);
	glutSpecialFunc(SpecialKey);
	glutKeyboardFunc(Keyboard);
	init();
	glutMainLoop();
}