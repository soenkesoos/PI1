//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"
#include "Student.h"
#include <vector>
#include <algorithm>

/**
 * @brief Standardkonstruktor, der eine leere Liste (eigentlich einen Vector) erstellt
 */
Liste::Liste()
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Anfang der Liste.
 *
 * @param student Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushFront(Student student)
{
    studenten.insert(studenten.begin(), student);
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student student)
{
    studenten.push_back(student);
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    studenten.erase(studenten.begin());
}

/**
 * @brief Entfernen eines Listenelements am Ende der Liste.
 *
 * @return void
 */
void Liste::popBack()
{
    studenten.pop_back();
}

/**
 * @brief entfernen eines Listenelements anhand des Index
 *
 * @return void
 */
void Liste::remove(int index)
{
    auto it = studenten.begin() + index;
    studenten.erase(it);
}

/**
 * @brief löscht listenElement anhand eines Pointer auf das Element
 *
 * @return void
 */
void Liste::remove(Student *pStudent)
{
    auto it = studenten.begin();
    for (Student &student : studenten)
    {
        if (pStudent == &student)
        {
            studenten.erase(it);
        }
        it++;
    }
}

/**
 * @brief Einfuegen eines Listenelements an beliebiger Stelle
 *
 * @param index Index, an dem das Listenelement eingefuegt werden soll
 * @param student Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::insert(int index, Student student)
{
    auto it = studenten.begin() + index;
    studenten.insert(it, student);
}

/**
 * @brief Sortieren der Liste nach Matrikelnummer
 *
 * @return void
 */
void Liste::sort()
{
    std::sort(studenten.begin(), studenten.end());
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    return studenten.empty();
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return studenten.front();
}

/**
 * @brief Gibt die Daten des letzten Listenelements in der Liste zurueck
 *
 * @return void
 */
Student Liste::dataBack()
{
    return studenten.back();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    for (auto it = studenten.begin(); it != studenten.end(); it++)
    {
        std::cout << *it;
    }
}

/**
 * @brief Ausgabe der Liste vom letzen bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
    for (auto rit = Liste::studenten.rbegin(); rit != studenten.rend(); rit++)
    {
        std::cout << *rit;
    }
}

/**
 * @brief Suchen eines Listenelements anhand der Matrikelnummer
 *
 * @param matNr Matrikelnummer des zu suchenden Listenelements
 * @return Zeiger auf das Listenelement, das die Matrikelnummer enthaelt
 */
Student *Liste::findElement(unsigned int matNr)
{
    // Ich bezweifle stark, dass wird das so machen sollen, aber es funktioniert
    auto it = std::find_if(studenten.begin(), studenten.end(), [&matNr](const Student &student)
        { return student.getMatNr() == matNr; });
    if (it != studenten.end())
    {
        // Element gefunden
        return &(*it);
    }
    else
    {
        // Element nicht gefunden
        return nullptr;
    }
}