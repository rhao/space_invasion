#include "coin.h"
#include "mainwindow.h"
#include <iostream>

Coin::Coin( QPixmap *pm, int nx, int ny, MainWindow *w ) : Thing( pm, nx, ny, w )
{
	count = 0;
	vX = 1; //keep same as background's v
	vY = 0;
}

void Coin::move()
{
	x = x - vX;
	if(x < 0)
	{
		//window->removeCoin(this);
	}
	this->setPos(x, y);
}

bool Coin::shouldRemove()
{
	if(x < -50)
	{
		return true;
	}
	return false;
}
