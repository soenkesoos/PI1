#include "Medium.h"
#include <string>

class Buch : public Medium
{
public:
    Buch(std::string initTitel, std::string initAutor);

    /**
     * @brief Ausgabefunktion
     * Überladene Funktion aus Medium
    */
    void ausgabe() const;

private:
    std::string autor;
};
