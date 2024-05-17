//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXIV
//////////////////////////////////////////////////////////////////////////////

#ifndef LISTE_H_
#define LISTE_H_

#include <iostream>
#include <vector>
#include "Student.h"

class Liste
{
private:
    std::vector<Student> studenten;

public:
    Liste();                                                     // Konstruktor mit Zeigerinitialisierung
    void pushFront(Student student);
    void pushBack(Student student);
    void popFront();
    void popBack();
    void remove(int index);
    void insert(int index, Student student);
    void sort();
    bool empty();
    Student dataFront();
    Student dataBack();
    void ausgabeVorwaerts() const;
    void ausgabeRueckwaerts() const;
    void remove(Student* pElement);
    Student* findElement(unsigned int matNr);
    void deleteElement(Student* pElement);
};

#endif /*LISTE_H_*/
