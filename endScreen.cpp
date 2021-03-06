#include "endScreen.h"
#include "mainwindow.h"
#include <iostream>

/**
 * Constructor
 *
 * @param n The name of the user to be displayed on the game over screen
 * @param s The score of the player to be displayed on the game over screen
 * @param w Pointer to the mainwindow
 * @return nothing
 */
EndScreen::EndScreen(QString n, int s, MainWindow *w) : QWidget()
{
	x = 0;
	y = 0;
	name = "Name: " + n;
	QString num = QString::number(s);
	scoreString = "Score: " + num;
	mw = w;
	
	QFont font;
	font.setPixelSize(40);
	
	nameText = new QGraphicsTextItem("Name: " + n);
	scoreText = new QGraphicsTextItem(scoreString);
	
	nameText->setDefaultTextColor(Qt::red);
	scoreText->setDefaultTextColor(Qt::red);
	nameText->setFont(font);
	scoreText->setFont(font);
	
	scene = new QGraphicsScene();
	view = new QGraphicsView( scene );
	window = new QWidget();
	layout = new QHBoxLayout();
	

	
	endGameImage = new QPixmap("images/turtle_in_space.gif");
	*endGameImage = endGameImage->scaled(WINDOW_MAX_X, WINDOW_MAX_Y + 50, Qt::IgnoreAspectRatio, Qt::FastTransformation);
	
	pal = new QPalette();
	pal->setBrush(QPalette::Background, *endGameImage);
	window->setPalette(*pal);
	
	restart = new QPushButton("Restart");
	quit = new QPushButton("Quit");
	
	layout->setAlignment(Qt::AlignCenter);
	restart->setFixedSize(200, 60);
	quit->setFixedSize(200, 60);
	
	//scene->addItem(restart);
	//scene->addItem(quit);
	layout->addWidget(restart);
	layout->addWidget(quit);
	window->setLayout(layout);
	view->setLayout(layout);
	
	scene->addWidget(window);
	
	view->setFixedSize( WINDOW_MAX_X + 5, WINDOW_MAX_Y + 30);
	qreal _w = WINDOW_MAX_X + 3;
	qreal _h = WINDOW_MAX_Y + 24;
	qreal _x = 0;
	qreal _y = 0;
	//window->setGeometry(0, 0, WINDOW_MAX_X, WINDOW_MAX_Y + 20);
	window->setFixedSize(WINDOW_MAX_X, WINDOW_MAX_Y + 30);
	scene->setSceneRect(_x, _y, _w, _h);
	nameText->setPos(450, 400);
	scoreText->setPos(450, 450);
	scene->addItem(nameText);
	scene->addItem(scoreText);
	
	connect(restart, SIGNAL(clicked()), mw, SLOT(callPopup()));
	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	
	view->show();
	
}

/**
 * Closes the view. This is used if the player restarts the game.
 *
 * @return nothing
 */
void EndScreen::close()
{
	view->close();
}

/**
 * Destructor
 *
 * @return nothing
 */
EndScreen::~EndScreen()
{

}
