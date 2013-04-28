#ifndef THING_H
#define THING_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Thing: public QGraphicsPixmapItem
{
	public:
	Thing (QPixmap *pm, int nx, int ny, MainWindow *w);
	virtual void move() = 0; //virtual function. Class Thing is abstract. For a reason.
	virtual bool shouldRemove() = 0;
	virtual void handleCollision() = 0;
	virtual bool isACoin() = 0;
	
	protected: //Every thing has a origin and a velocity – maybe 0
	int x;
	int y;
	double vX;
	double vY;
	QPixmap *pixMap;
	
	public:
	MainWindow *window;
};

#endif
