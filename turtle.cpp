#include "turtle.h"
#include "mainwindow.h"

/**
 * Constructor which calls the constructor of Thing as well
 *
 * @param pm The pixmap image of the turtle
 * @param nx The x-coordiate to be assigned
 * @param ny The y-coordinate to be assigned
 * @param w A pointer to the main window
 * @return nothing
 */
Turtle::Turtle( QPixmap *pm, int nx, int ny, MainWindow *w ) : Thing( pm, nx, ny, w )
{
	vX = 2;
	vY = 0;
}

/**
 * Moves the turtle by changing the x-coordinate by the velocity. Because turtles travel in a
 * straight line, the y-coordinate remains the same.
 *
 * @return nothing
 */
void Turtle::move()
{
	x = x - vX;
	this->setPos(x, y);
}

/**
 * Returns true is the turtle is off the screen and should be removed, false otherwise.
 *
 * @return bool True if object is off screen, otherwise false
 */
bool Turtle::shouldRemove()
{
	if(x < -100)
	{
		return true;
	}
	return false;
}

/**
 * This function gets called after the player collides with a turtle, and reduces the speed of
 * the game. The background and all objects move slower, however the player can still
 * move at the same speed.
 *
 * @return nothing
 */
void Turtle::handleCollision()
{
	window->turtleBool = true;
}

/**
 * Returns false because a turtle is not a coin object. This is used to test whether or not
 * collisions with turtles should be considered when the player is invincible.
 *
 * @return false
 */
bool Turtle::isACoin()
{
	return false;
}

/**
 * Destructor
 *
 * @return nothing
 */
Turtle::~Turtle()
{

}
