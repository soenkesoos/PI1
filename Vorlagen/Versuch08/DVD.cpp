#include "DVD.h"
#include "Medium.h"
#include <iostream>

DVD::DVD(std::string initTitel, int initAltersFreigabe, std::string initGenre) : Medium(initTitel)
{
    altersFreigabe = initAltersFreigabe;
    genre = initGenre;
}

void DVD::ausgabe() const
{
    Medium::ausgabe();
    std::cout << "Altersfreigabe: " << altersFreigabe << std::endl;
    std::cout << "Genre: " << genre << std::endl;
}

bool DVD::ausleihen(Person person, Datum ausleihdatum)
{
    if (ausleihdatum - person.getGeburtsdatum() < altersFreigabe*12)
    {
        std::cout << "Die Person ist zu jung um die DVD \"" << titel << "\" auszuleihen!" << std::endl;
        return false;
    }
    else if (Medium::ausleihen(person, ausleihdatum))
        return true;
    
    return false;
}