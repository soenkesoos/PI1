#ifndef MAP_H
#define MAP_H


#include <QVector>
#include <QDebug>
#include "city.h"
#include "abstractmap.h"
#include "street.h"

class Map : public AbstractMap
{
public:
    Map();
    void addCity(City *pCity);
    void draw(QGraphicsScene& scene);
    bool addStreet(Street*);
    City* findCity(const QString cityName) const;
    QVector<City*> getCities() const;
    QStringList getCityNames() const;
    QVector<Street*> getStreetList(const City* city) const;
    City* getOppositeCity(const Street* street, const City* city) const;
    double getLength(const Street* street) const;
    void clear();

private:
    QVector<City*> cities;
    QVector<Street*> streets;
};

#endif // MAP_H
