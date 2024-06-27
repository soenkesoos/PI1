#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDialog>
#include "city.h"
#include "map.h"
#include "street.h"
#include "addcitydialog.h"
#include "mapio.h"
#include "mapionrw.h"
#include "dijkstra.h"
#include "searchdialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Ui::MainWindow *ui;

private slots:
    void on_pushButton_Input_clicked();

    void on_actionExit_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_pushButton_TestDrawCity_clicked();

    void on_pushButton_TestDrawStreet_clicked();

    void on_pushButton_TestDrawMapWithCities_clicked();

    void on_pushButton_TestDrawFullMap_clicked();

    void on_checkBox_HideTestButtons_clicked();

    void on_pushButton_AddCity_clicked();

    void on_pushButton_FillMap_clicked();

    void on_pushButton_TestAbstractMap_clicked();

    void on_pushButton_TestDijkstra_clicked();

    void on_pushButton_Wayfinder_clicked();

private:
    QGraphicsScene scene;
    Map map;
    MapIo *mapIo;
    void testAbstractMap();

};
#endif // MAINWINDOW_H
