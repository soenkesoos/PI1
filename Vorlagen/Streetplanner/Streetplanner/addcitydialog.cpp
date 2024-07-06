#include "addcitydialog.h"
#include "ui_addcitydialog.h"


/**
 * @brief AddCityDialog::AddCityDialog
 * @param parent
 */
AddCityDialog::AddCityDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddCityDialog)
{
    ui->setupUi(this);
}

/**
 * @brief AddCityDialog::~AddCityDialog
 */
AddCityDialog::~AddCityDialog()
{
    delete ui;
}

/**
 * @brief AddCityDialog::getCityName
 * @return
 */
QString AddCityDialog::getCityName()
{
    return ui->input_name->text();
}

/**
 * @brief AddCityDialog::getX
 * @return returns the x value of the input
 */
int AddCityDialog::getX()
{
    return ui->input_x->text().toInt();
}

/**
 * @brief AddCityDialog::getY
 * @return returns the y value of the input
 */
int AddCityDialog::getY()
{
    return ui->input_y->text().toInt();
}

/**
 * @brief creates a new City object with the input values
 * 
 * @return City* 
 */
City* AddCityDialog::createCity() {
    City *returnCity = new City(getCityName(), getX(), getY());
    return returnCity;
}

/**
 * @brief AddCityDialog::isInputValid
 * @return bool
 */
bool AddCityDialog::isInputValid() {
    if(ui->input_name->text().isEmpty()) return false;
    if(ui->input_x->text().isEmpty()) return false;
    if(ui->input_y->text().isEmpty()) return false;
    return true;
}

/**
 * @brief AddCityDialog::on_input_name_textChanged
 * @param arg1
 */
void AddCityDialog::on_input_name_textChanged(const QString &arg1)
{
    cityName = arg1;
}

/**
 * @brief AddCityDialog::on_input_x_textChanged
 * @param arg1
 */
void AddCityDialog::on_input_x_textChanged(const QString &arg1)
{
    x = arg1.toInt();
}

/**
 * @brief AddCityDialog::on_input_y_textChanged
 * @param arg1
 */
void AddCityDialog::on_input_y_textChanged(const QString &arg1)
{
    y = arg1.toInt();
}

/**
 * @brief AddCityDialog::on_buttonBox_accepted
 */
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


/**
 * @brief AddCityDialog::on_buttonBox_rejected
 */
void AddCityDialog::on_buttonBox_rejected()
{
    qDebug() << "Input was canceled";
    done(QDialog::Rejected);        // QDialog::Rejected == 0
}
