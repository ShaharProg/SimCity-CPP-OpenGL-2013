#pragma once
#include <string>
#include "Point.h"
#include <vector>
#include "glut.h"
#include "FieldObject.h"

using namespace std;
//#define MAX_STR_LEN 20

class SimCity;//forward declaration

class MenuButton
{

public:
	
	SimCity* simCity;
	//char	name[MAX_STR_LEN];
	char*	name;
	//void	(*drawFunc)();
	int clickNum;
	bool onDrag;

	//static void setVecRef(vector<FieldObject*>& vecRef)
	//{
	//	vecRef = vecRef;
	//}
	
public:
	MenuButton(char* name) : clickNum(0), onDrag(false)
	{
		this->name = (char*) malloc(sizeof(name));
		strcpy(this->name, name);
	}
	virtual void action(Point& p) =0;
	virtual void actionRight(Point& p){};
	virtual void actionUp(Point& p){}
	virtual void actionMove(Point& p){}

	void setSimCity(SimCity* simCity)
	{
		this->simCity = simCity;
	}
	
	virtual void draw2d();

	~MenuButton(void){delete(name);}

	//friend class Menu;
};


