/**************************************************************************

  Name: main.cpp
  Description: This is the main file. Executes MainWindow, and MainWindow w will handle the rest.
  Author: Ethan Randolph
  Email: randolphe@student.vvc.edu
  Created: May 29, 2018

**************************************************************************/
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
