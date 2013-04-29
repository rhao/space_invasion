#include "player.h"
#include <iostream>
#include "mainwindow.h"

/**
 * Constructor
 *
 * @param p Pointer to a pixmap for the player
 * @param w Pointer to the mainwindow
 * @return nothing
 */
Player::Player(QPixmap *p, MainWindow *w) : QGraphicsPixmapItem(*p)
{
	x = 250;
	y = 400;
	v = 5;
	this->setPos(x, y);
	window = w;
}

/**
 * Sets the player's y-coordinate. There is no setX because the player can only move vertically.
 *
 * @param y_ The new y-coordinate
 * @return nothing
 */
void Player::setY(int y_)
{
	y = y_;
}

/**
 * Sets the value of the velocity of the player, or the amount to move the player every
 * time move is called.
 *
 * @param o The number of pixels the pl.yer should move each time move is called
 * @return nothing
 */
void Player::setV(int v_)
{
	v = v_;
}

/**
 * Gets the x-coordinate of the player.
 *
 * @return x The x-coordinate of the player.
 */
int Player::getX()
{
	return x;
}

/**
 * Gets the y-coordinate of the player.
 *
 * @return y The y-coordiante of the player.
 */
int Player::getY()
{
	return y;
}

/**
 * Returns the velocity of the player.
 *
 * @return v The velocity of the player.
 */
int Player::getV()
{
	return v;
}

/**
 * Moves the player up by subtracting the velocity from the y-coordinate. If the player is at
 * the top of the screen, the player cannot move higher and will remain there until the
 * player is moved down.
 *
 * @param window_min The y-coordinate of the top of the game area.
 * @return nothing
 */
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

/**
 * Moves the player down by adding the velocity to the y-coordinate. If the player is at
 * the bottom of the screen, the player cannot move down and will remain there until the
 * player is moved up.
 *
 * @param window_max The y-coordinate of the bottom of the game area.
 * @return nothing
 */
void Player::moveDown(int window_max)
{
	//std::cout<<"y: " <<y <<", max: " <<window_max;
	if(y + v + window->playerHeight > window_max)
	{
		y = window_max - window->playerHeight;
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
