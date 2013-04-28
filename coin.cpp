#include "coin.h"
#include "mainwindow.h"

Coin::Coin( QPixmap *pm, int nx, int ny, MainWindow *w) : Thing( pm, nx, ny, w )
{
	//coin y velocity is either -1 or +1
	vX = 3;
	int vRand = rand() % 2;
	if(vRand == 1)
	{
		vY = 1;
	}
	else if(vRand == 0)
	{
		vY = -1;
	}
}

void Coin::move()
{
	int miny = window->game_min_y;
	//coins fall off bottom of screen, bounce off top
	if(y < miny)
	{
		y = miny;
		vY = -vY;
	}
	else
	{
		y = y + vY;
	}
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

void Coin::handleCollision()
{
	int s = window->score;
	s += 10;
	window->setScore(s);
}

bool Coin::isACoin()
{
	return true;
}

Coin::~Coin()
{

}
