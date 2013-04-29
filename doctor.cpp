#include "doctor.h"
#include "mainwindow.h"

/**
 * Constructor for doctor which calls the constructor of Thing as well
 *
 * @param pm The pixmap image of the doctor
 * @param nx The x-coordiate to be assigned
 * @param ny The y-coordinate to be assigned
 * @param w A pointer to the main window
 * @return nothing
 */
Doctor::Doctor( QPixmap *pm, int nx, int ny, MainWindow *w ) : Thing( pm, nx, ny, w )
{
	//doctor x velocity is between 2 and 4
	vX = (double)((rand() % 20))/10 + 2;
	//doctor yvelocity is either 4 or -4
	int vRand = rand() % 2;
	if(vRand == 1)
	{
		vY = 4;
	}
	else if(vRand == 0)
	{
		vY = -4;
	}
}

/**
 * Moves the doctor by adjusting the x and y-coordinates by the velocity. Doctors bounce off
 * both the top and bottom of the screen.
 *
 * @return nothing
 */
void Doctor::move()
{
	int miny = window->game_min_y;
	int maxy = window->game_max_y;
	x = x - vX;
	y = y - vY;
	maxy -= window->doctorHeight;
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
 * Returns true is the doctor is off the screen to the left and should be removed,
 * false otherwise.
 *
 * @return bool True if object is off screen, otherwise false
 */
bool Doctor::shouldRemove()
{
	if(x < -100)
	{
		return true;
	}
	return false;
}

/**
 * This function is called after a player collides with a doctor. The player gains
 * a life when this occurs.
 *
 * @return nothing
 */
void Doctor::handleCollision()
{
	window->increaseLives();
}

/**
 * Returns false because the doctor is not a coin object. This is used to test whether or not
 * collisions with doctors should be considered when the player is invincible.
 *
 * @return false
 */
bool Doctor::isACoin()
{
	return false;
}

/**
 * Destructor
 *
 * @return nothing
 */
Doctor::~Doctor()
{

}
