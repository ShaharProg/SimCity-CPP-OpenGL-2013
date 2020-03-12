#include "MenuButtonCity.h"
#include "SimCity.h"


//MenuButtonCity::MenuButtonCity(void)
//{
//}


MenuButtonCity::~MenuButtonCity(void)
{
}



void MenuButtonCity::action(Point& p)
{
	Point p1, p12, p2, p23, p3, p34, p4, p41;
	int left,right,top,bottom;

	left =	(int)p.x-B_SIZE +Field::GSIZE/2-1;
	right =	(int)left + 2*B_SIZE;

	top =	(int)-(p.z+B_SIZE) +Field::GSIZE/2-1;
	bottom =	(int)top + 2*B_SIZE;

	// check and fix boundries:
	if (left < 5)
	{
		left	=	5;
		right	=	left + 2*B_SIZE -1;
		p.x = -Field::GSIZE/2 + 5 + B_SIZE;
	}
	else if (right > Field::GSIZE-1 -5)
	{
		right	=	Field::GSIZE-1 -5;
		left	=	right	- (2*B_SIZE-1);
		p.x = Field::GSIZE/2 - B_SIZE-1 -5;
	}

	if (top < 5)
	{
		top	=	5;
		bottom	=	top + 2*B_SIZE -1;
		p.z = Field::GSIZE/2 - B_SIZE -5;
	}
	else if (bottom > Field::GSIZE-1 -5)
	{
		bottom	=	Field::GSIZE-1 -5;
		top	=	bottom - (2*B_SIZE-1);
		p.z = -Field::GSIZE/2 + B_SIZE-1 +5;
	}


	// check and fix ground:
	double h;
	h = (p.y > 0.1) ? p.y : 0.1;
	for (int i=top-1;	i<=bottom+1;	++i)
	{
		for (int j=left-1;	j<=right+1;	++j)
		{
			//h = this->simCity->field->grid[i][j];
			//this->simCity->field->grid[i][j] = (h<0.1) ? 0.1 : h;
			this->simCity->field->grid[i][j] = h;
		}
	}




	//p = Point(left+B_SIZE-Field::GSIZE/2+1, -(bottom+B_SIZE-Field::GSIZE/2+1));
	//p.y = simCity->field->grid[bottom+B_SIZE][left+B_SIZE];

	p1 = Point(p.x - B_SIZE, p.z + B_SIZE);
	//p1.y = simCity->field->grid[top][left];
	p1.y = p.y;

	p12 = Point(p.x, p.z + B_SIZE);
	//p12.y = simCity->field->grid[top][left+B_SIZE];
	p12.y =p.y;

	p2 = Point(p.x + B_SIZE, p.z + B_SIZE);
	//p2.y = simCity->field->grid[top][right];
	p2.y = p.y;

	p23 = Point(p.x + B_SIZE, p.z);
	//p23.y = simCity->field->grid[bottom+B_SIZE][right];
	p23.y = p.y;

	p3 = Point(p.x + B_SIZE, p.z - B_SIZE);
	//p3.y = simCity->field->grid[bottom][right];
	p3.y = p.y;

	p34 = Point(p.x, p.z - B_SIZE);
	//p34.y = simCity->field->grid[bottom][left+B_SIZE];
	p34.y =p.y;

	p4 = Point(p.x - B_SIZE, p.z - B_SIZE);
	//p4.y = simCity->field->grid[bottom][left];
	p4.y = p.y;

	p41 = Point(p.x - B_SIZE, p.z);
	//p41.y = simCity->field->grid[bottom+B_SIZE][left];
	p41.y =p.y;

	// rand buildings
	vector<Point> randHousesFromHere;
	randHousesFromHere.push_back(p4);
	randHousesFromHere.push_back(p34);
	randHousesFromHere.push_back(p41);
	randHousesFromHere.push_back(p);

	int x_pos, z_pos;
	double y_pos;

	Point h1,h2;
	Point p_up1,p_up2,p_right1,p_right2,p_left1,p_left2,p_down1,p_down2;

	for (int i=0; i<randHousesFromHere.size(); ++i)
	{
		// menuButtons.at(4) == house button

		x_pos = rand() % (B_SIZE-8) + randHousesFromHere[i].x +4;
		z_pos = rand() % (B_SIZE-8) + randHousesFromHere[i].z +4;
		//y_pos = this->simCity->field->grid[-z_pos + Field::GSIZE/2 -1][x_pos + Field::GSIZE/2 -1];
		y_pos = p.y;
		this->simCity->menu->menuButtons.at(4)->action(Point(x_pos, y_pos, z_pos));
		h1 = Point(x_pos, y_pos, z_pos);

		x_pos = rand() % (B_SIZE-8) + randHousesFromHere[i].x +4;
		z_pos = rand() % (B_SIZE-8) + randHousesFromHere[i].z +4;
		//y_pos = this->simCity->field->grid[-z_pos + Field::GSIZE/2 -1][x_pos + Field::GSIZE/2 -1];
		y_pos = p.y;
		this->simCity->menu->menuButtons.at(4)->action(Point(x_pos, y_pos, z_pos));
		h2 = Point(x_pos, y_pos, z_pos);

		//h1.x += 1; 1 means house radius... not necessarily accurate


		if (h1.x < h2.x)
		{
			swap(h1,h2);
		}


		switch (i)
		{
		case 2://top left area

				p_up1 = Point(p.x,h1.z);
				//p_up1.y = simCity->field->grid[(int)-(p_up1.z) +Field::GSIZE/2-1][(int)(p_up1.x) +Field::GSIZE/2-1];
				p_up1.y = p.y;
				//(int)-(p.z+B_SIZE) +Field::GSIZE/2-1;
				//h1.x += 1;
				this->simCity->menu->menuButtons.at(1)->action(h1);
				this->simCity->menu->menuButtons.at(1)->action(p_up1);
				this->simCity->menu->menuButtons.at(1)->actionRight(p);
					
				p_left2 = Point(h2.x,p.z);
				//p_left2.y = simCity->field->grid[(int)-(p_left2.z) +Field::GSIZE/2-1][(int)(p_left2.x) +Field::GSIZE/2-1];
				p_left2.y =p.y;
				//h2.z -= 1;
				this->simCity->menu->menuButtons.at(1)->action(h2);
				this->simCity->menu->menuButtons.at(1)->action(p_left2);
				this->simCity->menu->menuButtons.at(1)->actionRight(p);
			break;
			
		case 3://top right area

				p_up2 = Point(p.x,h2.z);
				//p_up2.y = simCity->field->grid[(int)-(p_up2.z) +Field::GSIZE/2-1][(int)(p_up2.x) +Field::GSIZE/2-1];
				p_up2.y = p.y;
				//h2.x -= 1;
				this->simCity->menu->menuButtons.at(1)->action(h2);
				this->simCity->menu->menuButtons.at(1)->action(p_up2);
				this->simCity->menu->menuButtons.at(1)->actionRight(p);
					
				p_right2 = Point(h1.x,p.z);
				//p_right2.y = simCity->field->grid[(int)-(p_right2.z) +Field::GSIZE/2-1][(int)(p_right2.x) +Field::GSIZE/2-1];
				p_right2.y = p.y;
				//h1.z -= 1;
				this->simCity->menu->menuButtons.at(1)->action(h1);
				this->simCity->menu->menuButtons.at(1)->action(p_right2);
				this->simCity->menu->menuButtons.at(1)->actionRight(p);
			break;
			
		case 0://bottom left area

				p_down1 = Point(p.x,h1.z);
				//p_down1.y = simCity->field->grid[(int)-(p_down1.z) +Field::GSIZE/2-1][(int)(p_down1.x) +Field::GSIZE/2-1];
				p_down1.y = p.y;
				//h1.x += 1;
				this->simCity->menu->menuButtons.at(1)->action(h1);
				this->simCity->menu->menuButtons.at(1)->action(p_down1);
				this->simCity->menu->menuButtons.at(1)->actionRight(p);
					
				p_left1 = Point(h2.x,p.z);
				//p_left1.y = simCity->field->grid[(int)-(p_left1.z) +Field::GSIZE/2-1][(int)(p_left1.x) +Field::GSIZE/2-1];
				p_left1.y = p.y;
				//h2.z += 1;
				this->simCity->menu->menuButtons.at(1)->action(h2);
				this->simCity->menu->menuButtons.at(1)->action(p_left1);
				this->simCity->menu->menuButtons.at(1)->actionRight(p);
			break;
			
		case 1://bottom right area

				p_down2 = Point(p.x,h2.z);
				//p_down2.y = simCity->field->grid[(int)-(p_down2.z) +Field::GSIZE/2-1][(int)(p_down2.x) +Field::GSIZE/2-1];
				p_down2.y = p.y;
				//h2.x += 1;
				this->simCity->menu->menuButtons.at(1)->action(h2);
				this->simCity->menu->menuButtons.at(1)->action(p_down2);
				this->simCity->menu->menuButtons.at(1)->actionRight(p);
					
				p_right1 = Point(h1.x,p.z);
				//p_right1.y = simCity->field->grid[(int)-(p_right1.z) +Field::GSIZE/2-1][(int)(p_right1.x) +Field::GSIZE/2-1];
				p_right1.y = p.y;
				//h1.z -= 1;
				this->simCity->menu->menuButtons.at(1)->action(h1);
				this->simCity->menu->menuButtons.at(1)->action(p_right1);
				this->simCity->menu->menuButtons.at(1)->actionRight(p);
			break;
		}


		// menuButtons.at(0) == tree button

		x_pos = rand() % (B_SIZE-8) + randHousesFromHere[i].x +4;
		z_pos = rand() % (B_SIZE-8) + randHousesFromHere[i].z +4;
		//y_pos = this->simCity->field->grid[-z_pos + Field::GSIZE/2 -1][x_pos + Field::GSIZE/2 -1];
		y_pos = p.y;
		this->simCity->menu->menuButtons.at(0)->action(Point(x_pos, y_pos, z_pos));

		x_pos = rand() % (B_SIZE-8) + randHousesFromHere[i].x +4;
		z_pos = rand() % (B_SIZE-8) + randHousesFromHere[i].z +4;
		//y_pos = this->simCity->field->grid[-z_pos + Field::GSIZE/2 -1][x_pos + Field::GSIZE/2 -1];
		y_pos = p.y;
		this->simCity->menu->menuButtons.at(0)->action(Point(x_pos, y_pos, z_pos));

		x_pos = rand() % (B_SIZE-8) + randHousesFromHere[i].x +4;
		z_pos = rand() % (B_SIZE-8) + randHousesFromHere[i].z +4;
		//y_pos = this->simCity->field->grid[-z_pos + Field::GSIZE/2 -1][x_pos + Field::GSIZE/2 -1];
		y_pos = p.y;
		this->simCity->menu->menuButtons.at(0)->action(Point(x_pos, y_pos, z_pos));

		x_pos = rand() % (B_SIZE-8) + randHousesFromHere[i].x +4;
		z_pos = rand() % (B_SIZE-8) + randHousesFromHere[i].z +4;
		y_pos = p.y;
		//y_pos = this->simCity->field->grid[-z_pos + Field::GSIZE/2 -1][x_pos + Field::GSIZE/2 -1];
		this->simCity->menu->menuButtons.at(0)->action(Point(x_pos, y_pos, z_pos));

	}



	if (p_up1.z > p_up2.z)		swap(p_up1,p_up2);
	if (p_down1.z < p_down2.z)	swap(p_down1,p_down2);
	if (p_right1.x > p_right2.x)swap(p_right1,p_right2);
	if (p_left1.x < p_left2.x)	swap(p_left1,p_left2);


	// create streets:		demonstrates mouse clicks when Road button is selected (menu button #1 means Road)
	this->simCity->menu->menuButtons.at(1)->action(p1);
	this->simCity->menu->menuButtons.at(1)->action(p12);
	this->simCity->menu->menuButtons.at(1)->action(p2);
	this->simCity->menu->menuButtons.at(1)->action(p23);
	this->simCity->menu->menuButtons.at(1)->action(p3);
	this->simCity->menu->menuButtons.at(1)->action(p34);
	this->simCity->menu->menuButtons.at(1)->action(p4);
	this->simCity->menu->menuButtons.at(1)->action(p41);
	this->simCity->menu->menuButtons.at(1)->action(p1);
	this->simCity->menu->menuButtons.at(1)->actionRight(p);

	this->simCity->menu->menuButtons.at(1)->action(p12);
	this->simCity->menu->menuButtons.at(1)->action(p_up1);
	this->simCity->menu->menuButtons.at(1)->action(p_up2);
	this->simCity->menu->menuButtons.at(1)->action(p);
	this->simCity->menu->menuButtons.at(1)->action(p_right1);
	this->simCity->menu->menuButtons.at(1)->action(p_right2);
	this->simCity->menu->menuButtons.at(1)->action(p23);
	this->simCity->menu->menuButtons.at(1)->actionRight(p);

	this->simCity->menu->menuButtons.at(1)->action(p41);
	this->simCity->menu->menuButtons.at(1)->action(p_left1);
	this->simCity->menu->menuButtons.at(1)->action(p_left2);
	this->simCity->menu->menuButtons.at(1)->action(p);
	this->simCity->menu->menuButtons.at(1)->action(p_down1);
	this->simCity->menu->menuButtons.at(1)->action(p_down2);
	this->simCity->menu->menuButtons.at(1)->action(p34);
	this->simCity->menu->menuButtons.at(1)->actionRight(p);


	vector<Point> currentCityCorner;
	currentCityCorner.push_back(p1);
	currentCityCorner.push_back(p2);
	currentCityCorner.push_back(p3);
	currentCityCorner.push_back(p4);

	int iMin,jMin;
	double dist = Field::GSIZE, curDist;
	if (prevCityCorners.size() > 0)
	{
		for (int i=0; i<4; ++i)
		{
			for (int j=0; j<4; ++j)
			{
				curDist = sqrt( (prevCityCorners[j].x-currentCityCorner[i].x)*(prevCityCorners[j].x-currentCityCorner[i].x) +  (prevCityCorners[j].z-currentCityCorner[i].z)*(prevCityCorners[j].z-currentCityCorner[i].z) );
				if (curDist < dist )
				{
					dist = curDist;
					iMin = i;
					jMin = j;
				}
			} 
		}
		this->simCity->menu->menuButtons.at(1)->action(prevCityCorners[jMin]);
		this->simCity->menu->menuButtons.at(1)->action(currentCityCorner[iMin]);
		this->simCity->menu->menuButtons.at(1)->actionRight(p);
	}

	prevCityCorners = currentCityCorner;
}


//void seaToGround(Point& p)
