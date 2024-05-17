#include "Buch.h"
#include "Medium.h"
#include <iostream>
#include <string>


Buch::Buch(std::string initTitel, std::string initAutor) : Medium(initTitel)
{
    autor = initAutor;
}

void Buch::ausgabe() const
{
    Medium::ausgabe();
    std::cout << "Autor: " << autor << std::endl;
}
