#include "coin.h"
#include "mainwindow.h"

/**
 * Constructor which calls the constructor of Thing
 *
 * @param pm The pixmap image of the coin
 * @param nx The x-coordiate to be assigned
 * @param ny The y-coordinate to be assigned
 * @param w A pointer to the main window
 * @return nothing
 */
Coin::Coin( QPixmap *pm, int nx, int ny, MainWindow *w) : Thing( pm, nx, ny, w )
{
	//coin y velocity is either -1 or +1
	vX = 3;
	int vRand = rand() % 2;
	if(vRand == 1)
	{
		vY = 1;
	}
	else if(vRand == 0)
	{
		vY = -1;
	}
}

/**
 * Moves the coin by adjusting the x and y-coordinates by the velocity. Coins bounce off the top
 * of the screen, however they fall off the bottom.
 *
 * @return nothing
 */
void Coin::move()
{
	int miny = window->game_min_y;
	//coins fall off bottom of screen, bounce off top
	if(y < miny)
	{
		y = miny;
		vY = -vY;
	}
	else
	{
		y = y + vY;
	}
	x = x - vX;
	if(x < 0)
	{
		//window->removeCoin(this);
	}
	this->setPos(x, y);
}

/**
 * Returns true is the coin is off the screen and should be removed, false otherwise.
 *
 * @return bool True if object is off screen, otherwise false
 */
bool Coin::shouldRemove()
{
	if(x < -100)
	{
		return true;
	}
	return false;
}

/**
 * This function is called after a player collides with a coin. The player's score is
 * increased by ten and the coin is removed from the scene.
 *
 * @return nothing
 */
void Coin::handleCollision()
{
	int s = window->score;
	s += 10;
	window->setScore(s);
}

/**
 * Returns true to represent that this object is a coin. This is necessary for the invincible
 * mode in which the player is unaffected by all objects except for coins.
 *
 * @return true because the object is a coin
 */
bool Coin::isACoin()
{
	return true;
}

/**
 * Destructor
 *
 * @return nothing
 */
Coin::~Coin()
{

}
