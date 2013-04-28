#include "mainwindow.h"
#include <cmath>

/**
 * Performs appropriate actions every time timer is called.
 *
 
 grab keyboard x error bad window
 merrick said it seems like an issue that you can't fix with my code, but rather something about 
 qt or the vm
 
 get rid of player image, set player coordinates, set explosion image to that location,
 recreate player
 
 change velocities to rand
 make it so they can't start off screen/in menu bar
 
 * @return nothing
 */
void MainWindow::handleTimer()
{
	bg->scroll(0, WINDOW_MAX_X);
	bg2->scroll(0, WINDOW_MAX_X);
	
	for(int i = 0; i < (int)things.size(); i++)
	{
		things[i]->move();
		if(p->collidesWithItem(things[i]))
		{
			//remove from vector
			
			things[i]->handleCollision();
		}

	}
	//if(things[i]->shouldRemove())
	//{
		//REMOVE FROM VECTOR AFTER OFF SCREEN
	//}
	count++;

	if(count % 50 == 0)
	{
	
		randY = (rand() % (WINDOW_MAX_Y - game_min_y - 100)) + game_min_y;
		randThing = rand() % 14;
		Thing *newThing;

		if(randThing <= 5)
		{
			newThing = new Coin(coinImage, newX, randY, this);
		}
		else if(randThing <= 8)
		{
			newThing = new Alien(alienImage, newX, randY, this);
		}
		else if(randThing <= 10)
		{
			newThing = new Doctor(doctorImage, newX, randY, this);
		}
		else if(randThing <= 12)
		{
			newThing = new MoneyBag(moneybagImage, newX, randY, this);
		}
		else
		{
			newThing = new Turtle(turtleImage, newX, randY, this);
		}
		
		things.push_back(newThing);
		scene->addItem(newThing);
	}
}

/**
 * Function is called every time a tile is clicked.
 *
 * @param e Mouse event
 * @return nothing
 */
void MainWindow::keyPressEvent(QKeyEvent *e)
{
	//setFocusPolicy(Qt::StrongFocus);
	//std::cout<<"key";
	switch(e->key())
	{
		case Qt::Key_Up:
			if(!paused)
			{
				p->moveUp(game_min_y);
				p->moveUp(game_min_y);
				p->moveUp(game_min_y);
			}
			break;
		case Qt::Key_Down:
			if(!paused)
			{
				p->moveDown(game_max_y);
				p->moveDown(game_max_y);
				p->moveDown(game_max_y);
			}
			break;
		default:
			QWidget::keyPressEvent(e);
	}
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
		paused = !paused;
		pause->setText("Resume");
	}
	else
	{
		timer->start();
		paused = !paused;
		pause->setText("Pause");
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
		things.clear();
		gameStarted = true;
		nameLine->setText(userName);
		userNameLine->setText("");
		errors->setText("");
		livesLine->setText("3");
		QString stringScore;
		stringScore = QString::number(score);
		pointsLine->setText(stringScore);
		popupView->close();
		userName = userNameLine->text();
		
		createBackground();
		playerImage = new QPixmap("images/astronautb.png");
		*playerImage = playerImage->scaledToHeight(playerHeight);
		p = new Player(playerImage, this);
		timer->start();
	
		scene->addItem(p);
		
		this->grabKeyboard();
		
	}
	else
	{
		errorsExists = true;
		errors->setText("Enter a name above!");
	}
}

void MainWindow::callPopup()
{
	popupView->grabKeyboard();
	popupView->show();
}

void MainWindow::cancelPopup()
{
	userNameLine->setText("");
	errors->setText("");
	popupView->close();
}

/**
 * Constructor for the MainWindow
 *
 * @return nothing
 */
//MainWindow::MainWindow(QWidget* parent) : QWidget(parent)
MainWindow::MainWindow(QMainWindow* parent) : QMainWindow(parent)
{
	//this->setFocusPolicy(Qt::StrongFocus);
	
	scene = new QGraphicsScene();
	view = new QGraphicsView( scene );
	layout = new QFormLayout();
	window = new QWidget();
	gameStarted = false;
	
	initializeVariables();
	createPopup();
	createButtons();
	createOutput();
	
	QPalette pal(palette());
	//pal.setColor(QPalette::Background, QColor(152, 251, 152, 200));
	//pal.setColor(QPalette::Background, QColor(138, 43, 226, 50));
	pal.setColor(QPalette::Background, QColor(75, 209, 214, 100));
	window->setAutoFillBackground(true);
	window->setPalette(pal);
	
	view->setLayout(layout);
	window->setLayout(layout);
	window->setFixedSize(WINDOW_MAX_X-3, game_min_y);
	
	view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	scene->addWidget(window);
	view->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y);
	
	qreal _w = WINDOW_MAX_X - 3;
	qreal _h = WINDOW_MAX_Y - 3;
	qreal _x = 0;
	qreal _y = 0;
	scene->setSceneRect(_x, _y, _w, _h);
	view->setWindowTitle( "Space Invasion");
	
	
	//setting IMAGES of 5 things!
	coinImage = new QPixmap("images/coin.png");
	*coinImage = coinImage->scaledToHeight(coinHeight);
	
	alienImage = new QPixmap("images/alienb.png");
	*alienImage = alienImage->scaledToHeight(alienHeight);
	
	doctorImage = new QPixmap("images/doctorb3.png");
	*doctorImage = doctorImage->scaledToHeight(doctorHeight);
	
	moneybagImage = new QPixmap("images/money-bag.png");
	*moneybagImage = moneybagImage->scaledToHeight(moneybagHeight);
	
	turtleImage = new QPixmap("images/turtleb.png");
	*turtleImage = turtleImage->scaledToHeight(turtleHeight);

	//This is how we do animation. We use a timer with an interval of 20 milliseconds
	//We connect the signal from the timer - the timeout() function to a function
	//of our own - called handleTimer - which is in this same MainWindow class
	timer = new QTimer(this);
	timer->setInterval(35);
	
	//connects
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	connect(start, SIGNAL(clicked()), this, SLOT(callPopup()));
	connect(popupStart, SIGNAL(clicked()), this, SLOT(startGame()));
	connect(popupCancel, SIGNAL(clicked()), this, SLOT(cancelPopup()));
	connect(pause, SIGNAL(clicked()), this, SLOT(pauseApp()));
	
	//setFocus();
	view->setFocus();
	//std::cout<<QApplication::focusWidget();
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

void MainWindow::initializeVariables()
{
	game_max_y = WINDOW_MAX_Y;
	game_min_y = WINDOW_MAX_Y/5 - 20;
	mousePressed = false;
	count = 0;
	paused = false;
	newX = WINDOW_MAX_X + 50;
	score = 0;
	coinHeight = 50;
	alienHeight = 80;
	doctorHeight = 80;
	moneybagHeight = 60;
	turtleHeight = 65;
	playerHeight = 90;
	
}

void MainWindow::createPopup()
{
	popupScene = new QGraphicsScene();
	popupView = new QGraphicsView(popupScene);
	popupLayout = new QFormLayout();
	popupWindow = new QWidget();
	popupView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	popupView->setGeometry(WINDOW_MAX_X/2 - 80, WINDOW_MAX_Y/2, 300, 120);
	popupWindow->setGeometry(0, 0, 300 -3, 120 -3);
	popupNameLabel = new QLabel();
	popupNameLine = new QLineEdit();
	popupStart = new QPushButton("Start");
	popupCancel = new QPushButton("Cancel");
	userNameLabel = new QLabel("Enter name: ");
	userNameLine = new QLineEdit();
	errorsExists = false;
	errors = new QLineEdit();
	
	h1 = new QHBoxLayout();
	h1->addWidget(userNameLabel);
	h1->addWidget(userNameLine);
	h2 = new QHBoxLayout();
	h2->addWidget(popupStart);
	h2->addWidget(popupCancel);
	popupLayout->addItem(h2);
	popupLayout->addItem(h1);
	popupLayout->addWidget(errors);
			
	//popupLayout->addRow(userNameLabel, userNameLine);
	//popupLayout->addRow(popupStart, popupCancel);
	//popupView->setLayout(popupLayout);
	popupWindow->setLayout(popupLayout);
	errors->setText("");
	errors->setReadOnly(true);
	popupView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	popupScene->addWidget(popupWindow);
	popupView->setWindowTitle( "Start Screen");
}

void MainWindow::createButtons()
{
	startStopLayout = new QHBoxLayout();
	start = new QPushButton("Start Game");
	pause = new QPushButton("Pause");
	quit = new QPushButton("Quit");
	startStopLayout->addWidget(start);
	startStopLayout->addWidget(pause);
	startStopLayout->addWidget(quit);
	layout->addRow(startStopLayout);
}

void MainWindow::createOutput()
{

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

}

void MainWindow::removeCoin(Coin *c)
{
	scene->removeItem(c);
}

void MainWindow::setScore(int s)
{
	score = s;
	QString stringScore;
	stringScore = QString::number(score);
	pointsLine->setText(stringScore);
}

void MainWindow::createBackground()
{
	bgImage = new QPixmap("images/stars.jpg");
	*bgImage = bgImage->scaled(WINDOW_MAX_X + 3, game_max_y - game_min_y, Qt::IgnoreAspectRatio, Qt::FastTransformation);
	bg = new Background(bgImage, 0, game_min_y);
	scene->addItem(bg);
	
	bg2 = new Background(bgImage, WINDOW_MAX_X, game_min_y);
	scene->addItem(bg2);
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
