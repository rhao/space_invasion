#ifndef ENDSCREEN_H
#define ENDSCREEN_H

class MainWindow;

#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QPushButton>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include <QPalette>
#include <QHBoxLayout>

class EndScreen : public QWidget
{
	public:
	EndScreen(QString, int, MainWindow*);
	void close();
	~EndScreen();
	
	private:
	int x;
	int y;
	QPushButton* restart;
	QPushButton* quit;
	QString scoreString;
	QGraphicsTextItem *nameText;
	QGraphicsTextItem *scoreText;
	QString name;
	int score;
	QGraphicsScene *scene;
	QGraphicsView *view;
	QWidget *window;
	QPalette *pal;
	MainWindow *mw;
	QHBoxLayout *layout;
	QPixmap *endGameImage;
};

#endif
