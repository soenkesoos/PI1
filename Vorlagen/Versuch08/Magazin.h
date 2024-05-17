#include "Medium.h"
#include "Datum.h"
#include <string>

class Magazin : public Medium
{
public:
    Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
    void ausgabe() const;
    bool ausleihen(Person person, Datum ausleihdatum);

private:
    Datum datumAusgabe;
    std::string sparte;
};