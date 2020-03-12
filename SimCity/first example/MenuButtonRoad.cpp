#include "MenuButtonRoad.h"

#include "SimCity.h"

#define MIN_RADIUS 2

//MenuButtonRoad::MenuButtonRoad(void)
//{
//}


MenuButtonRoad::~MenuButtonRoad(void)
{
}

void MenuButtonRoad::action(Point& p)
{
	Vertex* ver;
	int i;

	p.y = (p.y < 0.1) ? 0.1 : p.y;

	for (i=0;	i< this->simCity->field->g.size();	++i)
	{
		ver = this->simCity->field->g[i];

		double r = sqrt(	(ver->p.x-p.x)*(ver->p.x-p.x) + (ver->p.z-p.z)*(ver->p.z-p.z)	);
		if ( r < MIN_RADIUS )
		{
			// reuse vertex
			p = ver->p; // copy the exact location
			break;
		}
	}

	if ( i >= this->simCity->field->g.size() )
	{
		//existing = NULL;

		ver = new Vertex();
		ver->p			= p;
		ver->neighbors	= Graph();

		this->simCity->field->g.push_back(ver);
	}
	//


	if (this->road)
	{
		if (this->road->vec.size() == 1)	// click #2, create first leg (2 points)
		{
			*(this->road) += p;
			this->simCity->field->addFieldObject((FieldObject*)(this->road));
		}
		else								// click #3+, continue creating more legs
		{
			*(this->road) += p;
		}

		// handshake
		this->lastVertex->neighbors.push_back(ver);
		ver->neighbors.push_back(this->lastVertex);
	}
	else
	{
		this->road = new Road(p,this->simCity);			// click #1
	}
	//vec this->simCity->field->fieldObjects.end();

	//this->simCity->field->addFieldObject((FieldObject*)(new Road(*p)));
	//glPushMatrix();
	//	glTranslated(p->x,p->y,0);
	//	glScaled(0.1,0.1,1);
	//	DrawRoad(0.6,0);
	//glPopMatrix();

	
	this->lastVertex = ver;
}


void MenuButtonRoad::actionRight(Point& p)
{
	this->road = NULL;
}


