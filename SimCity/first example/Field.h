#pragma once
#include "Point.h"
#include "FieldObject.h"
#include "Plane.h"
#include "Vehicle.h"

#include <time.h>
#include <vector>
#include <iostream>
using namespace std;

class SimCity;//forward declaration



////typedef vector<   Pair<Point,neighbors>   > graph;
//typedef pair<Point,graph>* neighbor;
//typedef vector<neighbor> graph;

//moved to Road.h
//typedef pair<Point,graph> neighbor;
//typedef vector<neighbor*> graph;

class Field
{

public:
	SimCity* simCity;
	vector<FieldObject*> fieldObjects;
	//vector<Road*> roads;//new
	Graph g;// new new

	static const int GSIZE = 200;
	double grid[GSIZE][GSIZE];
	
	double mouse_x;
	double mouse_y;
	double mouse_z;

	Plane				plane;//single
	vector<Vehicle*>	vehicles;

	//static const int TW = 256;
	//static const int TH = 256;

	//unsigned char tx1[TH][TW][4]; // texture1
	//unsigned char tx2[TH][TW][4]; // texture2
	//unsigned char tx3[TH][TW][4]; // window texture
	//unsigned char tx4[TH][TW][4]; // roof texture
	//unsigned char tx5[TH][TW*2][4]; // wall with window
	//unsigned char tx6[1024][2048][4]; // sky

	//unsigned char* bmp;


	// light 1 definitions
	static const float ltamb1[4];// = {0.4,0.3,0.3,0}; 
	static const float ltdiff1[4];// = {0.7,0.5,0.5,0}; 
	static const float ltspec1[4];// = {.6,.4,.4,0}; 
	static const float ltpos1[4];// = {0.6,2,0.2,0}; // 0 means directional light
												// 1 means positional
	
	// light 2 definitions
	static const float ltamb2[4];// = {0.3,0.4,0.3,0}; 
	static const float ltdiff2[4];// = {0.5,0.7,0.5,0}; 
	static const float ltspec2[4];// = {.6,.6,.6,0}; 
	static const float ltpos2[4];// = {-0.6,0.2,0.4,0}; // 0 means directional light
												// 1 means positional

	// silver material
	static const float mamb1[4];// = {0.2,0.2,0.2,0}; 
	static const float mdiff1[4];// = {0.6,0.6,0.6,0}; 
	static const float mspec1[4];// = {0.5,0.5,0.5,0};


public:
	Field(SimCity* simCity) : simCity(simCity), plane(Point(0,8,15))//, vehicle(Point(0,8,10))
	{
		//plane = Plane(Point(0,8,15));
		int i;

		for (i=0;i<GSIZE;i++)
		{
			for (int j=0;j<GSIZE;j++)
			{
				grid[i][j] = 0;
			}
		}


		srand((unsigned)time(NULL));

		for(i=1;i<200;i++)
			UpdateTerrain3();
		for(i=1;i<400;i++)
			UpdateTerrain1();
		for(i=1;i<50;i++)
			UpdateTerrain2();
		Smooth();
		for(i=1;i<5;i++)
			UpdateTerrain2();


		//initTextureDef();


	}

	~Field(void);

	void startGraph(Point& p)
	{
		Vertex *ver = new Vertex();
		ver->p			= p;
		ver->neighbors	= Graph();

		this->g.push_back(ver);// maybe just "graph()" instead of "new graph()" ?
	}
	
	void addNeighbor(Point& p)
	{
		Vertex*	v1 = g[g.size()-1];

		Vertex *v2 = new Vertex();
		v2->p			= p;
		v2->neighbors	= Graph();

		g.push_back(v2);

		v1->neighbors.push_back(v2);
		v2->neighbors.push_back(v1);
	}

	void moveAllVehicles()
	{
		for (Vehicle *vehicle : vehicles)
		{
			vehicle->move();
		}
	}

	void mouseDown(Point p);
	void mouseDownRight(Point p);
	void mouseUp(Point p);

	void draw2d();

	void addFieldObject(FieldObject* fieldObject);

	// imported

	void DrawFloor();
	void SetColor(double h);
	void Smooth();
	void UpdateTerrain1();
	void UpdateTerrain2();
	void UpdateTerrain3();


	//--------------------------------

static void output(GLfloat x, GLfloat y,GLfloat z,GLfloat xSzize, GLfloat ySize,GLfloat zSize, char *text);
	
static void DrawColorCube();

static void DrawCilynder(int n);

static void DrawCilynder1(int n,double topr, double bottomr);

static void DrawConus(int n);

static void DrawSphere(int n, int slices);

// th is how many textures we have on cilynder
static void DrawTCilynder(int n, int tx,int th,double topr, double bottomr, 
							double vt, double vb);

static void DrawTSphere(int n, int slices,int tx,int th,int tv);

static void DrawWall();

//------------------------------------


//void ReadBmp(char *fname);
//
//void CreateTexture(int tnum);
//
//void initTextureDef();
};

