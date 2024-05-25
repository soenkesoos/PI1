//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#include "Liste.h"

/**
 * @brief Standardkonstruktor, der eine leere Liste erstellt
 */
Liste::Liste() : front(nullptr), back(nullptr)
{
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Anfang der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushFront(Student pData)
{
    ListenElement *neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr && back == nullptr) // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        neuesElement->setNext(front);
        front->setPrev(neuesElement); // front zeigt auf das vorherige Element
        front = neuesElement;
    }
}

/**
 * @brief Hinzufuegen eines neuen Listenelements am Ende der Liste.
 *
 * @param pData Zeiger auf ein Objekt der Klasse Student
 * @return void
 */
void Liste::pushBack(Student pData)
{
    ListenElement *neuesElement = new ListenElement(pData, nullptr, nullptr);

    if (front == nullptr) // Liste leer?
    {
        front = neuesElement;
        back = neuesElement;
    }
    else
    {
        back->setNext(neuesElement);
        neuesElement->setPrev(back); // neuesElement zeigt auf das vorherige Element
        back = neuesElement;
    }
}

/**
 * @brief Entfernen eines Listenelements am Anfang der Liste.
 *
 * @return void
 */
void Liste::popFront()
{
    ListenElement *cursor = front;

    if (front == back) // Liste enthält nur ein Listenelement
    {
        delete front; // Listenelement löschen
        front = nullptr;
        back = nullptr;
    }
    else
    {
        front = front->getNext();
        front->setPrev(nullptr); // Zeiger auf das vorherige Element löschen
        delete cursor;
    }
}


/**
 * @brief Entfernen eines Listenelements am Ende der Liste.
 *
 * @return void
 */
void Liste::popBack()
{
    ListenElement *cursor = back;

    if (back == front) // Liste enthält nur ein Listenelement
    {
        delete back; // Listenelement löschen
        back = nullptr;
        front = nullptr;
    }
    else
    {
        back = back->getPrev();
        back->setNext(nullptr); // Zeiger auf das vorherige Element löschen
        delete cursor;
    }
}

/**
 * @brief Pruefen, ob die Liste leer ist
 *
 * @return wenn leer true, sonst false
 */
bool Liste::empty()
{
    if (front == nullptr && back == nullptr) // back == nullptr ist redundant, aber zur Sicherheit
    {
        return true;
    }
    return false;
}

/**
 * @brief Gibt die Daten des ersten Listenelements in der Liste zurueck
 *
 * @return Zeiger auf ein Objekt der Klasse Student
 */
Student Liste::dataFront()
{
    return front->getData();
}

/**
 * @brief Gibt die Daten des letzten Listenelements in der Liste zurueck
 *
 * @return void
 */
Student Liste::dataBack()
{
    return back->getData();
}

/**
 * @brief Ausgabe der Liste vom ersten bis zum letzten Element.
 *
 * @return void
 */
void Liste::ausgabeVorwaerts() const
{
    ListenElement *cursor = front;

    while (cursor != nullptr)
    {
        cursor->getData().ausgabe();
        cursor = cursor->getNext();
    }
}

/**
 * @brief Ausgabe der Liste vom letzen bis zum ersten Element.
 *
 * @return void
 */
void Liste::ausgabeRueckwaerts() const
{
    ListenElement *cursor = back;

    while (cursor != nullptr)
    {
        cursor->getData().ausgabe();
        cursor = cursor->getPrev();
    }
}

/**
 * @brief Suchen eines Listenelements anhand der Matrikelnummer
 *
 * @param matNr Matrikelnummer des zu suchenden Listenelements
 * @return Zeiger auf das Listenelement, das die Matrikelnummer enthaelt
 */
ListenElement *Liste::search(unsigned int matNr)
{
    if (empty())
    {
        return nullptr;
    }
    ListenElement *cursor = front;
    while (cursor->getData().getMatNr() != matNr)
    {
        cursor = cursor->getNext();
        if (cursor == nullptr)
        {
            return nullptr;
        }
    }
    return cursor;
}

/**
 * @brief Entfernen eines Listenelements aus der Liste
 *
 * @param pElement Zeiger auf das zu entfernende Listenelement
 * @return void
 */
void Liste::remove(ListenElement *pElement)
{

    if (pElement == front) {
				this->popFront();
			} else if (pElement == back) {
				this->popBack();
			} else {

        pElement->getPrev()->setNext(pElement->getNext());
        pElement->getNext()->setPrev(pElement->getPrev());
    }

}
