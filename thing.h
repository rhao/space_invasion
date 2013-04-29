#ifndef THING_H
#define THING_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Thing: public QGraphicsPixmapItem
{
	public:
	/**
	 * Constructor
	 *
	 * @param p Pointer to a pixmap for the Thing
	 * @param nx The x-coordinate of the Thing
	 * @param ny The y-coordinate of the Thing
	 * @param w Pointer to the mainwindow
	 * @return nothing
	 */
	Thing (QPixmap *p, int nx, int ny, MainWindow *w);
	
	/** Virtual move function. */
	virtual void move() = 0; //virtual function. Class Thing is abstract. For a reason.
	
	/** Virtual function that determines if the Thing should be removed. */
	virtual bool shouldRemove() = 0;
	
	/** Virtual function that handles collisons with player. */
	virtual void handleCollision() = 0;
	
	/** Virtual function that determines if object is a coin. */
	virtual bool isACoin() = 0;
	
	protected: //Every thing has a origin and a velocity – maybe 0
	/** x-coordinate of Thing */
	int x;
	
	/** y-coordinate of Thing */
	int y;
	
	/** Velocity of the Thing in the x-direction */
	double vX;
	
	/** Velocity of the Thing in the y-direction */
	double vY;
	
	/** Pixmap of the Thing */
	QPixmap *pixMap;
	
	public:
	/** Pointer to the main window */
	MainWindow *window;
};

#endif
