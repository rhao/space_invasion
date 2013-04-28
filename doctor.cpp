#include "doctor.h"
#include "mainwindow.h"

Doctor::Doctor( QPixmap *pm, int nx, int ny, MainWindow *w ) : Thing( pm, nx, ny, w )
{
	//doctor x velocity is between 2 and 4
	vX = (double)((rand() % 20))/10 + 2;
	//doctor yvelocity is either 4 or -4
	int vRand = rand() % 2;
	if(vRand == 1)
	{
		vY = 4;
	}
	else if(vRand == 0)
	{
		vY = -4;
	}
}

void Doctor::move()
{
	int miny = window->game_min_y;
	int maxy = window->game_max_y;
	x = x - vX;
	y = y - vY;
	maxy -= window->doctorHeight;
	if(y < miny)
	{
		y = miny;
		vY = -vY;
	}
	else if(y > maxy)
	{
		y = maxy;
		vY = -vY;
	}
	this->setPos(x, y);
}

bool Doctor::shouldRemove()
{
	if(x < -50)
	{
		return true;
	}
	return false;
}

void Doctor::handleCollision()
{
	window->increaseLives();
}

bool Doctor::isACoin()
{
	return false;
}

Doctor::~Doctor()
{

}
