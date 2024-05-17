#include "Medium.h"
#include <string>

class DVD : public Medium
{
public:
    DVD(std::string initTitel, int initAltersFreigabe, std::string initGenre);
    void ausgabe() const;
    bool ausleihen(Person person, Datum ausleihdatum);

private:
    int altersFreigabe;
    std::string genre;
};