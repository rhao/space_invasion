#include "mainwindow.h"

Thing::Thing( QPixmap* p, int nx, int ny, MainWindow *w )
{
	pixMap = p; //Handy to store separate to get image width/height, etc.
	setPixmap( *p );
	x = nx;
	y = ny;
	setPos( x, y );
	window = w;
}
