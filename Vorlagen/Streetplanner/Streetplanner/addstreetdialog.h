#ifndef ADDSTREETDIALOG_H
#define ADDSTREETDIALOG_H

#include <QDialog>
#include "street.h"
#include "map.h"
#include "city.h"

namespace Ui {
class AddStreetDialog;
}

class AddStreetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddStreetDialog(Map *map, QWidget *parent = nullptr);
    ~AddStreetDialog();
    QString getCityFrom();
    QString getCityTo();
    Street *createStreet();
    bool isInputValid();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::AddStreetDialog *ui;
    Map *map;
    QString CityFrom;
    QString CityTo;

};

#endif // ADDSTREETDIALOG_H
