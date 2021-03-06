#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Background : public QGraphicsPixmapItem
{
	public:
	Background(QPixmap *, int x_, int y_);
	void scroll(int, int);
	int getX();
	int getY();
	~Background();
	
	private:
	int x;
	int y;
	int v;
};

#endif
