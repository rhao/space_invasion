#include "doctor.h"
#include "mainwindow.h"

Doctor::Doctor( QPixmap *pm, int nx, int ny, MainWindow *w ) : Thing( pm, nx, ny, w )
{
	vX = 3; //keep same as background's v
	vY = 5;
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
