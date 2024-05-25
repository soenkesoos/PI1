#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QMessageBox>
#include <QLineEdit>
#include <QPushButton>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QMessageBox msgBox;


    w.show();

    msgBox.setText("The document has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");

    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Save);

    int ret = msgBox.exec();

    QMessageBox result;

    switch (ret)
    {
    case QMessageBox::Save:
        result.setText("Save was clicked.");
        break;
    case QMessageBox::Discard:
        result.setText("Don’t save was clicked."); break;
    case QMessageBox::Cancel: result.setText("Cancel was clicked."); break;
    default:
        result.setText("This should be impossible");
        break;
    }
    result.exec();




    return a.exec();
}
