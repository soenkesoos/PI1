/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

struct Person
{
    std::string sVorname;
    std::string sNachname;
    int iGeburtsjahr;
    int iAlter;
};

void printIDCard(Person person) {
    unsigned long breite = 40;
    std::string name = person.sVorname + " " + person.sNachname;
    std::string geburtsjahrStr = "Geburtsjahr: " + std::to_string(person.iGeburtsjahr);
    std::string alterStr = "Alter: " + std::to_string(person.iAlter);

    std::cout << std::endl << std::string(breite + 13, '#') << std::endl;
    std::cout << "#" << std::string(breite - 2, ' ') << "⢠⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⣤⡄" << "#" << std::endl;
    std::cout << "# " << "Blue Card" << std::string(breite - 12, ' ') << "⢸⠀⠀⠀⠀⣀⣄⡀⠀⠀⠀⢸⡇" << "#" << std::endl;
    std::cout << "#" << std::string(breite - 2, ' ') << "⢸⠀⠀⠀⣼⣿⣿⣿⡆⠀⠀⢸⡇" << "#" << std::endl;
    std::cout << "# " << name << std::string(breite - name.length() - 3, ' ') << "⢸⠀⠀⠀⢻⣿⣿⣿⠇⠀⠀⢸⡇" << "#" << std::endl;
    std::cout << "# " << geburtsjahrStr << std::string(breite - geburtsjahrStr.length() - 3, ' ') << "⢸⠀⠀⠀⣀⠙⠛⢁⣀⠀⠀⢸⡇" << "#" << std::endl;
    std::cout << "# " << alterStr << std::string(breite - alterStr.length() - 3, ' ') << "⢸⠀⢀⣾⣿⣿⣿⣿⣿⣧⠀⢸⡇" << "#" << std::endl;
    std::cout << "# " << "Student of RWTH-Aachen University" << std::string(breite - 36, ' ') << "⢸⢀⣾⣿⣿⣿⣿⣿⣿⣿⣇⢸⡇" << "#" << std::endl;
    std::cout << "#" << std::string(breite - 2, ' ') << "⢸⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣼⡇" << "#" << std::endl;
    std::cout << std::string(breite + 13, '#') << std::endl;
}


int main()
{
    Person nBenutzer;

    std::cout << std::endl << std::endl << "Bitte geben Sie Ihren Vornamen ein: ";
    std::cin >> nBenutzer.sVorname;
    std::cout << "Bitte geben Sie Ihren Nachnamen ein: ";
    std::cin >> nBenutzer.sNachname;
    std::cout << "Bitte geben Sie Ihr Geburtsjahr ein: ";
    std::cin >> nBenutzer.iGeburtsjahr;
    std::cout << "Bitte geben Sie Ihr Alter ein: ";
    std::cin >> nBenutzer.iAlter;

    printIDCard(nBenutzer);


    Person nKopieEinzeln;
    nKopieEinzeln.sVorname = nBenutzer.sVorname;
    nKopieEinzeln.sNachname = nBenutzer.sNachname;
    nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
    nKopieEinzeln.iAlter = nBenutzer.iAlter;

    Person nKopieGesamt = nBenutzer;

    printIDCard(nKopieEinzeln);
    printIDCard(nKopieGesamt);


    return 0;
}


