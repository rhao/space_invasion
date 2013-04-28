#ifndef EXPLOSION_H
#define EXPLOSION_H

class MainWindow;

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Explosion : public QGraphicsPixmapItem
{
	public:
	Explosion(QPixmap *, MainWindow *w);
	int getX();
	int getY();
	~Explosion();
	
	private:
	int x;
	int y;
	MainWindow *window;
};

#endif
