#include "map.h"

Map::Map() {}


void Map::addCity(City *pCity) {
    if(pCity == nullptr){
        qDebug() << "Argument given to Map::addCity(City *pCity) was a nullptr";
        return;
    }
    qDebug() << "adding City " << pCity->getName() << " to the cities List";
    cities.push_back(pCity);
}


bool Map::addStreet(Street* street)
{
    for (City* city : street->getCities()) {
        if (std::find(cities.begin(), cities.end(), city) == cities.end()) {//points to the end of the vector if the city is not found
            qDebug() << "Cannot add street. Not all cities of the street are added to the map.";
            return false;
        }
    }
    streets.push_back(street);
    qDebug() << "added" << *street;
    return true;
}


void Map::draw(QGraphicsScene &scene) {
    for(Street *s : streets)
        s->draw(scene);
    for(City *c : cities)
        c->draw(scene);

}


City* Map::findCity(const QString cityName) const
{
    for(auto city : cities) {
        if (city->getName() == cityName) {
            return city;
        }
    }
    return nullptr;
}


QVector<City*> Map::getCities() const
{
    return cities;
}


QStringList Map::getCityNames() const
{
    QStringList city_names;
    for(auto city : cities) {
        city_names.push_back(city->getName());
    }
    return city_names;
}


QVector<Street*> Map::getStreetList(const City* city) const
{
    QVector<Street*> street_list;
    for(auto street : streets) {
        if (street->getCities().contains(city)) {
            street_list.push_back(street);
        }
    }
    return street_list;
}


City* Map::getOppositeCity(const Street* street, const City* city) const
{
    if (street->getCities().contains(city)) {
        if (street->getCities()[0] == city) {
            return street->getCities()[1];
        }
        else {
            return street->getCities()[0];
        }
    }
    return nullptr;
}


double Map::getLength(const Street* street) const
{
    return street->getLength();
}


void Map::clear() {
    cities.clear();
    streets.clear();
}
