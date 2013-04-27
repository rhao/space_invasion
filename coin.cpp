#include "coin.h"
#include "mainwindow.h"

Coin::Coin( QPixmap *pm, int nx, int ny, MainWindow *w ) : Thing( pm, nx, ny, w )
{
	vX = 3; //keep same as background's v
	vY = 1;
}

void Coin::move()
{
	x = x - vX;
	y = y + vY;
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
