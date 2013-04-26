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
#include <map>
#include <QDialog>
#include "coin.h"
#include "thing.h"

#define WINDOW_MAX_X 300
#define WINDOW_MAX_Y 300
#define VELOCITY 1

class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    explicit MainWindow();
    ~MainWindow();
    void show();
    void removeCoin(Coin *c);
    
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
    QWidget *window;
    
    QGraphicsScene *popupScene;
    QGraphicsView *popupView;
    QVBoxLayout *popupLayout;
    
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
    
    QDialog popup;
    QPushButton popupClose;

    int timerCount;
    
    bool gameStarted;

public slots:
    void handleTimer();
    void pauseApp();
    void startGame();
};

#endif // MAINWINDOW_H
