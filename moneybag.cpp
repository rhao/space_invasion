#include "moneybag.h"
#include "mainwindow.h"

MoneyBag::MoneyBag( QPixmap *pm, int nx, int ny, MainWindow *w ) : Thing( pm, nx, ny, w )
{
	vX = 3;
	vY = 4;
}

void MoneyBag::move()
{
	int miny = window->game_min_y;
	int maxy = window->game_max_y;
	x = x - vX;
	y = y - vY;
	maxy -= 40;
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

bool MoneyBag::shouldRemove()
{
	if(x < -50)
	{
		return true;
	}
	return false;
}
