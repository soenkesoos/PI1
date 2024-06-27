#include "city.h"

City::City(QString pName, int pX, int pY) : name(pName), x(pX), y(pY) {}

void City::draw(QGraphicsScene &scene) {
    qDebug() << "Drawing City: " << name << " at (" << x << ";" << y << ")";
    scene.addEllipse(x, y, 10, 10, QPen (Qt::red), QBrush(Qt::red, Qt::SolidPattern));
    QGraphicsTextItem *cityNameLabel = new QGraphicsTextItem;
    cityNameLabel->setPlainText(name);
    cityNameLabel->setPos(x, y);
    scene.addItem(cityNameLabel);
}
QString City::getName()
{
    return name;
}
int City::getX()
{
    return x;
}
int City::getY()
{
    return y;
}
