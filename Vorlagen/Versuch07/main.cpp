/** @mainpage
 *
 * Praktikum Informatik 1 MMXXIV <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Student.h"

int main()
{
    std::vector<Student> studentenListe;
    Student student;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.push_back(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.push_back(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.push_back(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.push_back(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wöllnerstr.9");
        studentenListe.push_back(student);
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement vorne hinzufuegen" << std::endl
                  << "(2): Datenelement hinten hinzufuegen" << std::endl
                  << "(3): Datenelement vorne löschen" << std::endl
                  << "(4): Datenelement hinten löschen" << std::endl
                  << "(5): Datenbank ausgeben" << std::endl
                  << "(6): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
                  << "(7): Datenelement löschen" << std::endl
                  << "(8): Datenelemente aus Datei einlesen" << std::endl
                  << "(9): Daten in eine Datei speichern" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
        // Datenelement vorne hinzufuegen
        case '1':
        {
            unsigned int matNr = 0;
            std::string name = "";
            std::string geburtstag = "";
            std::string adresse = "";

            std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
            getline(std::cin, name); // ganze Zeile einlesen inklusive aller Leerzeichen

            std::cout << "Geburtsdatum: ";
            getline(std::cin, geburtstag);

            std::cout << "Adresse: ";
            getline(std::cin, adresse);

            std::cout << "Matrikelnummer: ";
            std::cin >> matNr;
            std::cin.ignore(10, '\n');

            student = Student(matNr, name, geburtstag, adresse);

            studentenListe.insert(studentenListe.begin(), student);
        }
        break;

        // Datenelement hinten hinzufuegen
        case '2':
        {
            unsigned int matNr = 0;
            std::string name = "";
            std::string geburtstag = "";
            std::string adresse = "";

            std::cout << "Bitte geben sie die Daten für den Studenten ein.\nName: ";
            getline(std::cin, name); // ganze Zeile einlesen inklusive aller Leerzeichen

            std::cout << "Geburtsdatum: ";
            getline(std::cin, geburtstag);

            std::cout << "Adresse: ";
            getline(std::cin, adresse);

            std::cout << "Matrikelnummer: ";
            std::cin >> matNr;
            std::cin.ignore(10, '\n');

            student = Student(matNr, name, geburtstag, adresse);

            studentenListe.push_back(student);
        }
        break;

        // Datenelement vorne entfernen
        case '3':
        {
            if (!studentenListe.empty())
            {
                student = studentenListe.front();
                std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                std::cout << student;
                studentenListe.erase(studentenListe.begin());
            }
            else
            {
                std::cout << "Die Liste ist leer!\n";
            }
        }
        break;

        // Datenelement hinten entfernen
        case '4':
        {
            if (!studentenListe.empty())
            {
                student = studentenListe.back();
                std::cout << "Der folgende Student wird geloescht:" << std::endl;
                std::cout << student;
                studentenListe.pop_back();
            }
            else
            {
                std::cout << "Die Liste ist leer!\n";
            }
        }
        break;

        // Datenbank vorwaerts ausgeben
        case '5':
        {
            if (!studentenListe.empty())
            {
                std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                for (Student &student : studentenListe)
                {
                    std::cout << student;
                }
            }
            else
            {
                std::cout << "Die Liste ist leer!\n\n";
            }
        }
        break;

        // Datenbank rueckwaerts ausgeben
        case '6':
        {
            if (!studentenListe.empty())
            {
                std::cout << "Inhalt der Liste in umgekehrter Reihenfolge:" << std::endl;
                for (std::vector<Student>::reverse_iterator it = studentenListe.rbegin() ; it != studentenListe.rend(); ++it)
						std::cout << *it;
            }
            else
            {
                std::cout << "Die Liste ist leer!\n\n";
            }
        }
        break;

        // Datenelement loeschen
        case '7':
        {
            unsigned int matNr = 0;
            std::cout << "Bitte geben sie die Matrikelnummer des Studenten ein, den sie loeschen moechten: ";
            std::cin >> matNr;

            std::cin.ignore(1, '\n');

            // Suche nach Matrikelnummer mit std::find
            auto it = std::find_if(studentenListe.begin(), studentenListe.end(), [matNr](const Student& s) {
                return s.getMatNr() == matNr;
            });
            if(it == studentenListe.end())
            {
                std::cout << "Es wurde kein Student mit der Matrikelnummer " << matNr << " gefunden." << std::endl;
                break;
            }
            std::cout << "Der folgende Student wird geloescht:" << std::endl;
            std::cout << *it;
            studentenListe.erase(it);
            break;
        }
        break;

        // Datenelemente aus Datei einlesen
        case '8':
        {
            // Variablen für die Daten
            unsigned int matNr = 0;
            std::string name = "";
            std::string geburtstag = "";
            std::string adresse = "";

            // Dateistream
            std::string dateiname = "studenten.txt";
            std::cout << "Bitte geben sie den Dateinamen ein: ";
            // std::cin >> dateiname;        // Dateiname einlesen (auskommentiert zum testen

            std::ifstream dateiStream(dateiname);
            if (!dateiStream)
            {
                std::cout << "Die Datei konnte nicht geoeffnet werden.\n";
                exit(1);
            }

            dateiStream >> matNr;
            while (!dateiStream.eof())
            {
                // Name einlesen
                // Windows (CRLF), MacOs (CR) oder viele ander UNIX Distros (LF) Zeilenumbruch
                // bei selbst erstellten Dateien
                // die Demodatei braucht nur LF
                dateiStream.ignore(1, 13); // LF ignorieren
                dateiStream.ignore(1, 10); // CR ignorieren

                std::getline(dateiStream, name);
                name.erase(std::remove(name.begin(), name.end(), '\r'), name.end());

                // Geburtstag einlesen
                std::getline(dateiStream, geburtstag);
                geburtstag.erase(std::remove(geburtstag.begin(), geburtstag.end(), '\r'), geburtstag.end());

                // Adresse einlesen
                std::getline(dateiStream, adresse);
                adresse.erase(std::remove(adresse.begin(), adresse.end(), '\r'), adresse.end());

                // Student erstellen und in Liste einfuegen
                student = Student(matNr, name, geburtstag, adresse);
                studentenListe.push_back(student);

                // Matrikelnummer einlesen
                dateiStream >> matNr;
            }
        }
        break;
                // Daten in eine Datei speichern
        case '9':
        {
            if(studentenListe.empty())
            {
                std::cout << "Es sind keine Daten vorhanden, die abgespeichert werden könnten." << std::endl;

                break;
            }

            std::cout << "Geben sie nun Bitte den Dateinamen an. (ENTER für 'longRandomStudents.txt)'";

            std::string filename;
            getline(std::cin, filename);    // ganze Zeile einlesen inklusive aller Leerzeichen

            if (filename.empty()) filename = "longRandomStudents.txt";

            std::ofstream outputFilestream;
            outputFilestream.open(filename);

            if (!outputFilestream)
            {
                std::cout << " Fehler beim oeffnen der Datei !";
                exit(1) ;
            }

            for(const Student& i : studentenListe) {
                outputFilestream << i.getMatNr() << std::endl;
                outputFilestream << i.getName() << std::endl;
                outputFilestream << i.getGeburtstag() << std::endl;
                outputFilestream << i.getAdresse() << std::endl;
            }

            outputFilestream.close();

            }
            break;
        case 'a':
            std::cout << "Sortieren der Liste nach Matrikelnummer\n";
            std::sort(studentenListe.begin(), studentenListe.end());
            break;

        case '0':
            std::cout << "Das Programm wird nun beendet";
            break;

        default:
            std::cout << "Falsche Eingabe, bitte nochmal";
            break;
        }
    } while (abfrage != '0');

    return 0;
}
