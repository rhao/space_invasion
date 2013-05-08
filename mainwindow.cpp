#include "mainwindow.h"
#include <cmath>

/**
 * Performs appropriate actions every time timer is called. This includes actions
 * such as moving the items and removing items that have scrolled past the screen.
 *
 * @return nothing
 */

void MainWindow::handleTimer()
{
	handleGameCounter();
	levelCount++;
	if(levelCount == 100)
	{
		level++;
		if(level == 2)
		{
			level2Popup = new PlusPopup(level2Image, this);
			scene->addItem(level2Popup);
			scene->removeItem(bg);
			scene->removeItem(bg2);
			createBackground();
			levelCount = 0;
			level2PopupExists = true;
		}
		else if(level == 3)
		{
			level3Popup = new PlusPopup(level3Image, this);
			scene->addItem(level3Popup);
			scene->removeItem(bg);
			scene->removeItem(bg2);
			createBackground();
			bg->setPixmap(*bgImage3);
			level3PopupExists = true;
		}
	}
	
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
		timer->setInterval(50);
		turtleCount++;
		if(turtleCount == 75)
		{
			turtleCount = 0;
			turtleBool = false;
			setTimer();
		}
	}
	
	//removing items as they go off screen
	for(int i = 0; i < (int)things.size(); i++)
	{
		if(things[i]->shouldRemove())
		{
			scene->removeItem(things[i]);
			removeFromVector(things[i]);
			i--;
		}
		
	}
	generateNewThings();
}

/**
 * Function is called every time a key is pressed. The up arrow key moves the player up, while
 * the down arrow key moves the player down.
 *
 * @param e Mouse event
 * @return nothing
 */
void MainWindow::keyPressEvent(QKeyEvent *e)
{
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
 * This functions loops through the items and determines if the thing with the given
 * index collides with the player.
 *
 * @param i The index of the thing to be checked.
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
			if(p->getY() > WINDOW_MAX_Y - 110)
			{
				p->setY(WINDOW_MAX_Y - 110);
				p->setPos(p->getX(), p->getY());
			}
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
 
/**
 * Increments the game counter and checks the value, increasing the speed of the game
 * by changing the timer interval when necessary. This allows the game to continuously
 * speed up over time, eventually moving so fast it is impossible to play.
 *
 * @return nothing
 */
void MainWindow::handleGameCounter()
{
	if(!turtleBool)
	{
		gameCounter++;
	}
	
	if(gameCounter == 500)
	{
		gameCounter = 0;

		/**
		if(gameSpeed <= 1)
		{
			gameSpeed = 1;
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
		*/
		timer->setInterval(gameSpeed);
	}
} 

/**
 * This function handles cases when the player collides with an alien, in which case an
 * explosion popup would occue, or with a doctor, in which case a plus one symbol to represent
 * gaining a life would pop up.
 *
 * @return nothing
 */
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
	if(level2PopupExists)
	{
		if(level2Popup->getC() == 30)
		{
			scene->removeItem(level2Popup);
			level2PopupExists = false;
		}
		else
		{
			level2Popup->incrementC();
		}
	}
	if(level3PopupExists)
	{
		if(level3Popup->getC() == 30)
		{
			scene->removeItem(level3Popup);
			level3PopupExists = false;
		}
		else
		{
			level3Popup->incrementC();
		}
	}
}

/**
 * Function randomly generates a new thing out of the five things with a random y-coordinate.
 *
 * @return nothing
 */
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
 * Sets up the game every time the start button is pressed from the popup menu.
 *
 * @return nothing
 */
void MainWindow::startGame()
{
	
	while(explosions.size() > 0)
	{
		scene->removeItem(explosions[0]);
		explosions.pop_front();
	}
	QString temp = userNameLine->text();
	if(temp != "")
	{
		userName = temp;	
		
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
			
			pause->setText("Pause");
		}
		
		gameStarted = true;
		nameLine->setText(userName);
		userNameLine->setText("");
		livesLine->setText("3");
		QString stringScore;
		score = 0;
		stringScore = QString::number(score);
		pointsLine->setText(stringScore);
		popupView->close();
		
		level = 1;
		createBackground();
		p = new Player(playerImage, this);
		
		gameSpeed = 35;
		setTimer();
		timer->start();
		scene->addItem(p);
		
		if(restarting)
		{
			endGame->close();
			restarting = false;
		}
		
		initializeVariables();
		
		this->grabKeyboard();
	}
}

/**
 * When the program is started, a popup appears. The popup contains a place for the user
 * to enter their name, a start button which begins the game, and a cancel button which
 * quits the program. The popup forces the user to enter a name before pressing start, or
 * else nothing happens.
 *
 * @return nothing
 */
void MainWindow::callPopup()
{
	//pausing if popup is called (i.e. start game was pressed)
	if(timer->isActive())
	{
		timer->stop();
		paused = !paused;
		pause->setText("Resume");
	}
	view->show();
	popupView->show();
	popupView->raise();
	popupView->setGeometry(WINDOW_MAX_X/2 - 80, WINDOW_MAX_Y/2 + 40, 300, 90);
	popupView->grabKeyboard();
}

/**
 * Handles the case in which the user presses cancel on the popup menu. If the game was already
 * started, the game simply resumes. If the game has not been started, then the cancel button
 * quits the program.
 *
 * @return nothing
 */
void MainWindow::cancelPopup()
{
	if(!(timer->isActive()))
	{
		timer->start();
		paused = !paused;
		pause->setText("Pause");
	}
	if(gameJustStarted)
	{
		qApp->quit();	
	}
	userNameLine->setText("");
	popupView->close();
	this->grabKeyboard();
}

/**
 * Constructor for the MainWindow. Reads in all the images and sets up the connects.
 *
 * @return nothing
 */
MainWindow::MainWindow(QMainWindow* parent) : QMainWindow(parent)
{	
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
	
	
	//setting IMAGES
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
	
	level2Image = new QPixmap("images/level2.png");
	*level2Image = level2Image->scaledToHeight(100);
	
	level3Image = new QPixmap("images/level3.png");
	*level3Image = level3Image->scaledToHeight(100);
	
	playerImage = new QPixmap("images/astronautb.png");
	*playerImage = playerImage->scaledToHeight(playerHeight);
	playerImageBig = new QPixmap("images/astronautb.png");
	*playerImageBig = playerImage->scaledToHeight(110);
	
	titleBackgroundImage = new QPixmap("images/background.png");
	
	bgImage = new QPixmap("images/stars.jpg");
	bgImage2 = new QPixmap("images/stars2.png");
	bgImage3 = new QPixmap("images/stars3.jpg");
	
	title1Image = new QPixmap("images/title2.png");

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
	
	view->setFocus();
	createTitle();
	callPopup();
}

/**
 * Displays the popup menu when the program is first started.
 *
 * @return nothing
 */
void MainWindow::show()
{
	//This is how we get our view displayed.
	//view->show();
	popupView->show();
}

/**
 * Initializes all the variables from the .h file to their start state.
 *
 * @return nothing
 */
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
	invincible = false;
	invincibleCount = 0;
	turtleCount = 0;
	turtleBool = false;
	gameCounter = 0;
	gameSpeed = 35;
	restarting = false;
	fileName = "highScores.txt";
	level = 1;
	levelCount = 0;
	level2PopupExists = false;
	level3PopupExists = false;
}

/**
 * Creates the actual popup menu by adding the buttons and line edit, etc.
 *
 * @return nothing
 */
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
			
	popupWindow->setLayout(popupLayout);
	popupView->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	popupScene->addWidget(popupWindow);
	popupView->setWindowTitle( "Start Screen");
}

/**
 * Creates the buttons that appear at the top menu part of the game, and adds them to the layout.
 *
 * @return nothing
 */
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

/**
 * Displays the output, including the user's name, number of lives, and points, at the top
 * of the game, and adds them to the layout.
 *
 * @return nothing
 */
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

/**
 * Removes the given Thing from the vector of Things.
 *
 * @param t The Thing to be removed from the vector.
 * @return nothing
 */
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

/**
 * Sets and displays the player's score.
 *
 * @param s The number of points the player has.
 * @return nothing
 */
void MainWindow::setScore(int s)
{
	score = s;
	QString stringScore;
	stringScore = QString::number(score);
	pointsLine->setText(stringScore);
}

/**
 * Decrements the number of lives the player has and creates the explosion.
 *
 * @return nothing
 */
void MainWindow::decreaseLives()
{
	lives--;
	QString stringLives;
	stringLives = QString::number(lives);
	livesLine->setText(stringLives);
	explosion = new Explosion(explosionImage, this);
	popupAlienImage = true;
	Explosion *ex = new Explosion(explosionImage, this);
	explosions.push_back(ex);
	scene->addItem(ex);
	
}

/**
 * Increments the number of lives the player has and creates the plus popup item.
 *
 * @return nothing
 */
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
}

/**
 * Returns the x-coordinate of the player.
 *
 * @return The x-coordinate of the player.
 */
int MainWindow::getPlayerX()
{
	return p->getX();
}

/**
 * Gets the y-coordinate of the player.
 *
 * @return The y-coordinate of the player.
 */
int MainWindow::getPlayerY()
{
	return p->getY();
}

/**
 * When the player loses all lives, the timer is stopped and an endGame object is created to
 * display the game over screen.
 *
 * @return nothing
 */
void MainWindow::gameOver()
{
	restarting = true;
	endGame = new EndScreen(userName, score, this);
	timer->stop();
	
	/*
	//reading through file and getting previous high scores and clear file
	fin.open(fileName.c_str());
	if(fin.fail())
	{
	
	}
	string testing;
	string oldName;
	int oldScore;
	//getline(fin, testing, '\"');
	//this is an old file, add all old high scores to queues then clear file
	if(!fin.eof())
	{
		//reading in and throwing away "High Scores:\n\n"
		getline(fin, testing, '\n');
		while(!fin.eof())
		{
			fin>>oldName;
			fin>>oldScore;
			names1.push(oldName);
			scores1.push(oldScore);
			//std::cout<<oldName<<"\n\n";
			//std::cout<<oldScore;
		}
		//fin.clear();
	}
	
	names1.push(userName.toStdString());
	scores1.push(score);
	fin.close();
	
	//writing new high scores to file
	fout.open(fileName.c_str());
	
	if(fout.fail())
	{	
	}
	fout<<"High Scores:\n\n";
	
	while(!names1.empty())
	{
		fout<<names1.top();
		fout<<": ";
		fout<<scores1.top();
		fout<<"\n";
		names2.push(names1.top());
		names1.pop();
		scores2.push(scores1.top());
		scores1.pop();
	}
	//putting names and scores back onto priority queues 1 and emptying queues 2
	while(!names2.empty())
	{
		names1.push(names2.top());
		names2.pop();
		scores1.push(scores2.top());
		scores2.pop();
	}
	fout.close();
	*/
	
	
	
	
	
	
	
	
	
	/*
	
	//reading through file and getting previous high scores and clear file
	fin.open(fileName.c_str());
	if(fin.fail())
	{
	
	}
	string testing;
	string oldName;
	int oldScore;
	int currScore;
	int index;
	
	//getline(fin, testing, '\"');
	//this is an old file, add all old high scores to queues then clear file
	if(!fin.eof())
	{
		//reading in and throwing away "High Scores:\n\n"
		getline(fin, testing, '\n');
		while(!fin.eof())
		{
			fin>>oldName;
			fin>>oldScore;
			scores1.push(oldScore);
			namesVector.push_back(oldName);
			scoresVector.push_back(oldScore);
		}
	}
	
	namesVector.push_back(userName.toStdString());
	scoresVector.push_back(score);
	scores1.push(score);
	fin.close();
	
	//writing new high scores to file
	fout.open(fileName.c_str());
	
	if(fout.fail())
	{	
	}
	fout<<"High Scores:\n\n";
	
	while(!scores1.empty())
	{
		currScore = scores1.top();
		for(int i = 0; i < scoresVector.size(); i++)
		{
			if(scoresVector[i] == currScore)
			{
				index = i;	
			}
		}
		fout<<namesVector[index];
		fout<<": ";
		fout<<scores1.top();
		fout<<"\n";
		scores1.pop();
	}
	fout.close();
	
	*/
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	names1.push(userName.toStdString());
	scores1.push(score);
	std::cout<<names1.top()<<"\n\n";
	
	//writing score to file
	fout.open(fileName.c_str());
	if(fout.fail())
	{	
	}
	fout<<"High Scores:\n\n";
	while(!names1.empty())
	{
		fout<<names1.top();
		fout<<": ";
		fout<<scores1.top();
		fout<<"\n";
		names2.push(names1.top());
		names1.pop();
		scores2.push(scores1.top());
		scores1.pop();
	}
	//putting names and scores back onto priority queues 1 and emptying queues 2
	while(!names2.empty())
	{
		names1.push(names2.top());
		names2.pop();
		scores1.push(scores2.top());
		scores2.pop();
	}
	*/
	
}

/**
 * Creates the start screen for before the game begins. This includes instructions.
 *
 * @return nothing
 */
void MainWindow::createTitle()
{
	*titleBackgroundImage = titleBackgroundImage->scaled(WINDOW_MAX_X + 5, WINDOW_MAX_Y + 5, Qt::IgnoreAspectRatio, Qt::FastTransformation);
	titleBackground = new Title(titleBackgroundImage, 0, 0);
	scene->addItem(titleBackground);
	*title1Image = title1Image->scaledToWidth(WINDOW_MAX_X - 50);
	title = new Title(title1Image, 35, 100);
	scene->addItem(title);

}

/**
 * Creates the scrolling background of the game.
 *
 * @return nothing
 */
void MainWindow::createBackground()
{
	if(level == 1)
	{
		*bgImage = bgImage->scaled(WINDOW_MAX_X + 3, game_max_y - game_min_y, Qt::IgnoreAspectRatio, Qt::FastTransformation);
		bg = new Background(bgImage, 0, game_min_y);
		bg->setZValue(-1);
		scene->addItem(bg);
	
		bg2 = new Background(bgImage, WINDOW_MAX_X, game_min_y);
		bg2->setZValue(-1);
		scene->addItem(bg2);
	}
	else if(level == 2)
	{
		*bgImage2 = bgImage2->scaled(WINDOW_MAX_X + 3, game_max_y - game_min_y, Qt::IgnoreAspectRatio, Qt::FastTransformation);
		bg = new Background(bgImage2, 0, game_min_y);
		bg->setZValue(-1);
		scene->addItem(bg);
	
		bg2 = new Background(bgImage2, WINDOW_MAX_X, game_min_y);
		bg2->setZValue(-1);
		scene->addItem(bg2);
	}
	else
	{
		*bgImage3 = bgImage3->scaled(WINDOW_MAX_X + 3, game_max_y - game_min_y, Qt::IgnoreAspectRatio, Qt::FastTransformation);
		bg = new Background(bgImage3, 0, game_min_y);
		bg->setZValue(-1);
		scene->addItem(bg);
	
		bg2 = new Background(bgImage3, WINDOW_MAX_X, game_min_y);
		bg2->setZValue(-1);
		scene->addItem(bg2);
	}
	
}

/**
 * Function is called when the timer is supposed to be slowed down because the player
 * collided with a turtle.
 *
 * @return nothing
 */
void MainWindow::slowTimer()
{
	turtleBool = true;
	//timer->setInterval(50);
}

/**
 * Sets the timer interval to the gameSpeed variable, which changes.
 *
 * @return nothing
 */
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
