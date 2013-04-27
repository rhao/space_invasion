#include "background.h"
#include <iostream>

/**
 * Constructor
 *
 * @param w Pointer to the mainwindow
 * @return nothing
 */
Background::Background(QPixmap *p, int x_, int y_) : QGraphicsPixmapItem(*p)
{
	x = x_;
	y = y_;
	v = 1;
	this->setPos(x, y);
}

/**
 * Gets the x-coordinate of the tile.
 *
 * @return x The x-coordinate of the tile
 */
int Background::getX()
{
	return x;
}

/**
 * Gets the y-coordinate of the tile.
 *
 * @return y The y-coordiante of the tile
 */
int Background::getY()
{
	return y;
}

void Background::scroll(int window_x_min, int window_x_max)
{
	if(x + window_x_max < window_x_min)
	{
		x = window_x_max;
	}
	else
	{
		x = x - v;
	}
	this->setPos(x, y);
}

/**
 * Destructor
 *
 * @return nothing
 */
Background::~Background()
{

}
