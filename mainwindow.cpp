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
	userName = userNameLine->text();
	if(userName != "")
	{
		gameStarted = true;
		nameLine->setText(userName);
		userNameLine->setText("");
		livesLine->setText("3");
		pointsLine->setText("0");
		popupView->close();
		userName = userNameLine->text();
		if(errorsExists)
		{
			//delete popupWindow;
			popupWindow = new QWidget();
			popupLayout->addItem(h1);
			popupLayout->addItem(h2);
			popupView->setGeometry(WINDOW_MAX_X/2 - 70, WINDOW_MAX_Y/2, 300, 100);
			popupWindow->setGeometry(0, 0, 300 -3, 100 -3);
			
		}
	}
	else
	{
		if(!errorsExists)
		{
			errorsExists = true;
			errors = new QLineEdit();
			errors->setText("Enter a name!");
			errors->setReadOnly(true);
			popupLayout->addWidget(errors);
			popupView->setGeometry(WINDOW_MAX_X/2 - 70, WINDOW_MAX_Y/2, 300, 150);
			popupWindow->setGeometry(0, 0, 300 -3, 150 -3);
		}
		
	}
}

void MainWindow::callPopup()
{
	popupView->show();
}

void MainWindow::cancelPopup()
{
	userNameLine->setText("");
	popupView->close();
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
	popupView = new QGraphicsView(popupScene);
	popupLayout = new QFormLayout();
	popupWindow = new QWidget();
	popupView->setGeometry(WINDOW_MAX_X/2 - 70, WINDOW_MAX_Y/2, 300, 100);
	popupWindow->setGeometry(0, 0, 300 -3, 100 -3);
	popupNameLabel = new QLabel();
	popupNameLine = new QLineEdit();
	popupStart = new QPushButton("Start");
	popupCancel = new QPushButton("Cancel");
	userNameLabel = new QLabel("Enter name: ");
	userNameLine = new QLineEdit();
	errorsExists = false;
	
	h1 = new QHBoxLayout();
	h1->addWidget(userNameLabel);
	h1->addWidget(userNameLine);
	h2 = new QHBoxLayout();
	h2->addWidget(popupStart);
	h2->addWidget(popupCancel);
	popupLayout->addItem(h2);
	popupLayout->addItem(h1);
	
	//popupLayout->addRow(userNameLabel, userNameLine);
	//popupLayout->addRow(popupStart, popupCancel);
	//popupView->setLayout(popupLayout);
	popupWindow->setLayout(popupLayout);
	
	popupView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	popupScene->addWidget(popupWindow);
	popupView->setWindowTitle( "Start Screen");
	
	startStopLayout = new QHBoxLayout();
	start = new QPushButton("Start Game");
	pause = new QPushButton("Pause");
	quit = new QPushButton("Quit");
	startStopLayout->addWidget(start);
	startStopLayout->addWidget(pause);
	startStopLayout->addWidget(quit);
	layout->addRow(startStopLayout);
	
	
	
	//popupLayout->addWidget(userNameLabel);
	//popupLayout->addWidget(userNameLine);
	
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
	window->setFixedSize(WINDOW_MAX_X-3, WINDOW_MAX_Y-3);
	
	view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	scene->addWidget(window);
	view->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y);
	view->setWindowTitle( "Space Invasion");

	//This is how we do animation. We use a timer with an interval of 5 milliseconds
	//We connect the signal from the timer - the timeout() function to a function
	//of our own - called handleTimer - which is in this same MainWindow class
	timer = new QTimer(this);
	timer->setInterval(5);
	
	//connects
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	connect(start, SIGNAL(clicked()), this, SLOT(callPopup()));
	connect(popupStart, SIGNAL(clicked()), this, SLOT(startGame()));
	connect(popupCancel, SIGNAL(clicked()), this, SLOT(cancelPopup()));
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
