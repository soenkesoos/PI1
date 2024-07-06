#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QLineEdit>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>


/**
 * @brief main method and entrypoint of the application
 * @param argc
 * @param argv
 * @return int
 
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QMessageBox msgBox;

    w.show();
    return a.exec();
}
