#include "Magazin.h"
#include "Medium.h"
#include <iostream>
#include <string>

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte) : Medium(initTitel)
{
    datumAusgabe = initDatumAusgabe;
    sparte = initSparte;
}

void Magazin::ausgabe() const
{
    Medium::ausgabe();
    std::cout << "Erscheinungsdatum: " << datumAusgabe << std::endl;
    std::cout << "Sparte: " << sparte << std::endl;
}

bool Magazin::ausleihen(Person person, Datum ausleihdatum)
{
    if (ausleihdatum - datumAusgabe > 2)
    {
        std::cout << "Das Medium \"" << titel << "\" kann nicht ausgeliehen werden, da es nicht die aktuelle Ausgabe ist!" << std::endl;
        return false;
    }
    else if(Medium::ausleihen(person, ausleihdatum))
        return true;
    return false;
}