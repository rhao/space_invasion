#include "explosion.h"
#include <iostream>
#include "mainwindow.h"

/**
 * Constructor
 *
 * @param p The pixmap image of the explosion
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
 * Gets the x-coordinate of the explosion.
 *
 * @return x The x-coordinate of the explosion.
 */
int Explosion::getX()
{
	return x;
}

/**
 * Gets the y-coordinate of the explosion.
 *
 * @return y The y-coordiante of the explosion.
 */
int Explosion::getY()
{
	return y;
}

/**
 * Gets the counter value of the explosion, which helps determine how long the explosion
 * should exist.
 *
 * @return c The counter variable
 */
int Explosion::getC()
{
	return c;
}

/**
 * Increments the count of the explosion. Explosions only last for a certain amount of
 * time before they disappear, so the count is a way to keep track of when to 
 * remove the explosion.
 *
 * @return nothing
 */
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
