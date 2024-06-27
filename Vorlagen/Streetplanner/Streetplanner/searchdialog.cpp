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

bool SearchDialog::inputEmpty() {
    return (ui->input_CityFrom->text().isEmpty() || ui->input_CityTo->text().isEmpty());
}

QString SearchDialog::getCityFrom() {
    return ui->input_CityFrom->text();
}

QString SearchDialog::getCityTo() {
    return ui->input_CityTo->text();
}

void SearchDialog::on_input_CityFrom_textChanged(const QString &arg1) {
    City_From = arg1;
}

void SearchDialog::on_input_CityTo_textChanged(const QString &arg1) {
    City_To = arg1;
}

void SearchDialog::on_buttonBox_accepted()
{
    done(QDialog::Accepted);
}


void SearchDialog::on_buttonBox_rejected()
{
    done(QDialog::Rejected);
}

