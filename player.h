#ifndef PLAYER_H
#define PLAYER_H

class MainWindow;

#include <QGraphicsSceneMouseEvent>

class Player
{
	public:
	Player(MainWindow*);
	
	void mousePressEvent(QGraphicsSceneMouseEvent *e);
	
	void move(bool dir);
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
