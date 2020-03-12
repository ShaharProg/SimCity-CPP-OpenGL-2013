#include "Road.h"
#include "SimCity.h"

#include <math.h>


Road::Road(Point p, SimCity *simCity) : simCity(simCity)
{
	// last mouse click is the 1st
	if (p.y<0.1) p.y=0.1;
	vec.push_back(p);
	//simCity->field->addRoad(*this);
	//simCity->field->startGraph(p);
}


Road::~Road(void)
{
}

void Road::operator+=(Point& p2)
{
	double r,dx,x,dz,z,dh,h,angleSidewise, angleElevation;
	int currentLegType, prevLegType, angleSidewiseFlip;// later turn to enum...
	//vector<Point>::iterator it1,it2;
	//it1 = (--it1=vec.end());
	if (p2.y<0.1) p2.y=0.1;
	Point p1(vec[vec.size()-1]);// p1 == prev clicked point
	x=p1.x;
	h=p1.y;
	z=p1.z;

	//if (this->roadType.size()>0)// last mouse click is the 3rd or later
	//{
	//	prevLegType = this->roadType[this->roadType.size()-1];// could be everything
	//}
	//else// last mouse click is the 2nd
	//{
	//	prevLegType = decideLegType(x,h,z);// or sea or land
	//}
	double dr = 2;



	// fetch legs - begin
	// ------
	// fetch legs - end

	r = sqrt( (p2.x-p1.x)*(p2.x-p1.x) + (p2.y-p1.y)*(p2.y-p1.y) + (p2.z-p1.z)*(p2.z-p1.z) );

	angleSidewiseFlip = (p1.z < p2.z) ? 1 : -1 ;//problam - right
	angleSidewise = angleSidewiseFlip*acos( (p2.x-p1.x)/r );//*180/PI;
	angleElevation = asin( (p2.y-p1.y)/r );//*180/PI;

	dx=dr*cos(angleElevation)*cos(angleSidewise);
	dz=dr*cos(angleElevation)*sin(angleSidewise);
	dh=dr*sin(angleElevation);
	dh = (abs(dh)<0.01)?0:dh;

	// checking the 1st mini-leg
	prevLegType = decideLegType(x,h,z);// or sea or land
	x+=dx;
	h+=dh;
	z+=dz;

	//checking the rest of the mini-legs to see if there's a change
	for (double rTag=dr;	rTag<r;	rTag+=dr,x+=dx, h+=dh, z+=dz)
	{
		//currentLegType = decideLegType(x,h,z,x-dx,h-dh,z-dz,angleSidewise,angleElevation);
		currentLegType = decideLegType(x,h,z,x-dx,h-dh,z-dz,dx/dr,dh/dr,dz/dr);
		if (prevLegType != currentLegType)
		{
			roadType.push_back(prevLegType);
			if (h<0.1) h=0.1;
			vec.push_back(Point(x,h,z));
			prevLegType = currentLegType;
		}
	}

	roadType.push_back(prevLegType);
	vec.push_back(p2);


	//simCity->field->addNeighbor(p2);
}

//int Road::decideLegType(double x1, double h1, double z1, double x2, double h2, double z2, double angleSidewise, double angleElevation)
int Road::decideLegType(double x1, double h1, double z1, double x2, double h2, double z2, double ddx, double ddh, double ddz)
{
	double tunnelRadius = 1.5;
	//int y = simCity->field->grid[(int)(-z1)+Field::GSIZE/2][(int)x1+Field::GSIZE/2];
	double y = simCity->field->grid[(int)(-z1)+Field::GSIZE/2-1][(int)x1+Field::GSIZE/2-1];


	if (y>0.1 && y>h1+tunnelRadius*3)// tunnel
	{
		//return tunnel (2)
		return 2;
	}
	else if (y>0.1 && y>h1)// quarrying (jatziva)
	{
		//quarrying
		//updates grid to road hights

		double r = tunnelRadius*2;


		double temp;
		if (x2<x1)
		{
			temp=x1;
			x1=x2;
			x2=temp;
		}
		if (z2<z1)
		{
			temp=z1;
			z1=z2;
			z2=temp;
		}

		//double ddx=cos(angleElevation)*sin(angleSidewise);// no flipping?!
		//double ddz=cos(angleElevation)*cos(angleSidewise);
		//double ddh=sin(angleElevation);

		double a,b,a2,b2,delta_x,delta_z;

		if (x2==x1)// || z2==z1)
		{
			//cout << "take care diferently" << endl;
			//return -1;//stam..
			x2++;
		}

		// a!=infinity && a!=0
		a = (z2-z1)/(x2-x1);
		b = z2-a*x2;

		a2 = -1/a;
		delta_x = r*cos(atan(a2));
		delta_z = r*sin(atan(a2));
		//b2 = z

		double z=z1,x=x1,h=h1,yMax=h1,yTemp;


		//		for (int i=0;i<r;i++)
		x=x1;
		z=z1;

		double rrr = sqrt( (x2-x1)*(x2-x1) + (z2-z1)*(z2-z1) );
		double dr = rrr/( (x2-x1)+ (z2-z1) );
		for (double rt=0;	rt<rrr;	rt+=dr, x+=ddx, h+=ddh, z+=ddz)
		{

			double xt,zt;
			b2 = z-a2*x;

			if (abs(a2)<1)	// run on x and find z
			{
				//for (int xt=x-delta_x;	xt<x+delta_x;		++xt) // ++ or +=0.X ???
				//{
				//	zt = a2*xt + b2;
				//	this->simCity->field->grid[(int)(-zt + Field::GSIZE/2)][(int)(xt + Field::GSIZE/2)] = h-0.1;

				//}
				for (int xt=x-r;	xt<x+r;		++xt) // ++ or +=0.X ???
				{
					for (int zt=z-r;	zt<z+r;		++zt) // ++ or +=0.X ???
					{
						//if((int)-zt+Field::GSIZE/2>0 && (int)-zt+Field::GSIZE/2<Field::GSIZE && (int)xt+Field::GSIZE/2>=0 && (int)xt+Field::GSIZE/2<Field::GSIZE)	// in field ranges
						{
							double dist = sqrt(double((x-xt)*(x-xt)+(z-zt)*(z-zt)));
							if(dist<r)	// in circle
							{
								this->simCity->field->grid[(int)(-zt + Field::GSIZE/2)][(int)(xt + Field::GSIZE/2)] = h-0.1;
							}
						}
					}
				}
			}
			else			// run on z and find x
			{
				//for (int zt=z-delta_z;	zt<z+delta_z;		++zt) // ++ or +=0.X ???
				//{
				//	xt = (zt - b2)/a2;
				//	this->simCity->field->grid[(int)(-zt + Field::GSIZE/2)][(int)(xt + Field::GSIZE/2)] = h-0.1;

				//}

				for (int xt=x-r;	xt<x+r;		++xt) // ++ or +=0.X ???
				{
					for (int zt=z-r;	zt<z+r;		++zt) // ++ or +=0.X ???
					{
						if((int)-zt+Field::GSIZE/2>0 && (int)-zt+Field::GSIZE/2<Field::GSIZE && (int)xt+Field::GSIZE/2>=0 && (int)xt+Field::GSIZE/2<Field::GSIZE)	// in field ranges
						{
							double dist = sqrt(double(x-xt)*(x-xt)+(z-zt)*(z-zt));
							if(dist<r)	// in circle
							{
								this->simCity->field->grid[(int)(-zt + Field::GSIZE/2)][(int)(xt + Field::GSIZE/2)] =h-0.1;
							}
						}
					}
				}
			}
		}





		////ddx=i*cos(angleElevation)*cos(angleSidewise);
		////ddz=i*cos(angleElevation)*sin(angleSidewise);
		////ddh=i*sin(angleElevation);
		//yTemp=simCity->field->grid[(int)(-z)+Field::GSIZE/2][(int)x+Field::GSIZE/2] - h; 
		//if ( yMax < yTemp )
		//{
		//	yMax = yTemp;
		//}

		//}

		////x=r/2*cos(angleElevation)*cos(angleSidewise) + x1;
		////z=r/2*cos(angleElevation)*sin(angleSidewise) + z1;
		////this->simCity->field->grid[(int)(-z)+Field::GSIZE/2][(int)x+Field::GSIZE/2]-yMax;
		//z=z1,x=x1;


		//int i,j;
		//r*=2;
		//double dist;
		//for(int i=z-r+1; i<z+r; i++)
		//{
		//	for(int j=x-r+1; j<x+r; j++)
		//	{
		//		if((int)-i+Field::GSIZE/2>0 && (int)-i+Field::GSIZE/2<Field::GSIZE && (int)j+Field::GSIZE/2>=0 && (int)j+Field::GSIZE/2<Field::GSIZE)	// in field ranges
		//		{
		//			dist = sqrt(double(x-j)*(x-j)+(z-i)*(z-i));
		//			if(dist<r)	// in circle
		//			{
		//				//ca = dist/r;
		//				//alpha = acos(ca);
		//				//h = (double)r*sin(alpha)*(1.0/10.0)*0.1;						//this->simCity->field->grid[i][j] -= h;
		//				
		//				
		//				//this->simCity->field->grid[i][j] -= yMax;
		//				this->simCity->field->grid[(int)-i+Field::GSIZE/2][(int)j+Field::GSIZE/2] -= yMax;//=7;DEBUG


		//				//this->simCity->field->grid[(int)(-z)+Field::GSIZE/2][(int)x+Field::GSIZE/2]-yMax;
		//		
		//				//if (dist==0)cout<<this->simCity->field->grid[i][j]<<endl;

		//			}
		//		}
		//	}
		//}


		//
		//double ddx=cos(angleElevation)*cos(angleSidewise);
		//double ddz=cos(angleElevation)*sin(angleSidewise);
		//double ddh=sin(angleElevation);

		//int zDirection =	(z1<z2)?1:-1;
		//int xDirection =	(x1<x2)?1:-1;

		//double z=z1,x=x1,h=h1-0.1;

		//for (int i=0;i<10;i++)
		//{
		////ddx=i*cos(angleElevation)*cos(angleSidewise);
		////ddz=i*cos(angleElevation)*sin(angleSidewise);
		////ddh=i*sin(angleElevation);
		//z+=ddz;
		//x+=ddx;
		//h+=ddh;

		//simCity->field->grid[(int)(-z)+Field::GSIZE/2][(int)x+Field::GSIZE/2] = h;

		//for(i=p1.z-r+1; i<p1.z+r; i++)
		//{
		//	for(j=p1.x-r+1; j<p1.x+r; j++)
		//	{
		//		if(i>0 && i<Field::GSIZE && j>=0 && j<Field::GSIZE)	// in field ranges
		//		{
		//			dist = sqrt(double(p1.x-j)*(p1.x-j)+(p1.z-i)*(p1.z-i));
		//			if(dist<r)	// in circle
		//			{
		//				ca = dist/r;
		//				alpha = acos(ca);
		//				h = (double)r*sin(alpha)*(1.0/10.0)*0.1;
		//		
		//				this->simCity->field->grid[i][j] -= h;
		//		
		//				if (dist==0)cout<<this->simCity->field->grid[i][j]<<endl;

		//			}
		//		}
		//	}
		//}

		//}

		//for (int z=(int)z1;	z<(int)z2;	z+=zDirection)
		//{
		//	for (int x=(int)x1;	x<(int)x2;	x+=xDirection)
		//	{
		//		if ()
		//	}
		//}


		y = simCity->field->grid[(int)(-z1)+Field::GSIZE/2-1][(int)x1+Field::GSIZE/2-1];
	}


	if (y<=0.1)// bridge, over the water
	{
		//return bridge (1)
		return 1;
	}
	else// regular (0), over the ground
	{
		//return regular
		return 0;
	}
}

void Road::draw2d()
{
	// assumes it must have at least 2 points (otherwise it won't be drawed)
	vector<Point>::iterator it1,it2,it3,it4;
	int leg;
	double r, legStart, legStop;
	double angleSidewise, angleElevation, angleSidewisePrev,angleSidewiseNext, rPrev, rNext;

	int angleSidewiseFlip, angleElevationFlip, angleSidewiseFlipPrev, angleSidewiseFlipNext;

	it4 = this->vec.begin();
	it3 = it4++;
	it2 = it3++;it4++;
	it1 = this->vec.begin();

	/*
	it1 0
	it2 0
	it3 1 
	it4 2
	*/
	leg = 0;// for the legtype
	

	//if (	it3 == vec.end()	)// only one leg situation
	//{
	//	// sets the iterators to make the loop work for one iteration.
	//	--it1;
	//	--it2;
	//	--it3;
	//	--it4;
	//}
	int vecsize = vec.size();
	for (;	it3 != vec.end();			++it2,++it3,++leg)
	{
		if(leg > 1) ++it1;//only once
		if( (leg > 0) && (it4 != vec.end()) ) ++it4;

		r = sqrt( (it3->x-it2->x)*(it3->x-it2->x) + (it3->y-it2->y)*(it3->y-it2->y) + (it3->z-it2->z)*(it3->z-it2->z) );

		angleSidewiseFlip = (it2->z < it3->z) ? -1 : 1 ;//problam - right
		angleSidewise = angleSidewiseFlip*acos( (it3->x-it2->x)/r )*180/PI;
		angleElevation = asin( (it3->y-it2->y)/r );


		// check edges

		// check prev
		if (it2 != vec.begin())
		{
			rPrev = sqrt( (it2->x-it1->x)*(it2->x-it1->x) + (it2->y-it1->y)*(it2->y-it1->y) + (it2->z-it1->z)*(it2->z-it1->z) );
			angleSidewiseFlipPrev = (it1->z < it2->z) ? -1 : 1 ;//problam - right
			angleSidewisePrev = angleSidewiseFlipPrev*acos( (it2->x-it1->x)/rPrev )*180/PI;
			legStart = (abs(angleSidewise - angleSidewisePrev) > 10) ? 2 : 0;
		}
		else
		{
			legStart = 0;
		}

		//check next
		if (it4 != vec.end())
		{
			rNext = sqrt( (it4->x-it3->x)*(it4->x-it3->x) + (it4->y-it3->y)*(it4->y-it3->y) + (it4->z-it3->z)*(it4->z-it3->z) );
			angleSidewiseFlipNext = (it3->z < it4->z) ? -1 : 1 ;//problam - right
			angleSidewiseNext = angleSidewiseFlipNext*acos( (it4->x-it3->x)/rNext )*180/PI;
			legStop = (abs(angleSidewise - angleSidewiseNext) > 10) ? r-2 : r;
		}
		else
		{
			legStop = r;
		}

		glPushMatrix();
		glTranslated(it2->x,0.1,it2->z);
		glRotated(angleSidewise,0,1,0);
		//glRotated(angleElevation,0,0,1);

		// asphalt
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D,0);// asphalt 
		glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
		glBegin(GL_POLYGON); //road
		glTexCoord2d(legStart,0);			glVertex3d(legStart,it2->y,2);//it3->x - it2->x * 30/100
		glTexCoord2d(legStart,1); 			glVertex3d(legStart,it2->y,-2);
		glTexCoord2d(legStop * 30/100,1); 	glVertex3d(legStop,it3->y,-2);
		glTexCoord2d(legStop * 30/100,0); 	glVertex3d(legStop,it3->y,2);
		glEnd();

		if (legStop < r)
		{
			glPushMatrix();
				glTranslated(r,it3->y,0);
				glScaled(2.8,0.01,2.8);
				glBegin(GL_POLYGON);
				glutSolidSphere(1,20,20);
				//Field::DrawTSphere(20, 20,0,10,2);
				glEnd();
			glPopMatrix();
		}



		//--------
		//
		//it3 = it2;
		//++it3;
		//if(&(*it3) != &(vec[vec.size()-1]))
		//{
		//
		//	double r23 = sqrt( (it3->x-it2->x)*(it3->x-it2->x) + (it3->y-it2->y)*(it3->y-it2->y) + (it3->z-it2->z)*(it3->z-it2->z) );
		//
		//	double angleSidewiseFlip23 = (it2->z < it3->z) ? -1 : 1 ;//problam - right
		//	double angleSidewise23 = angleSidewiseFlip23*acos( (it3->x-it2->x)/r23 )*180/PI;
		//
		//	if (abs(angleSidewise - angleSidewise23) > 10)
		//	{
		//		glPushMatrix();
		//		glTranslated(r,it2->y,0);
		//		glScaled(2.8,0.01,2.8);
		//		glBegin(GL_POLYGON);
		//		glutSolidSphere(1,20,20);
		//		//Field::DrawTSphere(20, 20,0,10,2);
		//		glEnd();
		//		glPopMatrix();
		//	}
		//	else
		//	{
		//		// asphalt
		//		glEnable(GL_TEXTURE_2D);
		//		glBindTexture(GL_TEXTURE_2D,0);// asphalt 
		//		glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
		//		glBegin(GL_POLYGON); //road
		//		glTexCoord2d(0,0);				glVertex3d(0,it1->y,2);//it2->x - it1->x * 30/100
		//		glTexCoord2d(0,1); 				glVertex3d(0,it1->y,-2);
		//		glTexCoord2d(r * 30/100,1); 	glVertex3d(r,it2->y,-2);
		//		glTexCoord2d(r * 30/100,0); 	glVertex3d(r,it2->y,2);
		//		glEnd();
		//	}
		//}
		//else
		//{
		//	// asphalt
		//	glEnable(GL_TEXTURE_2D);
		//	glBindTexture(GL_TEXTURE_2D,0);// asphalt 
		//	glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_REPLACE);
		//	glBegin(GL_POLYGON); //road
		//	glTexCoord2d(0,0);				glVertex3d(0,it1->y,2);//it2->x - it1->x * 30/100
		//	glTexCoord2d(0,1); 				glVertex3d(0,it1->y,-2);
		//	glTexCoord2d(r * 30/100,1); 	glVertex3d(r,it2->y,-2);
		//	glTexCoord2d(r * 30/100,0); 	glVertex3d(r,it2->y,2);
		//	glEnd();
		//}
		//--------

		glDisable(GL_TEXTURE_2D);

		double polesGap = 6.5;

		switch ( this->roadType[leg] )
		{
		case 0://regular
		case 1://bridge
			//glBindTexture(GL_TEXTURE_2D,0);// asphalt - pillar/pole
			//glBindTexture(GL_TEXTURE_2D,1);// bricks - pillar/pole

			//draw poles:
			if (r<=polesGap)// place one in the middle
			{
				glPushMatrix();
				//glS(r/2,-0.02,0);
				glTranslated(r/2,-0.1,0);
				this->simCity->field->DrawTCilynder(8, 1, 1, polesGap/8, polesGap/4, (it2->y+it3->y)/2, -7);
				// use angleElevation to draw cylinder with a diagonal top.... DrawTCilynderDiag(...,angleElevation,..) 
				glPopMatrix();
			}
			else// place one every polesGap
			{
				//Point midPointTop(r/2,(it1->y+it2->y)/2,0);
				//Point midPointBot(r/2,-2,0);
				glPushMatrix();
				glTranslated(polesGap/2,-0.1,0);
				for (int i=0;	i<r/polesGap-1;	++i)
				{
					//it1->y + i*polesGap*sin(angleElevation)
					this->simCity->field->DrawTCilynder(8, 1, 1, polesGap/8, polesGap/4, (it2->y + (i+0.5)*polesGap*sin(angleElevation)), -7);
					// use angleElevation to draw cylinder with a diagonal top.... DrawTCilynderDiag(...,angleElevation,..) 
					glTranslated(polesGap,0,0);
				}
				glPopMatrix();
			}

			break;
		case 2://tunnel
			glBindTexture(GL_TEXTURE_2D,2);//window - enterance/exit to/from tunnel & cylinder-tunnel
			break;
		default:
			glBindTexture(GL_TEXTURE_2D,3);//roof - kaka
			break;
		}

		//glColor3d(0.6,0.6,0.6);// grey
		//glBegin(GL_POLYGON);
		//	glVertex2d(- ROAD_WIDTH/2,0);// left bottom
		//	glVertex2d(ROAD_WIDTH/2,0);// right bottom
		//	glVertex2d(ROAD_WIDTH/2,r);// right top
		//	glVertex2d(- ROAD_WIDTH/2,r);// left top
		//glEnd();
		//
		//glEnable(GL_LINE_SMOOTH);
		//glLineWidth(ROAD_WIDTH*0.2);
		//// sidelines
		//glColor3d(1,0.9,0);// yellow
		//glBegin(GL_LINES);
		//	glVertex2d(- ROAD_WIDTH/2 + (ROAD_WIDTH*0.12),0);// left bottom
		//	glVertex2d(- ROAD_WIDTH/2 + (ROAD_WIDTH*0.12),r);// left top
		//	glVertex2d(ROAD_WIDTH/2 - (ROAD_WIDTH*0.12),0);// right bottom
		//	glVertex2d(ROAD_WIDTH/2 - (ROAD_WIDTH*0.12),r);// right top
		//glEnd();
		//
		//// striplines
		//glColor3d(0.95,0.95,0.95);// white
		//glBegin(GL_LINES);
		//double stripesNum = r/(ROAD_WIDTH/2);
		//double spaceBetLines = (ROAD_WIDTH/2) * 0.2;
		//double lineLenght = (ROAD_WIDTH/2) * 0.8;
		//for (int i=0; i<stripesNum-1; i++)
		//{
		//	glVertex2d(0,0 + (spaceBetLines+lineLenght)*i);// left bottom
		//	glVertex2d(0, (spaceBetLines+lineLenght)*i + lineLenght );// left top
		//}
		//
		//glEnd();

		glPopMatrix();
	}

}

const double Road::ROAD_WIDTH = 0.12;

