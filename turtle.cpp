#include "turtle.h"
#include "mainwindow.h"
Turtle::Turtle( QPixmap *pm, int nx, int ny, MainWindow *w ) : Thing( pm, nx, ny, w )
{
	vX = 1;
	vY = 0;
}

void Turtle::move()
{
	int miny = window->game_min_y;
	int maxy = window->game_max_y;
	x = x - vX;
	this->setPos(x, y);
}

bool Turtle::shouldRemove()
{
	if(x < -50)
	{
		return true;
	}
	return false;
}
