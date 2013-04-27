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
	
	private:
	void remove();
};

#endif
