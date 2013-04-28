#ifndef ALIEN_H
#define ALIEN_H

class MainWindow;

#include "thing.h"

class Alien: public Thing
{
	public:
	Alien(QPixmap *pm, int nx, int ny, MainWindow *w);
	void move();
	bool shouldRemove();
	void handleCollision();
	bool isACoin();
	
	private:
	~Alien();
};

#endif
