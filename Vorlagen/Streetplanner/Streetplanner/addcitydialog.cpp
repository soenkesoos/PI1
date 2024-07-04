#include "addcitydialog.h"
#include "ui_addcitydialog.h"

AddCityDialog::AddCityDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddCityDialog)
{
    ui->setupUi(this);
}

AddCityDialog::~AddCityDialog()
{
    delete ui;
}

QString AddCityDialog::getCityName()
{
    return ui->input_name->text();
}

int AddCityDialog::getX()
{
    return ui->input_x->text().toInt();
}

int AddCityDialog::getY()
{
    return ui->input_y->text().toInt();
}

City* AddCityDialog::createCity() {
    City *returnCity = new City(getCityName(), getX(), getY());
    return returnCity;
}

bool AddCityDialog::isInputValid() {
    if(ui->input_name->text().isEmpty()) return false;
    if(ui->input_x->text().isEmpty()) return false;
    if(ui->input_y->text().isEmpty()) return false;
    return true;
}

void AddCityDialog::on_input_name_textChanged(const QString &arg1)
{
    cityName = arg1;
}

void AddCityDialog::on_input_x_textChanged(const QString &arg1)
{
    x = arg1.toInt();
}

void AddCityDialog::on_input_y_textChanged(const QString &arg1)
{
    y = arg1.toInt();
}

void AddCityDialog::on_buttonBox_accepted()
{
    if(isInputValid()) {
        done(QDialog::Accepted);    // QDialog::Accepted == 1
        qDebug() << "Input was valid";
    } else {
        done(2);                    // new Value 2 for invalid Input
        qDebug() << "Input was invalid";
    }
}


void AddCityDialog::on_buttonBox_rejected()
{
    done(QDialog::Rejected);        // QDialog::Rejected == 0
}
