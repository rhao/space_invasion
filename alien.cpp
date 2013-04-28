#include "alien.h"
#include "mainwindow.h"

Alien::Alien( QPixmap *pm, int nx, int ny, MainWindow *w ) : Thing( pm, nx, ny, w )
{	
	//alien x velocity is a random number (to one decimal place) between 2 and 7
	vX = (double)((rand() % 50))/10 + 2;
	vY = 0;
}

void Alien::move()
{
	x = x - vX;
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

void Alien::handleCollision()
{

}

Alien::~Alien()
{

}
