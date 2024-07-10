#include "map.h"

Map::Map() {}


/**
 * @brief adds a city to the map
 * 
 * @param pCity pointer to the city object
 */
void Map::addCity(City *pCity) {
    if(pCity == nullptr){
        qDebug() << "Argument given to Map::addCity(City *pCity) was a nullptr";
        return;
    }
    qDebug() << "adding City " << pCity->getName() << " to the cities List";
    cities.push_back(pCity);
}


/**
 * @brief adds a street to the map
 * 
 * @param street pointer to the street object
 * @return true if the street was added successfully
 */
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


/**
 * @brief draws all cities and streets on the scene
 * 
 * @param scene reference to the scene
 */
void Map::draw(QGraphicsScene &scene) {
    for(Street *s : streets)
        s->draw(scene);
    for(City *c : cities)
        c->draw(scene);

}


/**
 * @brief finds a city by its name
 * 
 * @param cityName name of the city
 * @return City* pointer to the city object
 */
City* Map::findCity(const QString cityName) const
{
    for(City *city : cities) {
        if (city->getName() == cityName) {
            return city;
        }
    }
    return nullptr;
}


/**
 * @brief returns all cities of the map
 * 
 * @return Vector of all City pointers
 */
QVector<City*> Map::getCities() const
{
    return cities;
}


/**
 * @brief returns all city names of the map
 * 
 * @return QStringList of all city names
 */
QStringList Map::getCityNames() const
{
    QStringList city_names;
    for(auto city : cities) {
        city_names.push_back(city->getName());
    }
    return city_names;
}


/**
 * @brief returns all streets of the map
 * 
 * @param city pointer to the city object
 * @return QVector of all street pointers
 */
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


/**
 * @brief returns the opposite city for a given street and city
 * 
 * @param street pointer to the street object
 * @param city pointer to the city object
 * @return City* pointer to the opposite city along the street
 */
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


/**
 * @brief returns the length of a street
 * 
 * @param street pointer to the street object
 * @return double length of the street
 */
double Map::getLength(const Street* street) const
{
    return street->getLength();
}


/**
 * @brief clears the map
 * 
 */
void Map::clear() {
    for(City* city : cities)
        delete city;
    for(Street* street : streets)
        delete street;
    cities.clear();
    streets.clear();
}
