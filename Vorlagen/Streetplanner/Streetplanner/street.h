#ifndef STREET_H
#define STREET_H

#include "city.h"

class Street
{
public:
    Street(City*, City*);
    operator QString() const;
    void draw(QGraphicsScene &scene);
    void drawRed(QGraphicsScene& scene);
    QVector<City*> getCities() const;
    double getLength() const;


private:
    City *c1;
    City *c2;

};

#endif // STREET_H
