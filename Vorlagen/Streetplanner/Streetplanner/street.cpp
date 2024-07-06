#include "street.h"

Street::Street(City *pC1, City *pC2) : c1(pC1), c2(pC2) {}

Street::operator QString() const
{
    return QString("Street from %1 to %2").arg(c1->getName()).arg(c2->getName());
}

/**
 * @brief draws the street on the scene
 * 
 * @param scene QGraphicsScene
 */
void Street::draw(QGraphicsScene &scene) {
    scene.addLine(c1->getX()+5, c1->getY()+5, c2->getX()+5, c2->getY()+5,QPen(Qt::gray));
}

/**
 * @brief draws the street on the scene, but in red
 * 
 * @param scene QGraphicsScene
 */
void Street::drawRed(QGraphicsScene& scene) {
    scene.addLine(c1->getX()+5, c1->getY()+5, c2->getX()+5, c2->getY()+5,QPen(Qt::red, 4));
}

/**
 * @brief returns the cities of the street
 * 
 * @return QVector<City*> 
 */
QVector<City*> Street::getCities() const {
    QVector<City*> cities;
    cities.append(c1);
    cities.append(c2);
    return cities;
}

/**
 * @brief returns the length of the street
 * 
 * @return double 
 */
double Street::getLength() const {
    int xDistance = c1->getX() - c2->getX();
    int yDistance = c1->getY() - c2->getY();
    return sqrt(xDistance*xDistance + yDistance*yDistance);
}
