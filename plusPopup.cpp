#include "plusPopup.h"
#include <iostream>
#include "mainwindow.h"

/**
 * Constructor
 *
 * @param w Pointer to the mainwindow
 * @return nothing
 */
PlusPopup::PlusPopup(QPixmap *p, MainWindow *w) : QGraphicsPixmapItem(*p)
{
	window = w;
	x = WINDOW_MAX_X/2 - 100;
	y = WINDOW_MAX_Y/2 - 50;
	this->setPos(x, y);	
}

/**
 * Gets the x-coordinate of the tile.
 *
 * @return x The x-coordinate of the tile
 */
int PlusPopup::getX()
{
	return x;
}

/**
 * Gets the y-coordinate of the tile.
 *
 * @return y The y-coordiante of the tile
 */
int PlusPopup::getY()
{
	return y;
}

/**
 * Destructor
 *
 * @return nothing
 */
PlusPopup::~PlusPopup()
{

}
