#include "alien.h"
#include "mainwindow.h"

/**
 * Constructor which calls the constructor of Thing as well
 *
 * @param pm The pixmap image of the alien
 * @param nx The x-coordiate to be assigned
 * @param ny The y-coordinate to be assigned
 * @param w A pointer to the main window
 * @return nothing
 */
Alien::Alien( QPixmap *pm, int nx, int ny, MainWindow *w ) : Thing( pm, nx, ny, w )
{	
	//alien x velocity is a random number (to one decimal place) between 2 and 7
	vX = (double)((rand() % 50))/10 + 2;
	vY = 0;
}

/**
 * Moves the alien by changing the x-coordinate by the velocity. Because aliens travel in a
 * straight line, the y-coordinate remains the same.
 *
 * @return nothing
 */
void Alien::move()
{
	x = x - vX;
	this->setPos(x, y);
}

/**
 * Returns true is the Alien is off the screen and should be removed, false otherwise.
 *
 * @return bool True if object is off screen, otherwise false
 */
bool Alien::shouldRemove()
{
	if(x < -100)
	{
		return true;
	}
	return false;
}

/**
 * This function gets called after the player collides with an alien, and reduces the number
 * of player's lives. If the player has zero lives, then the game is over, so the function
 * triggers the gameOver function.
 *
 * @return nothing
 */
void Alien::handleCollision()
{
	window->decreaseLives();
	if(window->lives <= 0)
	{
		window->gameOver();
	}
}

/**
 * Returns false because an alien is not a coin object. This is used to test whether or not
 * collisions with aliens should be considered when the player is invincible.
 *
 * @return false
 */
bool Alien::isACoin()
{
	return false;
}

/**
 * Destructor
 *
 * @return nothing
 */
Alien::~Alien()
{

}
