#include "Medium.h"
#include <string>

class DVD : public Medium
{
public:
    DVD(std::string initTitel, int initAltersFreigabe, std::string initGenre);

    /**
     * @brief Ausgabefunktion
     * Überladene Funktion aus Medium
    */
    void ausgabe() const;

    /**
     * @brief Ausleihen-Funktion
     * Eine DVD kann nur ausgeliehen werden, wenn die Altersfreigabe eingehalten wird
     * 
     * @param person Person die das Medium ausleihen möchte
     * @param ausleihdatum Datum an dem das Medium ausgeliehen wird
     * 
     * @return true, wenn die Ausleihbeschränkungen erfüllt sind und das Medium ausgeliehen werden kann
    */
    bool ausleihen(Person person, Datum ausleihdatum);

private:
    int altersFreigabe;
    std::string genre;
};