#include "moneybag.h"
#include "mainwindow.h"

MoneyBag::MoneyBag( QPixmap *pm, int nx, int ny, MainWindow *w ) : Thing( pm, nx, ny, w )
{
	//money bag x velocity is between 2 and 5
	vX = (double)((rand() % 30))/10 + 2;
	//money bag y velocity is between 3 and 7
	vY = (double)((rand() % 40))/10 + 3;
}

void MoneyBag::move()
{
	int miny = window->game_min_y;
	int maxy = window->game_max_y;
	x = x - vX;
	y = y - vY;
	maxy -= window->moneybagHeight;
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

void MoneyBag::handleCollision()
{

}

MoneyBag::~MoneyBag()
{

}
