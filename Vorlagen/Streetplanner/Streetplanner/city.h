#include <QString>
#include <QGraphicsScene>
#include <QDebug>
#include <QGraphicsTextItem>

#ifndef CITY_H
#define CITY_H


class City
{
public:
    City(QString name, int x, int y);
    void draw(QGraphicsScene &scene);
    QString getName();
    int getX();
    int getY();

private:
    QString name;
    int x;
    int y;
};


#endif // CITY_H
