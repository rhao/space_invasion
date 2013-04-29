#include "background.h"
#include <iostream>

/**
 * Constructor
 *
 * @param p Pointer to a pixmap that represents the image of the background of the game
 * @param x_ The x-coordinate of the background
 * @param y_ The y-coordinate of the background
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
 * Gets the x-coordinate of the background.
 *
 * @return x The x-coordinate of the background
 */
int Background::getX()
{
	return x;
}

/**
 * Gets the y-coordinate of the backround.
 *
 * @return y The y-coordiante of the background
 */
int Background::getY()
{
	return y;
}

/**
 * Adjusts the x-coordinate to allow the background to scroll with a velocity and
 * mimick what it would look like if the player were moving forward.
 *
 * @param window_x_min The left-hand side of the window
 * @param window_x_max The right-hand side of the window
 * @return nothing
 */
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
