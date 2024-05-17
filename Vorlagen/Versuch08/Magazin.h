#include "Medium.h"
#include "Datum.h"
#include <string>

class Magazin : public Medium
{
public:
    Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);

    /**
     * @brief Ausgabefunktion
     * Überladene Funktion aus Medium
    */
    void ausgabe() const;

    /**
     * @brief Ausleihen-Funktion
     * Es ist aus den Aufgaben nicht klar, ob ein Magazin, wenn es nicht die aktuelle Ausgabe ist, nicht ausgeliehen werden kann.
     * Siehe 8.7.2: "Ein Magazin kann nur ausgeliehen werden, wenn es die aktuelle Ausgabe ist."
     * 8.7.2 später: "4. Wenn es sich nicht um die neueste Ausgabe des Magazins handelt, nutzen Sie die ausleihen()-Funktion der Basisklasse Medium."
     * 
     * @param person Person die das Medium ausleihen möchte
     * @param ausleihdatum Datum an dem das Medium ausgeliehen wird
     * 
     * @return true, wenn die Ausleihbeschränkungen erfüllt sind und das Medium ausgeliehen werden kann
    */
    bool ausleihen(Person person, Datum ausleihdatum);

private:
    Datum datumAusgabe;
    std::string sparte;
};