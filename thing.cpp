#include "mainwindow.h"

Thing::Thing( QPixmap* p, int nx, int ny, MainWindow *w ) : QGraphicsPixmapItem(*p)
{
	setPixmap( *p );
	x = nx;
	y = ny;
	setPos( x, y );
	window = w;
}
