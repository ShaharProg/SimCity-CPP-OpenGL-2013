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
//
//#include "SimCity.h"
//
//using namespace std;
//#define WIN_WIDTH 600
//#define WIN_HEIGHT 600
//
//
////const int WIDTH = 600;
////const int HEIGHT = 600;
//
//
//
//
//double angle=0,dx=0,dangle=0.5;
//
//SimCity  simCity;
//
//void init()
//{
//	glOrtho(-1,1,-1,1,1,-1);
//	glClearColor(0.31,0.55,0.14,0); // set background color
//
//
//
//	simCity.menu->addButton((MenuButton*) new MenuButtonTree("0"));
//	simCity.menu->addButton((MenuButton*) new MenuButtonRoad("1"));
//	simCity.menu->addButton((MenuButton*) new MenuButtonHill("2"));
//	simCity.menu->addButton((MenuButton*) new MenuButtonValley("3"));
//}
//
//void display()
//{
//	// fill the buffer with the background color
//	glClear(GL_COLOR_BUFFER_BIT);
//	glLoadIdentity();//clear memory about previous state
//
//	
//	simCity.draw();
//
//	glutSwapBuffers();
//}
//
//void idle()
//{
//	Sleep(50);
//	angle+=1;
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
//void main2(int argc, char** argv)
//{
//	glutInit(&argc,argv);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
//	glutInitWindowSize(WIN_WIDTH,WIN_HEIGHT);
//	glutInitWindowPosition(100,100);
//	glutCreateWindow("Targil 1");
//
//	// onPaint
//	glutDisplayFunc(display);
//	// onTimer
//	glutIdleFunc(idle);
//	glutMouseFunc(mouse);
//	init();
//	glutMainLoop();
//}