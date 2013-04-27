#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QFormLayout>
#include <QRadioButton>
#include <QListView>
#include <QApplication>
#include <QTextEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QStringListModel>
#include <QKeyEvent>
#include <map>
#include <iostream>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include "coin.h"
#include "thing.h"
#include "player.h"

#define WINDOW_MAX_X 1200
#define WINDOW_MAX_Y 640
#define VELOCITY 1

class MainWindow : public QMainWindow {
	Q_OBJECT
    
public:
	explicit MainWindow();
	~MainWindow();
	void show();
	void removeCoin(Coin *c);
	
protected:
	void keyPressEvent( QKeyEvent *e );
	void createPopup();
	void createButtons();
	void createOutput();
    
private:
	QGraphicsScene *scene;
	QGraphicsView *view;
	QTimer *timer;
	QWidget *window;
	
	QGraphicsScene *popupScene;
	QGraphicsView *popupView;
	QFormLayout *popupLayout;
	QWidget *popupWindow;
	QLabel *popupNameLabel;
	QLineEdit *popupNameLine;
	QPushButton *popupStart;
	QPushButton *popupCancel;
	QLineEdit *errors;
	bool errorsExists;
	QHBoxLayout *h1;
	QHBoxLayout *h2;
	
	//other stuff
	QFormLayout *layout;
	QLabel *userNameLabel;
	QLineEdit *userNameLine;
	QString userName;
	
	QHBoxLayout *startStopLayout;
	QHBoxLayout *userNameLayout;
	QHBoxLayout *labelsLayout;
	QHBoxLayout *outputLayout;
	
	QPushButton *start;
	QPushButton *quit;
	QPushButton *pause;
    
	QLabel *nameLabel;
	QLabel *pointsLabel;
	QLabel *livesLabel;
    
	QLineEdit *nameLine;
	QLineEdit *pointsLine;
	QLineEdit *livesLine;

	int timerCount;
	bool gameStarted;
	
	Player *p;
	QPixmap *playerImage;

public slots:
	void handleTimer();
	void pauseApp();
	void startGame();
	void callPopup();
	void cancelPopup();
};

#endif // MAINWINDOW_H
