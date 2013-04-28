#include "turtle.h"
#include "mainwindow.h"
Turtle::Turtle( QPixmap *pm, int nx, int ny, MainWindow *w ) : Thing( pm, nx, ny, w )
{
	vX = 2;
	vY = 0;
}

void Turtle::move()
{
	x = x - vX;
	this->setPos(x, y);
}

bool Turtle::shouldRemove()
{
	if(x < -100)
	{
		return true;
	}
	return false;
}

void Turtle::handleCollision()
{
	//window->slowTimer();
	window->turtleBool = true;
}

bool Turtle::isACoin()
{
	return false;
}

Turtle::~Turtle()
{

}
