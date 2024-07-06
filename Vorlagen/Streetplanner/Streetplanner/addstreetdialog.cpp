#include "addstreetdialog.h"
#include "ui_addstreetdialog.h"

/**
 * @brief AddStreetDialog::AddStreetDialog
 * @param map
 * @param parent
 */
AddStreetDialog::AddStreetDialog(Map *map, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddStreetDialog)
    , map(map)
{
    ui->setupUi(this);
}

/**
 * @brief AddStreetDialog::~AddStreetDialog
 */
AddStreetDialog::~AddStreetDialog()
{
    delete ui;
}

/**
 * @brief AddStreetDialog::getCityFrom
 * @return returns the city name the streets starts from
 */
QString AddStreetDialog::getCityFrom() {
    return ui->input_City_from->text();
}

/**
 * @brief AddStreetDialog::getCityTo
 * @return returns the city name the street ends at
 */
QString AddStreetDialog::getCityTo() {
    return ui->input_City_to->text();
}

/**
 * @brief creates a new Street object with the input values
 * 
 * @return Street* 
 */
Street* AddStreetDialog::createStreet() {
    City *From = map->findCity(getCityFrom());
    City *To = map->findCity(getCityTo());
    Street *street = new Street(From, To);
    return street;
}

/**
 * @brief checks if the input is valid
 * 
 * @return true if the input is valid
 */
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


/**
 * @brief AddStreetDialog::on_buttonBox_accepted
 */
void AddStreetDialog::on_buttonBox_accepted() {
    if(isInputValid()) {
        done(QDialog::Accepted);
        qDebug() << "Input was valid";
    } else {
        done(2);
        qDebug() << "input was invalid";
    }
}

/**
 * @brief AddStreetDialog::on_buttonBox_rejected
 */
void AddStreetDialog::on_buttonBox_rejected() {
    qDebug() << "Input was canceled";
    done(QDialog::Rejected);
}
