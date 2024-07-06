#include "searchdialog.h"
#include "ui_searchdialog.h"

SearchDialog::SearchDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SearchDialog)
{
    ui->setupUi(this);
}

SearchDialog::~SearchDialog()
{
    delete ui;
}

/**
 * @brief checks if the input fields are empty
 * 
 * @return true if the input fields are empty
 */
bool SearchDialog::inputEmpty() {
    return (ui->input_CityFrom->text().isEmpty() || ui->input_CityTo->text().isEmpty());
}

/**
 * @brief returns the city name from the "from" input field
 * 
 * @return QString city name
 */
QString SearchDialog::getCityFrom() {
    return ui->input_CityFrom->text();
}

/**
 * @brief returns the city name from the "to" input field
 * 
 * @return QString city name
 */
QString SearchDialog::getCityTo() {
    return ui->input_CityTo->text();
}

void SearchDialog::on_input_CityFrom_textChanged(const QString &arg1) {
    City_From = arg1;
}

void SearchDialog::on_input_CityTo_textChanged(const QString &arg1) {
    City_To = arg1;
}

/**
 * @brief slot for the accept button
 * 
 */
void SearchDialog::on_buttonBox_accepted()
{
    done(QDialog::Accepted);
}

/**
 * @brief slot for the reject button
 * 
 */
void SearchDialog::on_buttonBox_rejected()
{
    done(QDialog::Rejected);
}

