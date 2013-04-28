#ifndef TITLE_H
#define TITLE_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Title : public QGraphicsPixmapItem
{
	public:
	Title(QPixmap*);
	int getX();
	int getY();
	~Title();
	
	private:
	int x;
	int y;
};

#endif
