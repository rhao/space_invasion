#ifndef TURTLE_H
#define TURTLE_H

class MainWindow;

#include "thing.h"

class Turtle: public Thing
{
	public:
	Turtle(QPixmap *pm, int nx, int ny, MainWindow *w);
	void move();
	bool shouldRemove();
	void handleCollision();
	
	private:
	~Turtle();
};

#endif
