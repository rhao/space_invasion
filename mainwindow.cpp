#include "mainwindow.h"
#include <iostream>
#include <cmath>

/**
 * Performs appropriate actions every time timer is called.
 *
 * @return nothing
 */
void MainWindow::handleTimer()
{
}

/**
 * Pauses the app.
 *
 * @return nothing
 */
void MainWindow::pauseApp()
{
	if(timer->isActive())
	{
		timer->stop();
	}
	else
	{
		timer->start();
	}
}

/**
 * Sets up the game every time the start button is pressed.
 *
 * @return nothing
 */
void MainWindow::startGame()
{
	QString errorString;
	errorString = "";
	userName = userNameLine->text();
	
	
	if(userName != "")
	{
		gameStarted = true;
		nameLine->setText(userName);
		livesLine->setText("3");
		pointsLine->setText("0");
	}
}

/**
 * Constructor for the MainWindow
 *
 * @return nothing
 */
MainWindow::MainWindow()
{
	scene = new QGraphicsScene();
	view = new QGraphicsView( scene );
	layout = new QFormLayout();
	window = new QWidget();
	gameStarted = false;
	
	popupScene = new QGraphicsScene();
	popupView = new QGraphicsView();
	popupLayout = new QVBoxLayout();
	
	startStopLayout = new QHBoxLayout();
	start = new QPushButton("Start Game");
	pause = new QPushButton("Pause");
	quit = new QPushButton("Quit");
	startStopLayout->addWidget(start);
	startStopLayout->addWidget(pause);
	startStopLayout->addWidget(quit);
	layout->addRow(startStopLayout);
	
	userNameLabel = new QLabel("Enter name:");
	userNameLine = new QLineEdit();
	
	popupLayout->addWidget(userNameLabel);
	popupLayout->addWidget(userNameLine);
	
	layout->addRow(userNameLabel, userNameLine);
	
	labelsLayout = new QHBoxLayout();
	outputLayout = new QHBoxLayout();
	
	nameLabel = new QLabel("Name:");
	livesLabel = new QLabel("Lives:");
	pointsLabel = new QLabel("Points:");
	labelsLayout->addWidget(nameLabel);
	labelsLayout->addWidget(livesLabel);
	labelsLayout->addWidget(pointsLabel);
	layout->addRow(labelsLayout);
	
	nameLine = new QLineEdit();
	livesLine = new QLineEdit();
	pointsLine = new QLineEdit();
	nameLine->setReadOnly(true);
	livesLine->setReadOnly(true);
	pointsLine->setReadOnly(true);
	outputLayout->addWidget(nameLine);
	outputLayout->addWidget(livesLine);
	outputLayout->addWidget(pointsLine);
	layout->addRow(outputLayout);
	
	/**
	popup = new QDialog();
	popupClose = new QPushButton();
	popup->setWindowTitle("Name Popup");
	**/
	
	
	view->setLayout(layout);
	window->setLayout(layout);
	window->setFixedSize(WINDOW_MAX_X*2 -2, WINDOW_MAX_Y);
	
	view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	scene->addWidget(window);
	view->setFixedSize( WINDOW_MAX_X * 2, WINDOW_MAX_Y *2);
	view->setWindowTitle( "Space Invasion");

	//This is how we do animation. We use a timer with an interval of 5 milliseconds
	//We connect the signal from the timer - the timeout() function to a function
	//of our own - called handleTimer - which is in this same MainWindow class
	timer = new QTimer(this);
	timer->setInterval(5);
	
	//connects
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	connect(start, SIGNAL(clicked()), this, SLOT(startGame()));
}

/**
 * Displays the MainWindow
 *
 * @return nothing
 */
void MainWindow::show()
{
	//This is how we get our view displayed.
	window->show();
	view->show();
}

void MainWindow::removeCoin(Coin *c)
{
	scene->removeItem(c);
}

/**
 * Destructor
 *
 * @return nothing
 */
MainWindow::~MainWindow()
{
	timer->stop();
	delete timer;
	delete scene;
	delete view;

}