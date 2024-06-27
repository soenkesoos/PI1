#ifndef SEARCHDIALOG_H
#define SEARCHDIALOG_H

#include <QDialog>
#include <QDebug>
#include "dijkstra.h"

namespace Ui {
class SearchDialog;
}

class SearchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SearchDialog(QWidget *parent = nullptr);
    ~SearchDialog();
    bool inputEmpty();
    QString getCityFrom();
    QString getCityTo();

private slots:
    void on_input_CityFrom_textChanged(const QString &arg1);

    void on_input_CityTo_textChanged(const QString &arg1);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();


private:
    Ui::SearchDialog *ui;
    QString City_From;
    QString City_To;
};

#endif // SEARCHDIALOG_H
