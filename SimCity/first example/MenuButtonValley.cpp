#include "MenuButtonValley.h"

#include "SimCity.h"

//MenuButtonTree::MenuButtonValley(void)
//{
//}


MenuButtonValley::~MenuButtonValley(void)
{
}


void MenuButtonValley::action(Point& p)
{

	int i,j,r=10;
	double dist,alpha,ca,h;
	double red,green,blue;
	Point p1(p.x+Field::GSIZE/2, p.y, -p.z+Field::GSIZE/2);

	for(i=p1.z-r+1; i<p1.z+r; i++)
	{
		for(j=p1.x-r+1; j<p1.x+r; j++)
		{
			if(i>0 && i<Field::GSIZE && j>=0 && j<Field::GSIZE)	// in field ranges
			{
				dist = sqrt(double(p1.x-j)*(p1.x-j)+(p1.z-i)*(p1.z-i));
				if(dist<r)	// in circle
				{
					ca = dist/r;
					alpha = acos(ca);
					h = (double)r*sin(alpha)*(1.0/10.0)*0.1;
					
					this->simCity->field->grid[i][j] -= h;
					
					if (dist==0)cout<<this->simCity->field->grid[i][j]<<endl;

				}
			}
		}
	}

}