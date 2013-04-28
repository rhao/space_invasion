#ifndef COIN_H
#define COIN_H

class MainWindow;

#include "thing.h"

class Coin: public Thing
{
	public:
	Coin(QPixmap *pm, int nx, int ny, MainWindow *w);
	void move();
	bool shouldRemove();
	void handleCollision();
	bool isACoin();
	
	private:
	~Coin();
};

#endif
