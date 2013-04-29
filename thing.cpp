#include "mainwindow.h"

/**
 * Constructor for the abstract Thing class.
 *
 * @param p The pixmap of the Thing
 * @param nx The starting x-coordinate of the Thing
 * @param ny The starting y-coordinate of the Thing
 * @parram w A pointer to the main window
 * @return nothing
 */
Thing::Thing( QPixmap* p, int nx, int ny, MainWindow *w ) : QGraphicsPixmapItem(*p)
{
	setPixmap( *p );
	x = nx;
	y = ny;
	setPos( x, y );
	window = w;
}
