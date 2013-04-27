#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QPixmap>

class Player : public QGraphicsPixmapItem
{
	public:
	Player(QPixmap *);
	
	void moveUp(int window_min);
	void moveDown(int window_max);
	void setY(int y_);
	void setV(int v_);
	
	int getX();
	int getY();
	int getV();
	~Player();
	
	private:
	int x;
	int y;
	int v;
};

#endif
