#ifndef MONEYBAG_H
#define MONEYBAG_H

class MainWindow;

#include "thing.h"

class MoneyBag: public Thing
{
	public:
	MoneyBag(QPixmap *pm, int nx, int ny, MainWindow *w);
	void move();
	bool shouldRemove();
	void handleCollision();
	
	private:
	~MoneyBag();
};

#endif
