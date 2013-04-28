#include "doctor.h"
#include "mainwindow.h"

Doctor::Doctor( QPixmap *pm, int nx, int ny, MainWindow *w ) : Thing( pm, nx, ny, w )
{
	//doctor x velocity is between 2 and 5
	vX = (double)((rand() % 30))/10 + 2;
	//doctor yvelocity is either 5 or -5
	
	int vRand = rand() % 2;
	if(vRand == 1)
	{
		vY = 5;
	}
	else if(vRand == 0)
	{
		vY = -5;
	}
	cout<<vX<<", " <<vY <<" ";
}

void Doctor::move()
{
	int miny = window->game_min_y;
	int maxy = window->game_max_y;
	x = x - vX;
	y = y - vY;
	maxy -= 60;
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
