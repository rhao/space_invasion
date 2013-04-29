#include "title.h"
#include <iostream>

/**
 * Constructor
 *
 * @param p The pixmap for the title
 * @param x_ The x-coordinate of the title
 * @param y_ The y-coordinate of the title
 * @return nothing
 */
Title::Title(QPixmap *p, int x_, int y_) : QGraphicsPixmapItem(*p)
{
	x = x_;
	y = y_;
	this->setPos(x, y);
}

/**
 * Gets the x-coordinate of the title.
 *
 * @return x The x-coordinate of the title
 */
int Title::getX()
{
	return x;
}

/**
 * Gets the y-coordinate of the title.
 *
 * @return y The y-coordiante of the title
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
