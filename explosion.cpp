#include "explosion.h"
#include <iostream>
#include "mainwindow.h"

/**
 * Constructor
 *
 * @param w Pointer to the mainwindow
 * @return nothing
 */
Explosion::Explosion(QPixmap *p, MainWindow *w) : QGraphicsPixmapItem(*p)
{
	window = w;
	x = window->getPlayerX() - 80;
	y = window->getPlayerY() - 80;
	c = 0;
	this->setPos(x, y);	
}

/**
 * Gets the x-coordinate of the tile.
 *
 * @return x The x-coordinate of the tile
 */
int Explosion::getX()
{
	return x;
}

/**
 * Gets the y-coordinate of the tile.
 *
 * @return y The y-coordiante of the tile
 */
int Explosion::getY()
{
	return y;
}

int Explosion::getC()
{
	return c;
}

void Explosion::incrementC()
{
	c++;
}

/**
 * Destructor
 *
 * @return nothing
 */
Explosion::~Explosion()
{

}
