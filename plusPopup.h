#ifndef PLUSPOPUP_H
#define PLUSPOPUP_H

class MainWindow;

#include <QGraphicsPixmapItem>
#include <QPixmap>

class PlusPopup : public QGraphicsPixmapItem
{
	public:
	PlusPopup(QPixmap *, MainWindow *w);
	int getX();
	int getY();
	~PlusPopup();
	
	private:
	int x;
	int y;
	MainWindow *window;
};

#endif
