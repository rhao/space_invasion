#ifndef DOCTOR_H
#define DOCTOR_H

class MainWindow;

#include "thing.h"

class Doctor: public Thing
{
	public:
	Doctor(QPixmap *pm, int nx, int ny, MainWindow *w);
	void move();
	bool shouldRemove();
	void handleCollision();
	
	private:
	~Doctor();
};

#endif
