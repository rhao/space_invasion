#include "alien.h"
#include "mainwindow.h"

Alien::Alien( QPixmap *pm, int nx, int ny, MainWindow *w ) : Thing( pm, nx, ny, w )
{
	vX = 3; //keep same as background's v
	vY = 0;
}

void Alien::move()
{
	x = x - vX;
	if(x < 0)
	{
		//window->removeCoin(this);
	}
	this->setPos(x, y);
}

bool Alien::shouldRemove()
{
	if(x < -50)
	{
		return true;
	}
	return false;
}

Alien::~Alien()
{

}
