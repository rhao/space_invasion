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
#include <QPalette>
#include <QGraphicsSceneMouseEvent>
#include <vector>
#include <QErrorMessage>
#include "coin.h"
#include "thing.h"
#include "player.h"
#include "background.h"
#include "alien.h"
#include "doctor.h"
#include "moneybag.h"
#include "turtle.h"

using namespace std;

#define WINDOW_MAX_X 1200
#define WINDOW_MAX_Y 640
#define VELOCITY 1

//class MainWindow : public QWidget {
class MainWindow : public QMainWindow {
	Q_OBJECT
    
public:
	//MainWindow(QWidget *parent = 0);
	MainWindow(QMainWindow *parent = 0);
	~MainWindow();
	void show();
	void keyPressEvent(QKeyEvent *e);
	void setScore(int s);
	void decreaseLives();
	void gameOver();
	
protected:
	//void keyPressEvent( QKeyEvent *e );
	
	void initializeVariables();
	void createPopup();
	void createButtons();
	void createOutput();
	void createBackground();
	void removeFromVector(Thing*);
	
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
	
	Background *bg;
	Background *bg2;
	QPixmap *bgImage;
	Player *p;
	QPixmap *playerImage;
	
	QPixmap *coinImage;
	Coin *c;
	
	QPixmap *alienImage;
	Alien *a;
	
	QPixmap *doctorImage;
	Doctor *d;
	
	QPixmap *moneybagImage;
	MoneyBag *mb;
	
	QPixmap *turtleImage;
	Turtle *t;
	
	int count;
	bool paused;
	
	vector<Thing*> things;
	int randY;
	int randThing;
	int newX;
	


public:
	int game_max_y;
	int game_min_y;
	int score;
	int lives;
	int coinHeight;
	int alienHeight;
	int doctorHeight;
	int moneybagHeight;
	int turtleHeight;
	int playerHeight;

public slots:
	void handleTimer();
	void pauseApp();
	void startGame();
	void callPopup();
	void cancelPopup();
};

#endif // MAINWINDOW_H
