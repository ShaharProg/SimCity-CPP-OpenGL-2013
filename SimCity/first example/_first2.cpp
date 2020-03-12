//// OpenGL
//#include "glut.h"
//#include <math.h>
//#include <vector>
//#include "MenuButtonTree.h"
//#include "MenuButtonRoad.h"
//#include "MenuButtonHill.h"
//#include "MenuButtonValley.h"
//#include <iostream>
//#include "FieldObject.h"
//#include <time.h>
//#include <stdio.h>
//#include "SimCity.h"
//
//
//using namespace std;
//#define WIN_WIDTH 600
//#define WIN_HEIGHT 600
//
//const int GSIZE = 600;
//const int TW = 256;
//const int TH = 256;
//
//
//
//
//SimCity  simCity;
//
//
//
//
//unsigned char tx1[TH][TW][4]; // texture1
//unsigned char tx2[TH][TW][4]; // texture2
//unsigned char tx3[TH][TW][4]; // window texture
//unsigned char tx4[TH][TW][4]; // roof texture
//
//unsigned char* bmp;
//
//double grid[GSIZE][GSIZE]={0};
//
//double angle=PI,dangle=0.0,start=0;
//double eyex=1,eyey=10,eyez=20;
//double dx=0,dy=0,dz=0;
//double sightx=0,sighty= -0.2,sightz = -1;
//double speed = 0;
//double planex=0,planey=8,planez=15;
//double plane_angle=PI/2,plane_speed=0,plane_ang_speed=0;
//double pitch = 0;
//bool IsBuilding = false;
//
//// light 1 definitions
//float ltamb1[4] = {0.4,0.3,0.3,0}; 
//float ltdiff1[4] = {0.7,0.5,0.5,0}; 
//float ltspec1[4] = {.6,.4,.4,0}; 
//float ltpos1[4] = {0.6,2,0.2,0}; // 0 means directional light
//											// 1 means positional
//
//// light 2 definitions
//float ltamb2[4] = {0.3,0.4,0.3,0}; 
//float ltdiff2[4] = {0.5,0.7,0.5,0}; 
//float ltspec2[4] = {.6,.6,.6,0}; 
//float ltpos2[4] = {-0.6,0.2,0.4,0}; // 0 means directional light
//											// 1 means positional
//
//// silver
//float mamb1[4] = {0.2,0.2,0.2,0}; 
//float mdiff1[4] = {0.6,0.6,0.6,0}; 
//float mspec1[4] = {0.5,0.5,0.5,0}; 
//// gold
//float mamb2[4] = {0.2,0.2,0.0,0}; 
//float mdiff2[4] = {0.8,0.6,0.2,0}; 
//float mspec2[4] = {0.6,.5,.4,0}; 
//
//
//
//void Smooth();
//void UpdateTerrain1();
//void UpdateTerrain2();
//void UpdateTerrain3();
//
//void ReadBmp(char *fname)
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
//void CreateTexture(int tnum)
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
//	}// switch
//}
//
//void init()
//{
//	int i;
//	glClearColor(0,0,0.4,0); // set background color
//	glEnable(GL_DEPTH_TEST);
//	glEnable(GL_SMOOTH);
//
//	srand((unsigned)time(NULL));
//
//	for(i=1;i<200;i++)
//		UpdateTerrain3();
//	for(i=1;i<400;i++)
//		UpdateTerrain1();
//	for(i=1;i<50;i++)
//		UpdateTerrain2();
//	Smooth();
//	for(i=1;i<5;i++)
//		UpdateTerrain2();
//
//	glEnable(GL_NORMALIZE);
//
//	// texture definitions
//	CreateTexture(1);
//	glBindTexture(GL_TEXTURE_2D,0);
//	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
//	glTexImage2D(GL_TEXTURE_2D,0,4,TW,TH,0,GL_RGBA,
//		GL_UNSIGNED_BYTE,tx1);
//
//		CreateTexture(2);
//	glBindTexture(GL_TEXTURE_2D,1);
//	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
//	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
//	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
//	glTexImage2D(GL_TEXTURE_2D,0,4,TW,TH,0,GL_RGBA,
//		GL_UNSIGNED_BYTE,tx2);
//
//	//ReadBmp("window3.bmp");
//	//CreateTexture(3);
//	//glBindTexture(GL_TEXTURE_2D,2);
//	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
//	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
//	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
//	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
//	//glTexImage2D(GL_TEXTURE_2D,0,4,TW,TH,0,GL_RGBA,
//	//	GL_UNSIGNED_BYTE,tx3);
//
//	//ReadBmp("roof.bmp");
//	//CreateTexture(4);
//	//glBindTexture(GL_TEXTURE_2D,3);
//	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_NEAREST);
//	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST);
//	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
//	//glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
//	//glTexImage2D(GL_TEXTURE_2D,0,4,TW,TH,0,GL_RGBA,
//	//	GL_UNSIGNED_BYTE,tx4);
//
//
//
//
//	simCity.menu->addButton((MenuButton*) new MenuButtonTree("0"));
//	simCity.menu->addButton((MenuButton*) new MenuButtonRoad("1"));
//	simCity.menu->addButton((MenuButton*) new MenuButtonHill("2"));
//	simCity.menu->addButton((MenuButton*) new MenuButtonValley("3"));
//}
//
//// low-pass filter
//void Smooth()
//{
//	double tmp[GSIZE][GSIZE] = {0};
//	int i,j;
//	for(i=1;i<GSIZE-1;i++)
//		for(j=1;j<GSIZE-1;j++)
//		{
//			tmp[i][j] = (grid[i-1][j-1] + grid[i-1][j] +grid[i-1][j+1] +
//				grid[i][j-1] + 4*grid[i][j] +grid[i][j+1]+
//				grid[i+1][j-1] + grid[i+1][j] +grid[i+1][j+1])/12;
//		}
//
//	for(i=1;i<GSIZE-1;i++)
//		for(j=1;j<GSIZE-1;j++)
//			grid[i][j] = tmp[i][j];
//}
//
//void UpdateTerrain1()
//{
//	double a,b,delta = 0.1;
//	int x1,x2,y1,y2,x,y;
//
//	x1 = rand()% GSIZE;
//	y1 = rand()% GSIZE;
//	x2 = rand()% GSIZE;
//	y2 = rand()% GSIZE;
//
//	if(rand()%2==0) delta = -delta;
//
//	if(x1!=x2)
//	{
//		a = (y2-y1)/(double)(x2-x1) ;
//		b = y1 - a*x1;
//		for(y=0;y<GSIZE;y++)
//			for(x=0;x<GSIZE;x++)
//			{
//				if(y>a*x+b) grid[y][x]+=delta;
//				else grid[y][x] -= delta;
//			}
//	}
//}
//
//void UpdateTerrain2()
//{
//	int x1,y1,points = 1500,direction;
//	double delta = 0.1;
//	x1 = rand()% GSIZE;
//	y1 = rand()% GSIZE;
//	if(rand()%2==0) delta = -delta;
//
//	while(points>0)
//	{
//		grid[y1][x1] += delta;
//		direction = rand()%4;
//		switch(direction)
//		{
//		case 0: // up
//			y1--;
//			break;
//		case 1: // right
//			x1++;
//			break;
//		case 2: // down
//			y1++;
//			break;
//		case 3: // left
//			x1--;
//			break;
//		} 
//		x1 = (x1+GSIZE) % GSIZE;
//		y1 = (y1+GSIZE) % GSIZE;
//		points--;
//	}
//}
//
//void UpdateTerrain3()
//{
//	int x,y,r;
//	int i,j;
//	double dist,alpha;
//	double delta = 1;
//
//	x = rand()% GSIZE;
//	y = rand()% GSIZE;
//	r = 1 +rand()%30 ;
//	if(rand()%2==0) delta = -delta;
//
//	for(i=y-r;i<=y+r;i++)
//		for(j = x-r;j<=x+r;j++)
//		{
//			if(i>=0 && j>=0 && i<GSIZE && j<GSIZE)
//			{
//				dist = sqrt(((double)x-j)*(x-j) + (i-y)*(i-y));
//				if(dist<r)
//				{
//					alpha = acos(dist/r);
//					grid[i][j] += delta * 0.03* r*sin(alpha);
//				}
//			}
//		}
//
//
//}
//
//void SetColor(double h)
//{
//	if(h>-5)
//	{
//	h=fabs(h);
////	glColor3d((h+3)/10,(h+3)/10,(h+3)/6);
//	if(h>0 && h<0.4) // sand
//		glColor3d(0.8,0.8,0.5);
//	else if(h<5)
//		glColor3d(0.2+h/30,(5-h)/6,0);
//	else glColor3d(h/11,h/11,h/10);
//	}
//	else glColor3d(0,0,0);
//}
//
//void DrawFloor()
//{
//	int i,j;
//	double a[3],b[3],c[3];
//	double ba[3],bc[3],n[3];
//	double len;
//
//
//	for(i=2;i<GSIZE;i++)
//		for(j=2;j<GSIZE;j++)
//		{
//			b[0] = j; b[1] = grid[i][j]; b[2] = i;
//			a[0] = j; a[1] = grid[i-1][j]; a[2] = i-1;
//			c[0] = j-1; c[1] = grid[i][j-1]; c[2] = i;
//
//			ba[0] = 0; ba[1] = a[1] - b[1]; ba[2] = -1;
//			bc[0] = -1; bc[1] = c[1] - b[1]; bc[2] = 0;
//
//			n[0] = bc[1]; 			n[1] = 1; 			n[2] = ba[1];
//			len = sqrt(n[0]*n[0] + n[2]*n[2]+1);
//			n[0]/=len;  n[1] /=len;  n[2]/=len;
//
//			glBegin(GL_POLYGON);
////					SetColor(grid[i][j]);
//				glNormal3d(n[0],n[1],n[2]);
//				glVertex3d(j-GSIZE/2,grid[i][j],i-GSIZE/2);
////					SetColor(grid[i][j-1]);
//
//			b[1] = grid[i][j-1];
//			a[1] = grid[i-1][j-1];
//			c[1] = grid[i][j-2];
//
//			bc[1] = c[1] - b[1];			ba[1] = a[1] - b[1];
//			n[0] = bc[1]; 			n[1] = 1; 			n[2] = ba[1];
//			len = sqrt(n[0]*n[0] + n[2]*n[2]+1);
//			n[0]/=len;  n[1] /=len;  n[2]/=len;
//
//				glNormal3d(n[0],n[1],n[2]);
//				glVertex3d(j-1-GSIZE/2,grid[i][j-1],i-GSIZE/2);
////					SetColor(grid[i-1][j-1]);
//
//			b[1] = grid[i-1][j-1];
//			a[1] = grid[i-2][j-1];
//			c[1] = grid[i-1][j-2];
//
//			bc[1] = c[1] - b[1];			ba[1] = a[1] - b[1];
//			n[0] = bc[1]; 			n[1] = 1; 			n[2] = ba[1];
//			len = sqrt(n[0]*n[0] + n[2]*n[2]+1);
//			n[0]/=len;  n[1] /=len;  n[2]/=len;
//
//				glNormal3d(n[0],n[1],n[2]);
//				glVertex3d(j-1-GSIZE/2,grid[i-1][j-1],i-1-GSIZE/2);
////					SetColor(grid[i-1][j]);
//			b[1] = grid[i-1][j];
//			a[1] = grid[i-2][j];
//			c[1] = grid[i-1][j-1];
//
//			bc[1] = c[1] - b[1];			ba[1] = a[1] - b[1];
//			n[0] = bc[1]; 			n[1] = 1; 			n[2] = ba[1];
//			len = sqrt(n[0]*n[0] + n[2]*n[2]+1);
//			n[0]/=len;  n[1] /=len;  n[2]/=len;
//
//				glNormal3d(n[0],n[1],n[2]);
//				glVertex3d(j-GSIZE/2,grid[i-1][j],i-1-GSIZE/2);
//			glEnd();
//		}
//
//// water
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glColor4d(0,0,0.5,0.7);
//	glBegin(GL_POLYGON);
//			glVertex3d(-GSIZE/2,0,-GSIZE/2);
//			glVertex3d(GSIZE/2,0,-GSIZE/2);
//			glVertex3d(GSIZE/2,0,GSIZE/2);
//			glVertex3d(-GSIZE/2,0,GSIZE/2);
//	glEnd();
//	glDisable(GL_BLEND);
//
//
///*	
//	glColor3d(0,1,0);
//	for(i=1;i<GSIZE;i++)
//		for(j=1;j<GSIZE;j++)
//		{
//			glBegin(GL_LINE_LOOP);
//				glVertex3d(j-GSIZE/2,1+grid[i][j],i-GSIZE/2);
//				glVertex3d(j-1-GSIZE/2,1+grid[i][j-1],i-GSIZE/2);
//				glVertex3d(j-1-GSIZE/2,1+grid[i-1][j-1],i-1-GSIZE/2);
//				glVertex3d(j-GSIZE/2,1+grid[i-1][j],i-1-GSIZE/2);
//			glEnd();
//		}
//		*/
//}
//
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
//void DrawColorCube()
//{
//	// top
//	glBegin(GL_POLYGON);
//			glColor3d(1,0,0);//red
//		glVertex3d(1,1,1);
//			glColor3d(1,0,1);// magenta
//		glVertex3d(-1,1,1);
//			glColor3d(0,0,1);//blue
//		glVertex3d(-1,1,-1);
//			glColor3d(1,1,1);// white
//		glVertex3d(1,1,-1);
//	glEnd();
//	// bottom
//	glBegin(GL_POLYGON);
//			glColor3d(1,1,0);// yellow
//		glVertex3d(1,-1,1);
//			glColor3d(0,0,0); // black
//		glVertex3d(-1,-1,1);
//			glColor3d(0,1,1); // cyan
//		glVertex3d(-1,-1,-1);
//			glColor3d(0,1,0); // green
//		glVertex3d(1,-1,-1);
//	glEnd();
//	// front
//	glBegin(GL_POLYGON);
//			glColor3d(1,0,0);
//		glVertex3d(1,1,1);
//			glColor3d(1,1,1);
//		glVertex3d(1,1,-1);
//			glColor3d(0,1,0);
//		glVertex3d(1,-1,-1);
//			glColor3d(1,1,0);
//		glVertex3d(1,-1,1);
//	glEnd();
//
//	glBegin(GL_POLYGON);
//			glColor3d(1,0,1);// magenta
//		glVertex3d(-1,1,1);
//			glColor3d(0,0,1);//blue
//		glVertex3d(-1,1,-1);
//			glColor3d(0,1,1); // cyan
//		glVertex3d(-1,-1,-1);
//			glColor3d(0,0,0); // black
//		glVertex3d(-1,-1,1);
//	glEnd();
//	// left
//	glBegin(GL_POLYGON);
//			glColor3d(1,0,0);//red
//		glVertex3d(1,1,1);
//			glColor3d(1,0,1);// magenta
//		glVertex3d(-1,1,1);
//			glColor3d(0,0,0); // black
//		glVertex3d(-1,-1,1);
//			glColor3d(1,1,0);// yellow
//		glVertex3d(1,-1,1);
//	glEnd();
//	// right
//	glBegin(GL_POLYGON);
//			glColor3d(0,0,1);//blue
//		glVertex3d(-1,1,-1);
//			glColor3d(1,1,1);// white
//		glVertex3d(1,1,-1);
//			glColor3d(0,1,0); // green
//		glVertex3d(1,-1,-1);
//			glColor3d(0,1,1); // cyan
//		glVertex3d(-1,-1,-1);
//	glEnd();
//
//}
//
//void DrawCilynder(int n)
//{
//	double teta, alpha;
//
//	teta = 2*PI/n;
//	for(alpha = 0; alpha<=2*PI;alpha+=teta)
//	{
//		glBegin(GL_POLYGON);
////				glColor3d(fabs(sin(2*alpha)), fabs(cos(2*alpha)),0);
//			glNormal3d(sin(alpha),0,cos(alpha));
//			glVertex3d(sin(alpha), 1, cos(alpha));
////				glColor3d(fabs(sin(alpha+teta)), fabs(cos(alpha+teta)),1);
//			glNormal3d(sin(alpha+teta),0,cos(alpha+teta));
//			glVertex3d(sin(alpha+teta), 1, cos(alpha+teta));
////				glColor3d(fabs(sin(alpha)), fabs(cos(alpha)),0.8);
//			glNormal3d(sin(alpha+teta),0,cos(alpha+teta));
//			glVertex3d(sin(alpha+teta), 0, cos(alpha+teta));
////				glColor3d(fabs(sin(alpha-teta)), fabs(cos(alpha-teta)),0.5);
//			glNormal3d(sin(alpha),0,cos(alpha));
//			glVertex3d(sin(alpha), 0, cos(alpha));
//		glEnd();
//	}
//}
//
//void DrawCilynder1(int n,double topr, double bottomr)
//{
//	double teta, alpha;
//	double newy;
//
//	teta = 2*PI/n;
//	for(alpha = 0; alpha<=2*PI;alpha+=teta)
//	{
//		newy = bottomr*(bottomr-topr);
//		glBegin(GL_POLYGON);
////				glColor3d(fabs(sin(2*alpha)), fabs(cos(2*alpha)),0);
//			glNormal3d(bottomr*sin(alpha),newy,bottomr*cos(alpha));
//			glVertex3d(topr*sin(alpha), 1, topr*cos(alpha));
////				glColor3d(fabs(sin(alpha+teta)), fabs(cos(alpha+teta)),1);
//			glNormal3d(bottomr*sin(alpha+teta),newy,bottomr*cos(alpha+teta));
//			glVertex3d(topr*sin(alpha+teta), 1, topr*cos(alpha+teta));
////				glColor3d(fabs(sin(alpha)), fabs(cos(alpha)),0.8);
//			glNormal3d(bottomr*sin(alpha+teta),newy,bottomr*cos(alpha+teta));
//			glVertex3d(bottomr*sin(alpha+teta), 0, bottomr*cos(alpha+teta));
////				glColor3d(fabs(sin(alpha-teta)), fabs(cos(alpha-teta)),0.5);
//			glNormal3d(bottomr*sin(alpha),newy,bottomr*cos(alpha));
//			glVertex3d(bottomr*sin(alpha), 0, bottomr*cos(alpha));
//		glEnd();
//	}
//}
//
//
//void DrawConus(int n)
//{
//	double teta, alpha;
//
//	teta = 2*PI/n;
//	for(alpha = 0; alpha<2*PI;alpha+=teta)
//	{
//		glBegin(GL_POLYGON);
////				glColor3d(fabs(sin(2*alpha)), fabs(cos(2*alpha)),0);
//			glNormal3d(sin(alpha+teta/2),1,cos(alpha+teta/2));
//			glVertex3d(0, 1, 0);
////				glColor3d(fabs(sin(alpha+teta)), fabs(cos(alpha+teta)),1);
////				glColor3d(fabs(sin(alpha)), fabs(cos(alpha)),0.8);
//
//			glNormal3d(sin(alpha+teta),1,cos(alpha+teta));
//			glVertex3d(sin(alpha+teta), 0, cos(alpha+teta));
////				glColor3d(fabs(sin(alpha-teta)), fabs(cos(alpha-teta)),0.5);
//			glNormal3d(sin(alpha),1,cos(alpha));
//			glVertex3d(sin(alpha), 0, cos(alpha));
//		glEnd();
//	}
//}
//
//void DrawSphere(int n, int slices)
//{
//	double delta,alpha;
//	delta = PI/slices;
//	int i;
//
//	for(alpha = -PI/2,i=0; alpha< PI/2; alpha+=delta,i++)
//	{
//		if(i%2==0)
//		{
//		glPushMatrix();
//		glTranslated(0,sin(alpha),0);
//		glScaled(1,sin(alpha+delta)-sin(alpha),1);
//		DrawCilynder1(n,cos(alpha+delta),cos(alpha));
//		glPopMatrix();
//		}
//	}
//
//}
//
//
//void DrawWall()
//{
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D,1);
//	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
//	// bottum level
//	glBegin(GL_POLYGON);
//		glTexCoord2d(0,0);    glVertex3d(-10,5,-5);
//		glTexCoord2d(0,3); 	glVertex3d(-10,10,-5);
//		glTexCoord2d(4,3); 	glVertex3d(10,10,-5);
//		glTexCoord2d(4,0); 	glVertex3d(10,5,-5);
//	glEnd();
//
//	// upper level
//	glBegin(GL_POLYGON);
//		glTexCoord2d(0,0);    glVertex3d(-10,15,-5);
//		glTexCoord2d(0,3); 	glVertex3d(-10,20,-5);
//		glTexCoord2d(4,3); 	glVertex3d(10,20,-5);
//		glTexCoord2d(4,0); 	glVertex3d(10,15,-5);
//	glEnd();
//	// left middle level
//	glBegin(GL_POLYGON);
//		glTexCoord2d(0,0);    glVertex3d(-10,10,-5);
//		glTexCoord2d(0,3); 	glVertex3d(-10,15,-5);
//		glTexCoord2d(1,3); 	glVertex3d(-5,15,-5);
//		glTexCoord2d(1,0); 	glVertex3d(-5,10,-5);
//	glEnd();
//	// right mid level
//	glBegin(GL_POLYGON);
//		glTexCoord2d(0,0);    glVertex3d(5,10,-5);
//		glTexCoord2d(0,3); 	glVertex3d(5,15,-5);
//		glTexCoord2d(1,3); 	glVertex3d(10,15,-5);
//		glTexCoord2d(1,0); 	glVertex3d(10,10,-5);
//	glEnd();
//	// window
//
//	glBindTexture(GL_TEXTURE_2D,2);
//	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
//	glBegin(GL_POLYGON);
//		glTexCoord2d(0,0);    glVertex3d(-5,10,-5);
//		glTexCoord2d(0,1); 		glVertex3d(-5,15,-5);
//		glTexCoord2d(1,1); 		glVertex3d(5,15,-5);
//		glTexCoord2d(1,0); 		glVertex3d(5,10,-5);
//	glEnd();
//	glDisable(GL_TEXTURE_2D);
//
//
//}
//
//void DrawHouse(int floors)
//{
//	int i;
//
//	glPushMatrix();
//	for(i=0;i<floors;i++)
//	{
//		glTranslated(0,10,0);
//		DrawWall();
//		glPushMatrix();
//			glTranslated(0,0,-20);
//			DrawWall();
//		glPopMatrix();
//		glPushMatrix();
//			glTranslated(-10,0,-15);
//			glRotated(90,0,1,0);
//			glTranslated(0,0,5);
//			DrawWall();
//			glTranslated(0,0,20);
//			DrawWall();
//		glPopMatrix();
//	}
//	// roof
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D,3);
//	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
//
//	glTranslated(0,15,0);
//
//	glBegin(GL_POLYGON);
//		glTexCoord2d(0,0);    glVertex3d(-10,5,-5);
//		glTexCoord2d(0.5,1); 		glVertex3d(0,20,-15);
//		glTexCoord2d(1,0); 		glVertex3d(10,5,-5);
//	glEnd();
//	glBegin(GL_POLYGON);
//		glTexCoord2d(0,0);    glVertex3d(-10,5,-25);
//		glTexCoord2d(0.5,1); 		glVertex3d(0,20,-15);
//		glTexCoord2d(1,0); 		glVertex3d(10,5,-25);
//	glEnd();
//	glBegin(GL_POLYGON);
//		glTexCoord2d(0,0);    glVertex3d(-10,5,-5);
//		glTexCoord2d(0.5,1); 		glVertex3d(0,20,-15);
//		glTexCoord2d(1,0); 		glVertex3d(-10,5,-25);
//	glEnd();
//	glBegin(GL_POLYGON);
//		glTexCoord2d(0,0);    glVertex3d(10,5,-5);
//		glTexCoord2d(0.5,1); 		glVertex3d(0,20,-15);
//		glTexCoord2d(1,0); 		glVertex3d(10,5,-25);
//	glEnd();
//	glDisable(GL_TEXTURE_2D);
//
//	glPopMatrix();
//}
//
//void displayEdit()
//{
//	
//	int i,j;
//	// fill the buffer with the background color
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glViewport(0,0,WIDTH,HEIGHT); //
//
//	glMatrixMode(GL_PROJECTION);	
//	glLoadIdentity();
//
//	glFrustum(-1,1,-1,1,1,200);
//	gluLookAt(eyex,eyey,eyez,eyex+sightx,eyey+sighty,eyez+sightz,0,1,0);
//
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//
//	// extra - begin:::::::::::::::::::
//
//	// texture road
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D,0);
//	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
//	glBegin(GL_POLYGON);
//		glTexCoord2d(0,0);    glVertex3d(-50,5,2);
//		glTexCoord2d(0,1); 	glVertex3d(-50,5,-2);
//		glTexCoord2d(30,1); 	glVertex3d(50,5,-2);
//		glTexCoord2d(30,0); 	glVertex3d(50,5,2);
//	glEnd();
//	glDisable(GL_TEXTURE_2D);
//
//
//
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_LIGHT1);
//	glLightfv(GL_LIGHT0,GL_AMBIENT,ltamb1);
//	glLightfv(GL_LIGHT0,GL_DIFFUSE,ltdiff1);
//	glLightfv(GL_LIGHT0,GL_SPECULAR,ltspec1);
//	glLightfv(GL_LIGHT0,GL_POSITION,ltpos1);
//	glLightf(GL_LIGHT0,GL_SHININESS,100);
//
//	glLightfv(GL_LIGHT1,GL_AMBIENT,ltamb2);
//	glLightfv(GL_LIGHT1,GL_DIFFUSE,ltdiff2);
//	glLightfv(GL_LIGHT1,GL_SPECULAR,ltspec2);
//	glLightfv(GL_LIGHT1,GL_POSITION,ltpos2);
//	glLightf(GL_LIGHT1,GL_SHININESS,100);
//
//	// material definitions
//	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mamb1);
//	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mdiff1);
//	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mspec1);
//	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,40);
//
//
//	DrawFloor();
//
///*
//	glPushMatrix();
//
//	glTranslated(0,0,-15);
//
//	glPushMatrix();
//	glTranslated(0,9,11);
////	glRotated(-start,0,1,0);
//	glRotated(-start,1,0,0);
//	glScaled(1,2,1);
//	glTranslated(0,-0.5,0);
//
//		DrawCilynder(100);
//		glTranslated(0,1,0);
//	DrawConus(100);
//		glRotated(-90,1,0,0);
//		glTranslated(3,0,0);
//		glutSolidCone(1,1,100,20);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslated(3,9,15);
////	glRotated(-start,1,0,0);
//	glScaled(1,2,1);
//	DrawCilynder1(100,0.3,1.5);
//	glTranslated(0,-1,0);
//	DrawCilynder1(100,2,0.6);
//	glPopMatrix();
//
//	// gold
////	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mamb2);
////	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mdiff2);
////	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mspec2);
////	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,120);
//
//	glTranslated(-4,7,14);
//	glRotated(-start,0,1,0);
//	glScaled(3,3,3);
//	DrawSphere(50,30);
////	glutSolidTeapot(1);
//	glPopMatrix();
//	glDisable(GL_LIGHTING);
//*/
//
//
//
//	// extra - end ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	
//	simCity.draw();
//
//	glutSwapBuffers();
//}
//
//void display()
//{
//	
//	int i,j;
//	// fill the buffer with the background color
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//	glViewport(0,0,WIDTH,HEIGHT); //
//
//	glMatrixMode(GL_PROJECTION);	
//	glLoadIdentity();
//
//	glFrustum(-1,1,-1,1,1,200);
//	gluLookAt(eyex,eyey,eyez,eyex+sightx,eyey+sighty,eyez+sightz,0,1,0);
//
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//
//
//	// extra - begin:::::::::::::::::::
//
//	// texture
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D,0);
//	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
//	glBegin(GL_POLYGON);
//		glTexCoord2d(0,0);    glVertex3d(-50,5,2);
//		glTexCoord2d(0,1); 	glVertex3d(-50,5,-2);
//		glTexCoord2d(30,1); 	glVertex3d(50,5,-2);
//		glTexCoord2d(30,0); 	glVertex3d(50,5,2);
//	glEnd();
//	glDisable(GL_TEXTURE_2D);
//
//	glPushMatrix();
//	glScaled(0.5,0.5,0.5);
//	DrawHouse(4);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslated(20,0,0);
//	glScaled(0.5,0.5,0.5);
//	DrawHouse(3);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslated(-20,0,0);
//	glScaled(0.5,0.5,0.5);
//	DrawHouse(2);
//	glPopMatrix();
//
//
//
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//	glEnable(GL_LIGHT1);
//	glLightfv(GL_LIGHT0,GL_AMBIENT,ltamb1);
//	glLightfv(GL_LIGHT0,GL_DIFFUSE,ltdiff1);
//	glLightfv(GL_LIGHT0,GL_SPECULAR,ltspec1);
//	glLightfv(GL_LIGHT0,GL_POSITION,ltpos1);
//	glLightf(GL_LIGHT0,GL_SHININESS,100);
//
//	glLightfv(GL_LIGHT1,GL_AMBIENT,ltamb2);
//	glLightfv(GL_LIGHT1,GL_DIFFUSE,ltdiff2);
//	glLightfv(GL_LIGHT1,GL_SPECULAR,ltspec2);
//	glLightfv(GL_LIGHT1,GL_POSITION,ltpos2);
//	glLightf(GL_LIGHT1,GL_SHININESS,100);
//
//	// material definitions
//	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mamb1);
//	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mdiff1);
//	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mspec1);
//	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,40);
//
//
//	DrawFloor();
//
///*
//	glPushMatrix();
//
//	glTranslated(0,0,-15);
//
//	glPushMatrix();
//	glTranslated(0,9,11);
////	glRotated(-start,0,1,0);
//	glRotated(-start,1,0,0);
//	glScaled(1,2,1);
//	glTranslated(0,-0.5,0);
//
//		DrawCilynder(100);
//		glTranslated(0,1,0);
//	DrawConus(100);
//		glRotated(-90,1,0,0);
//		glTranslated(3,0,0);
//		glutSolidCone(1,1,100,20);
//	glPopMatrix();
//
//	glPushMatrix();
//	glTranslated(3,9,15);
////	glRotated(-start,1,0,0);
//	glScaled(1,2,1);
//	DrawCilynder1(100,0.3,1.5);
//	glTranslated(0,-1,0);
//	DrawCilynder1(100,2,0.6);
//	glPopMatrix();
//
//	// gold
////	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,mamb2);
////	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,mdiff2);
////	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,mspec2);
////	glMaterialf(GL_FRONT_AND_BACK,GL_SHININESS,120);
//
//	glTranslated(-4,7,14);
//	glRotated(-start,0,1,0);
//	glScaled(3,3,3);
//	DrawSphere(50,30);
////	glutSolidTeapot(1);
//	glPopMatrix();
//	glDisable(GL_LIGHTING);
//*/
//
//
//
//	// extra - end ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	
//	glutSwapBuffers();
//}
//
//
//
//void displayComb()
//{
//	// fill the buffer with the background color
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glViewport(0,300,300,300);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glFrustum(-1,1,-1,1,1,200);
//	gluLookAt(eyex,eyey,eyez,eyex+sightx,eyey+sighty,eyez+sightz,0,1,0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	DrawFloor();
//	// plane
//	glPushMatrix();
//		glTranslated(planex,planey, planez);
//		glRotated(plane_angle*180/PI,0,1,0);  // yaw
//		glRotated(-plane_ang_speed*2000,1,0,0); // roll
//		glRotated(pitch*180/PI,0,0,1);
//		DrawPlane();
//	glPopMatrix();
//
//// top view
//	glViewport(300,300,300,300);
//
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glFrustum(-1,1,-1,1,1,200);
//	gluLookAt(eyex,80,eyez,eyex,0,eyez,sightx,0,sightz);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	DrawFloor();
//	// plane
//	glPushMatrix();
//	glTranslated(planex,planey, planez);
//	glRotated(plane_angle*180/PI,0,1,0);  // yaw
//	glRotated(-plane_ang_speed*2000,1,0,0); // roll
//	glRotated(pitch*180/PI,0,0,1);
//	DrawPlane();
//	glPopMatrix();
//
//	// cockpit view
//	glViewport(0,0,600,300);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glFrustum(-1,1,-1,1,1,200);
//	gluLookAt(planex+2*sin(plane_angle+PI/2),
//		planey+2*sin(pitch),planez+2*cos(plane_angle+PI/2),
//		planex+3*sin(plane_angle+PI/2),
//		planey+3*sin(pitch),planez+3*cos(plane_angle+PI/2),
//		0,1,0);
//
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	DrawFloor();
//	// plane
//	glPushMatrix();
//		glTranslated(planex,planey, planez);
//		glRotated(plane_angle*180/PI,0,1,0);  // yaw
//		glRotated(-plane_ang_speed*2000,1,0,0); // roll
//		glRotated(pitch*180/PI,0,0,1);
//		DrawPlane();
//	glPopMatrix();
//
//	glutSwapBuffers();
//}
//
//
//
//
//
//void idle()
//{
//	int i,j;
//	double r;
//	angle+=dangle;
//	start+=0.4;
//	sightx = sin(angle);
//	sightz = cos(angle);
//	eyex+=sightx*speed;
//	eyey+=dy;
//	eyez+=sightz*speed;
//
//	// plane
//	plane_angle+=plane_ang_speed;
//	planex+=plane_speed*sin(plane_angle+PI/2);
//	planez+=plane_speed*cos(plane_angle+PI/2);
//	planey+=plane_speed*sin(pitch);
//
///*	if(IsBuilding)
//	{
//		UpdateTerrain1();
//		UpdateTerrain2();
//		UpdateTerrain3();
//	}
//	*/
///*	start-=0.03;
//
//for(i=0;i<GSIZE;i++)
//		for(j=0;j<GSIZE;j++)
//		{
//			r = sqrt( (i-GSIZE/2.0)*(i-GSIZE/2) + (j-GSIZE/2)*(j-GSIZE/2) );
//			grid[i][j] = 3*sin(start+ r/6.0) ;
//		}
//*/
//	glutPostRedisplay();
//}
//
//
//void mouse(int button,int state,int x, int y)
//{
//	int i1,i2;
//	if (state == GLUT_DOWN)
//	{
//		double mouseX = ((double)((double)x / WIN_WIDTH) - 0.5)*2;
//		double mouseY = ((double)((double)y / WIN_HEIGHT) - 0.5)*(-2);
//		
//		//cout << "(x,y)=(" << mouseX << "," << mouseY << ")" << endl;
//		cout << "(x,y)=(" << x << "," << HEIGHT-y-1 << ")" << endl;
//
//		simCity.mouseDown(Point(mouseX,mouseY), Point(x,HEIGHT-y-1),button);
//	}
//}
//
//void SpecialKey(int key,int x,int y)
//{
//	switch(key)
//	{
//	case GLUT_KEY_LEFT:
//		dangle+=0.001;
//		break;
//	case GLUT_KEY_RIGHT:
//		dangle-=0.001;
//		break;
//	case GLUT_KEY_UP:
//		speed+=0.01;
//		break;
//	case GLUT_KEY_DOWN:
//		speed-=0.01;
//		break;
//	case GLUT_KEY_PAGE_UP:
//		dy+=0.01;
//		break;
//	case GLUT_KEY_PAGE_DOWN:
//		dy-=0.01;
//		break;
//		
//	}
//}
//
//void Keyboard(unsigned char key, int x, int y)
//{
//	switch( key)
//	{
//	case '1':
//			glutDisplayFunc(displayEdit);
//		break;
//	case '2':
//			glutDisplayFunc(displayComb);
//		break;
//
//
//
//	case 'a':
//			plane_ang_speed+=0.002;
//		break;
//	case 'd':
//			plane_ang_speed-=0.002;
//		break;
//	case 'w':
//			plane_speed+=0.01;
//		break;
//	case 's':
//			plane_speed-=0.01;
//		break;
//
//
//	case 'r':   // up
//			pitch+=0.02;
//		break;
//	case 'f':   // down
//			pitch-=0.02;
//		break;
//
//
//
//
//
//	}
//}
//
//void main(int argc, char** argv)
//{
//	glutInit(&argc,argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
//	glutInitWindowSize(WIN_WIDTH,WIN_HEIGHT);
//	glutInitWindowPosition(300,200);
//	glutCreateWindow("Elad & Shahar - SimCity");
//
//	// onPaint
//	glutDisplayFunc(displayComb);
//	// onTimer
//	glutIdleFunc(idle);
//
//	glutMouseFunc(mouse);
//	glutSpecialFunc(SpecialKey);
//	glutKeyboardFunc(Keyboard);
//
//	// onInit
//	init();
//
//	glutMainLoop();
//}