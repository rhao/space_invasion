#include <QtGui/QApplication>
#include "mainwindow.h"

/** @mainpage CSCI 102 Programming Assignment 5
@author Rebecca Hao
@section purpose Purpose/Overview
Space Invasion is a game in which an astronaut navigates his way through space. The astronaut must
try to collect points by colliding with coins and money bags and try to stay alive by avoiding
aliens and colliding with doctors. Turtles slow down the pace of the game, which is helpful as
the speed of the game increases as the game goes on. The arrow keys are used to move the astronaut
up and down as he floats through space.
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
