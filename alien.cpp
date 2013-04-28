#include "alien.h"
#include "mainwindow.h"

Alien::Alien( QPixmap *pm, int nx, int ny, MainWindow *w ) : Thing( pm, nx, ny, w )
{
/*
	int vRand = rand() % 5;
	if(vRand <= 1)
	{
		vX = 3;
	}
	else if(vRand <= 3)
	{
		vX = 4;
	}
	else
	{
		vX=5;
	}
	*/
	
	vX = (double)((rand() % 100))/100 + 3;
	std::cout<<vX<<" ";
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
