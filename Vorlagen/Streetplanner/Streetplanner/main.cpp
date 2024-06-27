#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QLineEdit>
#include <QPushButton>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QMessageBox msgBox;

    w.show();
    return a.exec();
}
