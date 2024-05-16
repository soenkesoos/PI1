//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

/**
 * @brief Construct a new Vektor::Vektor object
 *
 * @param inX The x-component of the vector
 * @param inY The y-component of the vector
 * @param inZ The z-component of the vector
 */
Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{
}

Vektor::~Vektor()
{
}

/**
 * @brief Function printing the components of the vector
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl
              << std::endl;
}

/**
 * @brief Function subtracting two vectors
 *
 * @param input The vector to subtract from the current vector
 * @return Vektor The resulting vector
 */
Vektor Vektor::sub(const Vektor &input) const
{
    return Vektor(x - input.x, y - input.y, z - input.z);
}

/**
 * @brief Function calculating the length of the vector
 *
 * @return double The length of the vector
 */
double Vektor::laenge() const
{
    return sqrt(x * x + y * y + z * z);
}

/**
 * @brief Function calculating the scalar product of two vectors
 *
 * @param input The vector to calculate the scalar product with
 * @return double The scalar product of the two vectors
 */
double Vektor::skalarProd(const Vektor &input) const
{
    return x * input.x + y * input.y + z * input.z;
}

/**
 * @brief Function calculating the angle between two vectors
 *
 * @param input The vector to calculate the angle with
 * @return double The angle between the two vectors
 */
double Vektor::winkel(const Vektor &input) const
{
    return acos(skalarProd(input) / (laenge() * input.laenge()));
}

/**
 * @brief Function rotating the vector around the z-axis
 *
 * @param rad The angle to rotate the vector by
 */
void Vektor::rotiereUmZ(const double rad)
{
    const Vektor rotMat[] = {Vektor(cos(rad), -sin(rad), 0), // row vectors
                             Vektor(sin(rad), cos(rad), 0),
                             Vektor(0, 0, 1)};

    double xOld = x;
    double yOld = y;
    double zOld = z;
    x = rotMat[0].x * xOld + rotMat[0].y * yOld + rotMat[0].z * zOld;
    y = rotMat[1].x * xOld + rotMat[1].y * yOld + rotMat[1].z * zOld;
    z = rotMat[2].x * xOld + rotMat[2].y * yOld + rotMat[2].z * zOld;
}
