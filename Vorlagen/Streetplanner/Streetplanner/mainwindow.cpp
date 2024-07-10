#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QRandomGenerator>
#include <QCheckBox>
#include <QComboBox>
#include <QFileDialog>
#include <QStandardPaths>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(&scene);
    mapIo = new MapIoNrw();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Input_clicked()
{
    qDebug() << "Button_Input was pushed";
    QString input = ui->lineEdit_Input->text();
    QMessageBox outputBox;
    if(input.toInt() != 0) {
        qDebug() << "lineEdit: " << input.toInt()+4;
        outputBox.setText(QString::number(input.toInt()+4));
    } else {
        qDebug() << "lineEdit: " <<input;
        outputBox.setText(input);
    }
    int x = QRandomGenerator::global()->bounded(scene.width());
    int y = QRandomGenerator::global()->bounded(scene.height());
    scene.addRect(x, y, 10, 10, QPen (Qt::red), QBrush(Qt::red, Qt::SolidPattern));
    outputBox.exec();

}

void MainWindow::on_actionExit_triggered()
{
    qDebug() << "Exiting Program because Exit was triggered";
    close();
}


void MainWindow::on_actionClear_Scene_triggered()
{
    qDebug() << "Clearing Scene because Clear Scene was Triggerd";
    scene.clear();
    map.clear();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox aboutBox;
    aboutBox.about(this, "About", "written by: \nSönke Schulte-Zurhausen \n\n as part of the Praktikum Informatik 1");
}


void MainWindow::on_pushButton_TestDrawCity_clicked()
{
    City *city1 = new City("city1", 100, 200);
    city1->draw(scene);

}


void MainWindow::on_pushButton_TestDrawMapWithCities_clicked()
{
    City *c1 = new City("c1", 20, 50);
    map.addCity(c1);
    City *c2 = new City("c2", 200, 100);
    map.addCity(c2);
    map.draw(scene);
}



void MainWindow::on_pushButton_TestDrawStreet_clicked()
{
    City *c1 = new City("c1", 20,50);
    City *c2 = new City("c2", 200, 100);
    Street *s1 = new Street(c1, c2);
    s1->draw(scene);
}




void MainWindow::on_pushButton_TestDrawFullMap_clicked()
{
    //some Cities for testing
    City *c1 = new City("c1", 20, 50);
    City *c2 = new City("c2", 234, 125);
    City *c3 = new City("c3", -284, 243);
    City *c4 = new City("c4", -203, 50);
    City *c5 = new City("c5", 200, -100);
    map.addCity(c1);
    map.addCity(c2);
    map.addCity(c3);
    map.addCity(c4);
    map.addCity(c5);
    //some Streets to connect
    Street *s1 = new Street(c1, c2);
    Street *s2 = new Street(c2, c3);
    Street *s3 = new Street(c3, c4);
    Street *s4 = new Street(c4, c5);
    Street *s5 = new Street(c5, c1);
    Street *s6 = new Street(c1, c3);
    Street *s7 = new Street(c2, c4);
    Street *s8 = new Street(c3, c5);
    Street *s9 = new Street(c4, c1);
    Street *s10 = new Street(c5, c2);
    map.addStreet(s1);
    map.addStreet(s2);
    map.addStreet(s3);
    map.addStreet(s4);
    map.addStreet(s5);
    map.addStreet(s6);
    map.addStreet(s7);
    map.addStreet(s8);
    map.addStreet(s9);
    map.addStreet(s10);
    map.draw(scene);


}


void MainWindow::on_checkBox_HideTestButtons_clicked()
{
    if(ui->checkBox_HideTestButtons->isChecked()) {
        ui->pushButton_TestDrawCity->hide();
        ui->pushButton_TestDrawMapWithCities->hide();
        ui->pushButton_TestDrawStreet->hide();
        ui->pushButton_TestDrawFullMap->hide();
        ui->pushButton_TestAbstractMap->hide();
        ui->pushButton_TestDijkstra->hide();
    } else {
        ui->pushButton_TestDrawCity->show();
        ui->pushButton_TestDrawMapWithCities->show();
        ui->pushButton_TestDrawStreet->show();
        ui->pushButton_TestDrawFullMap->show();
        ui->pushButton_TestAbstractMap->show();
        ui->pushButton_TestDijkstra->show();
    }
}


void MainWindow::on_pushButton_AddCity_clicked()
{
    qDebug() << "on_pushButton_AddCity_clicked";
    int returnValue;
    AddCityDialog *addCityDialog = new AddCityDialog();
    do {
        returnValue = addCityDialog->exec();
    } while(returnValue == 2 || map.findCity(addCityDialog->getCityName()) != NULL);              // 2 -> Input invalid
    if(returnValue == QDialog::Rejected)    // close Button was clicked
        return;


    qDebug() << "Input registered";
    this->map.addCity(addCityDialog->createCity());
    this->map.draw(this->scene);

}


void MainWindow::on_pushButton_FillMap_clicked()
{
    mapIo->fillMap(map);
    map.draw(scene);
}



void MainWindow::on_pushButton_TestAbstractMap_clicked()
{
    testAbstractMap();
}


void MainWindow::testAbstractMap()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}

void MainWindow::on_pushButton_TestDijkstra_clicked()
{
    QVector<Street*> path = Dijkstra::search(map, "Bonn", "Aachen");
    for(auto street : path )
    {
        qDebug() << *street;
        street->drawRed(scene);
    }
}


void MainWindow::on_pushButton_Wayfinder_clicked()
{
    SearchDialog *searchDialog = new SearchDialog();
    if(searchDialog->exec() == QDialog::Accepted) {
        if(searchDialog->inputEmpty())
            return;
        scene.clear();
        map.draw(scene);
        QVector<Street*> path = Dijkstra::search(map, searchDialog->getCityFrom(), searchDialog->getCityTo());
        for(auto street : path )
        {
            qDebug() << *street;
            street->drawRed(scene);
        }
    }
}


void MainWindow::on_pushButton_AddStreet_clicked()
{
    qDebug() << "on_pushButton_AddStreet_clicked";
    int returnValue;
    AddStreetDialog *addStreetDialog = new AddStreetDialog(&map);
    do {
        returnValue = addStreetDialog->exec();
    } while(returnValue == 2);              // 2 -> Input invalid
    if(returnValue == QDialog::Rejected)    // close Button was clicked
        return;


    qDebug() << "Input registered";
    this->map.addStreet(addStreetDialog->createStreet());
    qDebug() << "Street was successfully added";
    this->map.draw(this->scene);
}


void MainWindow::on_actionOpen_triggered()
{
    QString citiesFileName = QFileDialog::getOpenFileName(
        this,
        tr("Open Cities file"),
        QStandardPaths::writableLocation(QStandardPaths::HomeLocation),
        tr("Text Files (*.txt)")
        );
    if (citiesFileName.isEmpty()) return;

    QString streetsFileName = QFileDialog::getOpenFileName(
        this,
        tr("Open Streets file"),
        "",
        tr("Text Files (*.txt)")
        );
    if (streetsFileName.isEmpty()) return;


    MapIoFileinput *fileInput = new MapIoFileinput(citiesFileName, streetsFileName);
    this->mapIo = fileInput;
    this->mapIo->fillMap(map);
    this->map.draw(scene);
}

