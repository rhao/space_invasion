#include "player.h"
#include "mainwindow.h"

/**
 * Constructor
 *
 * @param w Pointer to the mainwindow
 * @return nothing
 */
Player::Player(MainWindow *w)
{
	window = w;
	x = 80;
}

/**
 * Function is called every time a tile is clicked.
 *
 * @param e Mouse event
 * @return nothing
 */
void Player::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
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

void Player::move(bool dir)
{
	//move up
	if(dir == 0)
	{
		y += v;
	}
	//move down
	else
	{
		y -= v;
	}
}

/**
 * Destructor
 *
 * @return nothing
 */
Player::~Player()
{

}
