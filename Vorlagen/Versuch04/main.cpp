//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

#define earthRadius 6371000
#define eyeHeight (555.7 + 1.7)

bool erdeSichtbar(const double winkel)
{
    const double rad = winkel * M_PI / 180;
    Vektor radiusVektor(earthRadius, 0, 0);
    radiusVektor.rotiereUmZ(rad);
    if (radiusVektor.winkel(radiusVektor.sub(Vektor(earthRadius + eyeHeight, 0, 0))) > M_PI / 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

double getSichtweite(const double winkel)
{
    const double rad = winkel * M_PI / 180;
    Vektor radiusVektor(earthRadius, 0, 0);
    radiusVektor.rotiereUmZ(rad);
    radiusVektor = radiusVektor.sub(Vektor(earthRadius + eyeHeight, 0, 0));
    return radiusVektor.laenge();
}

int main()
{

    const Vektor eye(2, 0, 0);
    Vektor radiusVektor(1, 0, 0);

    double winkel = 15;

    std::cout << std::fixed << std::setprecision(10);

    double increment = 1.0;
    bool lastVisible = true;
    int counter = 0;
    int counter2 = 0;
    while (abs(increment) > 0.0000000001)
    {
        counter++;
        counter2++;
        if (erdeSichtbar(winkel) && !lastVisible)
        {
            std::cout << "Zu weit rückwärts gedreht. Ändere Schrittweite von " << increment << " zu ";
            increment /= -10;
            std::cout << increment << std::endl;
            std::cout << "Winkel: " << winkel << "\tSchritte in diesem Durchlauf: " << counter2 << std::endl;
            counter2 = 0;
        }
        else if (!erdeSichtbar(winkel) && lastVisible)
        {
            std::cout << "Zu weit vorwärts gedreht. Ändere Schrittweite von " << increment << " zu ";
            increment /= -10;
            std::cout << increment << std::endl;
            std::cout << "Winkel: " << winkel << "\tSchritte in diesem Durchlauf: " << counter2 << std::endl;
            counter2 = 0;
        }
        lastVisible = erdeSichtbar(winkel);
        winkel += increment;
    }

    std::cout << std::endl
              << "Sie können " << getSichtweite(winkel) / 1000 << "Km weit sehen." << std::endl;
    std::cout << "Sie sind " << eyeHeight << "Meter hoch." << std::endl;
    std::cout << "Der Winkel beträgt " << winkel << " Grad." << std::endl;
    std::cout << "Anzahl Schritte: " << counter << std::endl;

    return 0;
}
