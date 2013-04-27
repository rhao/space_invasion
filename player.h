#ifndef PLAYER_H
#define PLAYER_H

class MainWindow;

#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include <QPixmap>

class Player : public QGraphicsPixmapItem
{
	public:
	Player(MainWindow*, QPixmap *);
	
	void moveUp();
	void moveDown();
	void setY(int y_);
	void setV(int v_);
	
	int getX();
	int getY();
	int getV();
	~Player();
	
	private:
	MainWindow *window;
	int x;
	int y;
	int v;
};

#endif
