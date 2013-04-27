#include "player.h"
#include <iostream>

/**
 * Constructor
 *
 * @param w Pointer to the mainwindow
 * @return nothing
 */
Player::Player(QPixmap *p) : QGraphicsPixmapItem(*p)
{
	x = 250;
	y = 400;
	v = 1;
	this->setPos(x, y);
}

/**
 * Sets the GUI tile's y-coordinate.
 *
 * @param y_ The new y-coordinate
 * @return nothing
 */
void Player::setY(int y_)
{
	y = y_;
}

/**
 * Sets the value of the offset from the x and y-coordinates for the number to be printed at.
 *
 * @param o The number of pixels the number should be from the upper left corner of the tile
 * @return nothing
 */
void Player::setV(int v_)
{
	v = v_;
}

/**
 * Gets the x-coordinate of the tile.
 *
 * @return x The x-coordinate of the tile
 */
int Player::getX()
{
	return x;
}

/**
 * Gets the y-coordinate of the tile.
 *
 * @return y The y-coordiante of the tile
 */
int Player::getY()
{
	return y;
}

int Player::getV()
{
	return v;
}

void Player::moveUp(int window_min)
{
	if(y - v < window_min)
	{
		y = window_min;
	}
	else
	{
		y -= v;
	}
	this->setPos(x, y);
}

void Player::moveDown(int window_max)
{
	//std::cout<<"y: " <<y <<", max: " <<window_max;
	if(y + v + 105 > window_max)
	{
		y = window_max - 105;
	}
	else
	{
		y += v;
	}
	this->setPos(x, y);
}

/**
 * Destructor
 *
 * @return nothing
 */
Player::~Player()
{

}
