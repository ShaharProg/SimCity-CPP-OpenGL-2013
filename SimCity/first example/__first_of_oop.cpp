// OpenGL
#include "glut.h"
#include <math.h>
#include <vector>
	#include "MenuButtonTree.h"
	#include "MenuButtonRoad.h"
	#include "MenuButtonHill.h"
#include <iostream>
	#include "FieldObject.h"

	#include "SimCity.h"

using namespace std;
#define WIN_WIDTH 600
#define WIN_HEIGHT 600

#define PI 3.14159

double angle11=0,dx11=0,dangle11=0.5;
//vector<MenuButton*> menuButtons;
//vector<MenuButton*>::iterator it;
//int selectedButton = -1;

//111111//SimCity  simCity11;

//vector<FieldObject*> fieldObjects;


//
//void DrawTree(double len,int a)
//{
//	if(len>0.003)
//	{
//		glLineWidth(5*len);
//		glColor3d(len,0.2+ 0.8*(1-len),0);
//		glBegin(GL_LINES);
//			glVertex2d(0,0);
//			glVertex2d(0,len);
//		glEnd();
//		// top
//		glPushMatrix();
//			glTranslated(0,len,0);
//			glRotated(a,0,0,1);
//			DrawTree(len*0.6,-5+rand()%10);
//		glPopMatrix();
//		glPushMatrix();
//			glTranslated(0,len,0);
//			glRotated(-80,0,0,1);
//			DrawTree(len*0.5,0);
//		glPopMatrix();
//		glPushMatrix();
//			glTranslated(0,len,0);
//			glRotated(80,0,0,1);
//			DrawTree(len*0.5,0);
//		glPopMatrix();
//	}
//}
//
//void drawBtnTree()
//{
//	//glPushMatrix();
//		//glTranslated(0,-0.08,0);
//		//glScaled(0.1,0.1,1);
//		//DrawTree(0.6,0);
//		Tree::drawFieldObject(Point(0,-0.08));
//	//glPopMatrix();
//}
//
//void drawButton()
//{
//	glPushMatrix();
//		glScaled(0.8,0.8,1);
//		glColor3d(0,0,0);
//		glBegin(GL_POLYGON);
//			glVertex2d(-0.1,-0.1);
//			glVertex2d(0.1,-0.1);
//			glVertex2d(0.1,0.1);
//			glVertex2d(-0.1,0.1);
//		glEnd();
//	glPopMatrix();
//}
//
//void drawSelectedButton()
//{
//	glPushMatrix();
//		glScaled(0.8,0.8,1);
//		glColor4d(1,1,0,0.6);
//		glBegin(GL_POLYGON);
//			glVertex2d(-0.1,-0.1);
//			glVertex2d(0.1,-0.1);
//			glVertex2d(0.1,0.1);
//			glVertex2d(-0.1,0.1);
//		glEnd();
//	glPopMatrix();
//}
//
//void drawMenu()
//{
//	int i=0;
//
//	glColor3d(0.31,0.59,0.75);
//	glBegin(GL_POLYGON);
//		glVertex2d(-1,-1);
//		glVertex2d(-0.8,-1);
//		glVertex2d(-0.8,1);
//		glVertex2d(-1,1);
//	glEnd();
//
//	for (it = menuButtons.begin(); it!=menuButtons.end(); ++it)
//	{
//		
//		glPushMatrix();
//			glTranslated(-0.9,0.9-(i*0.18),0);
//
//			if (i == selectedButton)
//				drawSelectedButton();
//			else
//				drawButton();
//
//			(*it)->draw();
//		glPopMatrix();
//		i++;
//	}
//
//	//for (it = menuButtons.begin(); it!=menuButtons.end(); ++it)
//	//{
//	//	glPushMatrix();
//	//		glTranslated(-0.9,0.9,0);
//	//		glScaled(0.8,0.8,1);
//	//		drawButton();
//	//	glPopMatrix();
//
//	//	glPushMatrix();
//	//		glTranslated(-0.9,0.8,0);
//	//		glScaled(0.1,0.1,1);
//	//		menuButtons[0].draw();
//	//	glPopMatrix();
//	//}
//
//
//		//glTranslated(-0.9,0.8,0);
//		//glScaled(0.1,0.1,1);
//		//DrawTree(0.7,0);
//}
//
//void drawField()
//{
//}


void init11()
{
	glOrtho(-1,1,-1,1,1,-1);
	glClearColor(0.31,0.55,0.14,0); // set background color

	//simCity = SimCity();
	//111111111//simCity.menu->addButton((MenuButton*) new MenuButtonTree("0"));
	//111111111//simCity.menu->addButton((MenuButton*) new MenuButtonRoad("1"));
	//111111111//simCity.menu->addButton((MenuButton*) new MenuButtonHill("2"));
}

void display11()
{
	// fill the buffer with the background color
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();//clear memory about previous state

	//111111111//simCity.draw2d();
	//drawMenu();
	//menuButtons[0]->action(Point(0.5,0.5)); 
	//drawField();
	//glTranslated(0,-1,0);
	//glScaled(0.1,0.1,1);
	//DrawTree(0.7,0);

	glutSwapBuffers();
}

void idle11()
{
	Sleep(50);
	angle11+=1;
	glutPostRedisplay();
}


void mouse11(int button,int state,int x, int y)
{
	int i1,i2;
	if (state == GLUT_DOWN)
	{
		double mouseX = ((double)((double)x / WIN_WIDTH) - 0.5)*2;
		double mouseY = ((double)((double)y / WIN_HEIGHT) - 0.5)*(-2);
		
		cout << "(x,y)=(" << mouseX << "," << mouseY << ")" << endl;

		//111111111//simCity.mouseDown(Point(mouseX,mouseY));

		//if(6<x && x<53)//wide // mouse pressed in manu area
		//if(6<x && x<53)//wide // mouse pressed in manu area
		//{
		//	i1 = (y - 6)/53 ;
		//	cout << "button: "<< i1+1 << endl;
		//	if (i1 == selectedButton)
		//		selectedButton = -1; //disable selected button
		//	else
		//		selectedButton = i1; //select button i1
		//}
		//else if (selectedButton > -1) // mouse pressed in field && one of the buttons is selected
		//{
		//	menuButtons[selectedButton]->action(new Point(mouseX,mouseY)); //put button value in point(x,y)
		//}


		//y = ((i+1)*6 + i*47))
		//y = 6i +6 + 47i
		//y = 53i + 6
		//y -6 = 53i
		//i1 = (y - 6)/53 ; //+1
		//i2=((y+47)-6)/53;
		//cout << "i1=(" << i1 <<")" << endl;
		//cout << "i2=(" << i2 <<")" << endl;
	}
}

void main11(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(WIN_WIDTH,WIN_HEIGHT);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Targil 1");

	// onPaint
	glutDisplayFunc(display11);
	// onTimer
	glutIdleFunc(idle11);
	glutMouseFunc(mouse11);
	init11();
	glutMainLoop();
}