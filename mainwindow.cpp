#include "mainwindow.h"
#include <cmath>

/**
 * Performs appropriate actions every time timer is called.
 *
 * @return nothing
 */
void MainWindow::handleTimer()
{
	bg->scroll(0, WINDOW_MAX_X);
	bg2->scroll(0, WINDOW_MAX_X);
}

/**
 * Function is called every time a tile is clicked.
 *
 * @param e Mouse event
 * @return nothing
 */
void MainWindow::keyPressEvent(QKeyEvent *e)
{
	std::cout<<"key";
	if(e->key() == Qt::Key_Q)
	{
		std::cout<<"Up\n";
		//p->moveUp();
	}
	else if(e->key() == Qt::Key_Down)
	{
		std::cout<<"Down\n";
		//p->moveDown();
	}
}

/**
 * Pauses the app.
 *
 * @return nothing
 */
void MainWindow::pauseApp()
{
	//p->moveDown(game_max_y);
	p->moveUp(game_min_y);
/**
	if(timer->isActive())
	{
		timer->stop();
	}
	else
	{
		timer->start();
	}
	**/
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
		errors->setText("");
		livesLine->setText("3");
		pointsLine->setText("0");
		popupView->close();
		userName = userNameLine->text();
		
		createBackground();
		playerImage = new QPixmap("images/astronaut.jpg");
		*playerImage = playerImage->scaledToHeight(100);
		p = new Player(playerImage);
		timer->start();
		//p->setPos(500, 500);
	
		scene->addItem(p);
	}
	else
	{
		errorsExists = true;
		errors->setText("Enter a name!");
	}
}

void MainWindow::callPopup()
{
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
MainWindow::MainWindow()
{
	scene = new QGraphicsScene();
	view = new QGraphicsView( scene );
	layout = new QFormLayout();
	window = new QWidget();
	gameStarted = false;
	
	initializeVariables();
	createPopup();
	createButtons();
	createOutput();
	
	
	view->setLayout(layout);
	window->setLayout(layout);
	window->setFixedSize(WINDOW_MAX_X-3, game_min_y);
	
	view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
	scene->addWidget(window);
	view->setFixedSize( WINDOW_MAX_X, WINDOW_MAX_Y);
	view->setWindowTitle( "Space Invasion");
	

	//This is how we do animation. We use a timer with an interval of 5 milliseconds
	//We connect the signal from the timer - the timeout() function to a function
	//of our own - called handleTimer - which is in this same MainWindow class
	timer = new QTimer(this);
	timer->setInterval(10);
	
	//connects
	connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
	connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));
	connect(start, SIGNAL(clicked()), this, SLOT(callPopup()));
	connect(popupStart, SIGNAL(clicked()), this, SLOT(startGame()));
	connect(popupCancel, SIGNAL(clicked()), this, SLOT(cancelPopup()));
	connect(pause, SIGNAL(clicked()), this, SLOT(pauseApp()));
	
	setFocus();
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
	game_min_y = WINDOW_MAX_Y/5;
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
