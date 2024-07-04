#include "addstreetdialog.h"
#include "ui_addstreetdialog.h"

AddStreetDialog::AddStreetDialog(Map *map, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddStreetDialog)
    , map(map)
{
    ui->setupUi(this);
}

AddStreetDialog::~AddStreetDialog()
{
    delete ui;
}

QString AddStreetDialog::getCityFrom() {
    return ui->input_City_from->text();
}

QString AddStreetDialog::getCityTo() {
    return ui->input_City_to->text();
}

Street* AddStreetDialog::createStreet() {
    City *From = map->findCity(getCityFrom());
    City *To = map->findCity(getCityTo());
    Street *street = new Street(From, To);
    return street;
}

bool AddStreetDialog::isInputValid() {
    qDebug() << "1";
    if(getCityFrom().isEmpty()) return false;
    qDebug() << "2";
    if(getCityTo().isEmpty()) return false;
    qDebug() << "3";
    if(map->findCity(getCityFrom()) == NULL) return false;
    qDebug() << "4";
    if(map->findCity(getCityTo()) == NULL) return false;
    qDebug() << "5";

    return true;
}


void AddStreetDialog::on_buttonBox_accepted() {
    if(isInputValid()) {
        done(QDialog::Accepted);
        qDebug() << "Input was valid";
    } else {
        done(2);
        qDebug() << "input was invalid";
    }
}

void AddStreetDialog::on_buttonBox_rejected() {
    qDebug() << "Input was canceled";
    done(QDialog::Rejected);
}
