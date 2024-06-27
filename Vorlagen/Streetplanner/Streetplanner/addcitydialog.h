#ifndef ADDCITYDIALOG_H
#define ADDCITYDIALOG_H

#include <QDialog>
#include "city.h"

namespace Ui {
class AddCityDialog;
}

class AddCityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCityDialog(QWidget *parent = nullptr);
    ~AddCityDialog();
    QString getCityName();
    int getX();
    int getY();
    City *createCity();
    bool isInputValid();

private slots:
    void on_input_name_textChanged(const QString &arg1);

    void on_input_x_textChanged(const QString &arg1);

    void on_input_y_textChanged(const QString &arg1);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::AddCityDialog *ui;
    QString cityName;
    int x;
    int y;

};

#endif // ADDCITYDIALOG_H
