#include "moneybag.h"
#include "mainwindow.h"

/**
 * Constructor which calls the constructor of Thing as well
 *
 * @param pm The pixmap image of the money bag
 * @param nx The x-coordiate to be assigned
 * @param ny The y-coordinate to be assigned
 * @param w A pointer to the main window
 * @return nothing
 */
MoneyBag::MoneyBag( QPixmap *pm, int nx, int ny, MainWindow *w ) : Thing( pm, nx, ny, w )
{
	//money bag x velocity is between 2 and 5
	vX = (double)((rand() % 30))/10 + 2;
	//money bag y velocity is between 3 and 7
	vY = (double)((rand() % 40))/10 + 3;
}

/**
 * Moves the alien by changing the x-coordinate and y-coordinate by the velocity. Money bags
 * bounce off the top and bottom of the screen.
 *
 * @return nothing
 */
void MoneyBag::move()
{
	int miny = window->game_min_y;
	int maxy = window->game_max_y;
	x = x - vX;
	y = y - vY;
	maxy -= window->moneybagHeight;
	if(y < miny)
	{
		y = miny;
		vY = -vY;
	}
	else if(y > maxy)
	{
		y = maxy;
		vY = -vY;
	}
	this->setPos(x, y);
}

/**
 * Returns true is the money bag is off the screen and should be removed, false otherwise.
 *
 * @return bool True if object is off screen, otherwise false
 */
bool MoneyBag::shouldRemove()
{
	if(x < -100)
	{
		return true;
	}
	return false;
}

/**
 * This function gets called after the player collides with a money bag. Money bags increase
 * the player's score by fifty, and prevents the player from interacting with any object
 * except for coins. The player's size will grow throughout the duration the player is invincible.
 *
 * @return nothing
 */
void MoneyBag::handleCollision()
{
	int s = window->score;
	s += 50;
	window->setScore(s);
	window->invincible = true;
}

/**
 * Returns false because a money bag is not a coin object. This is used to test whether or not
 * collisions with money bags should be considered when the player is invincible.
 *
 * @return false
 */
bool MoneyBag::isACoin()
{
	return false;
}

/**
 * Destructor
 *
 * @return false
 */
MoneyBag::~MoneyBag()
{

}
