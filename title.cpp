#include "title.h"
#include <iostream>

/**
 * Constructor
 *
 * @param w Pointer to the mainwindow
 * @return nothing
 */
Title::Title(QPixmap *p) : QGraphicsPixmapItem(*p)
{
	x = 50;
	y = 200;
	this->setPos(x, y);
}

/**
 * Gets the x-coordinate of the tile.
 *
 * @return x The x-coordinate of the tile
 */
int Title::getX()
{
	return x;
}

/**
 * Gets the y-coordinate of the tile.
 *
 * @return y The y-coordiante of the tile
 */
int Title::getY()
{
	return y;
}

/**
 * Destructor
 *
 * @return nothing
 */
Title::~Title()
{

}
