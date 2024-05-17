#include "Medium.h"
#include <string>

class Buch : public Medium
{
public:
    Buch(std::string initTitel, std::string initAutor);
    void ausgabe() const;

private:
    std::string autor;
};
