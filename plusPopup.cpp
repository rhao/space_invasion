#include "plusPopup.h"
#include <iostream>
#include "mainwindow.h"

/**
 * Constructor
 *
 * @param p Pointer to the pixmap for the plus popup
 * @param w Pointer to the mainwindow
 * @return nothing
 */
PlusPopup::PlusPopup(QPixmap *p, MainWindow *w) : QGraphicsPixmapItem(*p)
{
	window = w;
	x = WINDOW_MAX_X/2 - 100;
	y = WINDOW_MAX_Y/2 - 50;
	c = 0;
	this->setPos(x, y);	
}

/**
 * Gets the x-coordinate of the popup.
 *
 * @return x The x-coordinate of the popup.
 */
int PlusPopup::getX()
{
	return x;
}

/**
 * Gets the y-coordinate of the popup.
 *
 * @return y The y-coordiante of the popup.
 */
int PlusPopup::getY()
{
	return y;
}

/**
 * Gets the counter variable which represents how many clock cycles the popup has existed.
 *
 * @return c The count variable
 */
int PlusPopup::getC()
{
	return c;
}

/**
 * Increments the count variable.
 *
 * @return nothing
 */
void PlusPopup::incrementC()
{
	c++;
}

/**
 * Destructor
 *
 * @return nothing
 */
PlusPopup::~PlusPopup()
{

}
