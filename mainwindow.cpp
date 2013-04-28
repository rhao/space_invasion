#include "mainwindow.h"
#include <cmath>

/**
 * Performs appropriate actions every time timer is called.
 *
 
 slowly make more items/speed up
 
 popup is the only thing that pops up first
 OR start screen
 
 game over screen
 
 remove items as they go off screen
 
 
 segfaults if i double click on start
 
 grab keyboard x error bad window
 merrick said it seems like an issue that you can't fix with my code, but rather something about 
 qt or the vm

 need game over something
 
 * @return nothing
 */
 
 
void MainWindow::checkCollisions(int i)
{
	if(invincible)
	{
		if(invincibleCount == 0)
		{
			p->setPixmap(*playerImageBig);
			playerHeight = 110;
		}
		invincibleCount++;
		if(invincibleCount == 3000)
		{
			p->setPixmap(*playerImage);
			invincible = false;
			invincibleCount = 0;
			playerHeight = 90;
		}
		if(things[i]->isACoin() && p->collidesWithItem(things[i]))
		{
			things[i]->handleCollision();
			scene->removeItem(things[i]);
			removeFromVector(things[i]);
		}
	}
	else
	{
		if(p->collidesWithItem(things[i]))
		{
			things[i]->handleCollision();
			scene->removeItem(things[i]);
			removeFromVector(things[i]);
		}
	}
}
 
void MainWindow::handleGameCounter()
{
	gameCounter++;
	if(gameCounter == 500)
	{
		gameCounter = 0;

		if(gameSpeed <= 1)
		{
			//stop changing speed here
		}
		else if(gameSpeed < 5)
		{
			gameSpeed--;
		}
		else if(gameSpeed <= 15)
		{
			gameSpeed -= 5;
		}
		else
		{
			gameSpeed -= 10;
		}
		timer->setInterval(gameSpeed);
	}
} 

void MainWindow::handleGamePopups()
{
	for(int i = 0; i < (int)pluses.size(); i++)
	{
		pluses[i]->incrementC();
	}
	while(pluses.size() > 0 && (pluses.front()->getC()) == 30)
	{
		scene->removeItem(pluses[0]);
		pluses.pop_front();
	}
	
	for(int i = 0; i < (int)explosions.size(); i++)
	{
		explosions[i]->incrementC();
	}
	while(explosions.size() > 0 && explosions.front()->getC() == 30)
	{
		scene->removeItem(explosions[0]);
		explosions.pop_front();
	}
}

void MainWindow::generateNewThings()
{
	count++;

	if(count % 50 == 0)
	{
		randY = (rand() % (WINDOW_MAX_Y - game_min_y - 100)) + game_min_y;
		randThing = rand() % 7;
		Thing *newThing;

		if(randThing == 0 || randThing == 1)
		{
			newThing = new Coin(coinImage, newX, randY, this);
		}
		else if(randThing == 2 || randThing == 3)
		{
			newThing = new Alien(alienImage, newX, randY, this);
		}
		else if(randThing == 4)
		{
			newThing = new Doctor(doctorImage, newX, randY, this);
		}
		else if(randThing == 5)
		{
			newThing = new MoneyBag(moneybagImage, newX, randY, this);
		}
		else
		{
			newThing = new Turtle(turtleImage, newX, randY, this);
		}
		
		things.push_back(newThing);
		scene->addItem(newThing);
	
	/*
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
		*/
	}
}

void MainWindow::handleTimer()
{
	handleGameCounter();
	
	bg->scroll(0, WINDOW_MAX_X);
	bg2->scroll(0, WINDOW_MAX_X);
	
	for(int i = 0; i < (int)things.size(); i++)
	{
		things[i]->move();
		checkCollisions(i);

	}
	
	handleGamePopups();
	
	if(turtleBool)
	{
		turtleCount++;
		if(turtleCount == 75)
		{
			turtleCount = 0;
			turtleBool = false;
			setTimer();
		}
	}
	
	//if(things[i]->shouldRemove())
	//{
		//REMOVE FROM VECTOR AFTER OFF SCREEN
		//change money bag - gains you more points (100?) and makes invincible
	//}
	generateNewThings();
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
		if(gameJustStarted)
		{
			scene->removeItem(title);
			scene->removeItem(titleBackground);
			gameJustStarted = false;
			
			view->setLayout(layout);
			window->setLayout(layout);
			window->show();
		}
		
		if(gameStarted)
		{ 
			for(int i = 0; i < (int)things.size(); i++)
			{
				scene->removeItem(things[i]);
			}
			things.clear();
			scene->removeItem(p);
			scene->removeItem(bg);
			scene->removeItem(bg2);
			initializeVariables();
			pause->setText("Pause");
		}
		
		gameStarted = true;
		nameLine->setText(userName);
		userNameLine->setText("");
		livesLine->setText("3");
		QString stringScore;
		stringScore = QString::number(score);
		pointsLine->setText(stringScore);
		popupView->close();
		userName = userNameLine->text();
		
		createBackground();
		playerImage = new QPixmap("images/astronautb.png");
		*playerImage = playerImage->scaledToHeight(playerHeight);
		playerImageBig = new QPixmap("images/astronautb.png");
		*playerImageBig = playerImage->scaledToHeight(110);
		p = new Player(playerImage, this);
		
		timer->start();
	
		scene->addItem(p);
		
		
		this->grabKeyboard();
		
	}
}

void MainWindow::callPopup()
{
	view->show();
	popupView->show();
	popupView->grabKeyboard();
}

void MainWindow::cancelPopup()
{
	if(gameJustStarted)
	{
		qApp->quit();	
	}
	userNameLine->setText("");
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
	gameJustStarted = true;
	
	initializeVariables();
	createPopup();
	createButtons();
	createOutput();
	
	QPalette pal(palette());
	pal.setColor(QPalette::Background, QColor(75, 209, 214, 100));
	window->setAutoFillBackground(true);
	window->setPalette(pal);
	
	//view->setLayout(layout);
	//window->setLayout(layout);
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
	
	explosionImage = new QPixmap("images/explosion.png");
	*explosionImage = explosionImage->scaledToHeight(200);
	
	plusImage = new QPixmap("images/plus.png");
	*plusImage = plusImage->scaledToHeight(200);

	//This is how we do animation. We use a timer with an interval of 20 milliseconds
	//We connect the signal from the timer - the timeout() function to a function
	//of our own - called handleTimer - which is in this same MainWindow class
	timer = new QTimer(this);
	setTimer();
	
	
	//connects
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	connect(start, SIGNAL(clicked()), this, SLOT(callPopup()));
	connect(popupStart, SIGNAL(clicked()), this, SLOT(startGame()));
	connect(popupCancel, SIGNAL(clicked()), this, SLOT(cancelPopup()));
	connect(pause, SIGNAL(clicked()), this, SLOT(pauseApp()));
	
	//setFocus();
	view->setFocus();
	createTitle();
	callPopup();
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
	//view->show();
	popupView->show();
}

void MainWindow::initializeVariables()
{
	game_max_y = WINDOW_MAX_Y;
	game_min_y = WINDOW_MAX_Y/5 - 20;
	count = 0;
	paused = false;
	newX = WINDOW_MAX_X + 50;
	score = 0;
	lives = 3;
	coinHeight = 50;
	alienHeight = 80;
	doctorHeight = 80;
	moneybagHeight = 60;
	turtleHeight = 65;
	playerHeight = 90;
	popupCount = 0;
	popupImage = false;
	popupAlienImage = false;
	popupAlienCount = 0;
	alreadyPlusPopup = false;
	alreadyAlienPopup = false;
	invincible = false;
	invincibleCount = 0;
	turtleCount = 0;
	turtleBool = false;
	gameCounter = 0;
	gameSpeed = 35;
}

void MainWindow::createPopup()
{
	popupScene = new QGraphicsScene();
	popupView = new QGraphicsView(popupScene);
	popupLayout = new QFormLayout();
	popupWindow = new QWidget();
	popupView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	popupView->setGeometry(WINDOW_MAX_X/2 - 80, WINDOW_MAX_Y/2 + 40, 300, 90);
	popupWindow->setGeometry(0, 0, 300 -3, 90 -3);
	popupNameLabel = new QLabel();
	popupNameLine = new QLineEdit();
	popupStart = new QPushButton("Start");
	popupCancel = new QPushButton("Cancel");
	userNameLabel = new QLabel("Enter name: ");
	userNameLine = new QLineEdit();
	
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

void MainWindow::removeFromVector(Thing *t)
{
	int index = 0;
	for(int i = 0; i < (int)things.size(); i++)
	{
		if(things[i] == t)
		{
			index = i;
		}
	}
	things[index] = things.back();
	things.pop_back();
}

void MainWindow::setScore(int s)
{
	score = s;
	QString stringScore;
	stringScore = QString::number(score);
	pointsLine->setText(stringScore);
}

void MainWindow::decreaseLives()
{
	lives--;
	QString stringLives;
	stringLives = QString::number(lives);
	livesLine->setText(stringLives);
	explosion = new Explosion(explosionImage, this);
	popupAlienImage = true;
	//if(alreadyAlienPopup)
	//{
	//	popupAlienCount = 0;
	//	scene->removeItem(explosion);
	//}
	Explosion *ex = new Explosion(explosionImage, this);
	explosions.push_back(ex);
	scene->addItem(ex);
	
}

void MainWindow::increaseLives()
{
	lives++;
	QString stringLives;
	stringLives = QString::number(lives);
	livesLine->setText(stringLives);
	plus = new PlusPopup(plusImage, this);
	popupImage = true;
	
	PlusPopup *pl = new PlusPopup(plusImage, this);
	pluses.push_back(pl);
	scene->addItem(pl);
	//if(alreadyPlusPopup)
	//{
	//	popupCount = 0;
	//	scene->removeItem(plus);
	//}
}

int MainWindow::getPlayerX()
{
	return p->getX();
}

int MainWindow::getPlayerY()
{
	return p->getY();
}

void MainWindow::gameOver()
{
/*
	QErrorMessage errorMessage;
	errorMessage.showMessage("Game over.");
	errorMessage.exec();
	qApp->quit();
	*/
	pauseApp();
}

void MainWindow::createTitle()
{
	titleBackgroundImage = new QPixmap("images/background.png");
	*titleBackgroundImage = titleBackgroundImage->scaled(WINDOW_MAX_X + 5, WINDOW_MAX_Y + 5, Qt::IgnoreAspectRatio, Qt::FastTransformation);
	titleBackground = new Title(titleBackgroundImage, 0, 0);
	scene->addItem(titleBackground);
	title1Image = new QPixmap("images/title2.png");
	*title1Image = title1Image->scaledToWidth(WINDOW_MAX_X - 50);
	title = new Title(title1Image, 35, 100);
	scene->addItem(title);

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

void MainWindow::slowTimer()
{
	turtleBool = true;
	timer->setInterval(gameSpeed * 3);
}

void MainWindow::setTimer()
{
	timer->setInterval(gameSpeed);
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
