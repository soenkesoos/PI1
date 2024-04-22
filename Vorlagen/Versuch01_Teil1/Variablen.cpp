//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using std::cout;
using std::cin;
int main()
{

    int iErste = 0;
    int iZweite = 0;

    // Hier folgt Ihr eigener Code

    cin >> iErste;
    cin >> iZweite;

    int iSumme = iErste + iZweite;
    int iQuotient = iErste / iZweite; // Achtung iQuotient ist vom typ int, daher wird der Nachkommawert abgeschnitten

    double dSumme = iErste + iZweite;
    double dQuotient = iErste / iZweite; // Hier wird der Nachkommawert immer noch abgeschnitten, da iErste und iZweite vom Typ int sind und das implizite casten zu double erst nach der Division stattfindet

    double dSummeCast = (double)iErste + (double)iZweite;
    double dQuotientCast = (double)iErste / (double)iZweite; // Hier wird der Nachkommawert nicht abgeschnitten, da die Operanden vor der Division explizit zu double gecastet werden (einen der Operanden zu casten hätte gereicht)

    cout << "Die Summe der beiden Zahlen ist: " << iSumme << std::endl;
    cout << "Der Quotient der beiden Zahlen ist: " << iQuotient << std::endl;

    cout << "Die Summe (vom Typ double) der beiden Zahlen ist: " << dSumme << std::endl;
    cout << "Der Quotient (vom Typ double) der beiden Zahlen ist: " << dQuotient << std::endl;

    cout << "Die Summe (vom Typ double) der beiden (zu double gecasteden) Zahlen ist: " << dSummeCast << std::endl;
    cout << "Der Quotient (vom Typ double) der beiden Zahlen ist: " << dQuotientCast << std::endl;

    std::string sVorname;
    std::string sNachname;

    cout << std::endl << std::endl << "Bitte geben Sie Ihren Vornamen ein: ";
    cin >> sVorname;
    cout << "Bitte geben Sie Ihren Nachnamen ein: ";
    cin >> sNachname;

    std::string sVornameName = sVorname + ", " + sNachname;

    cout << std::endl << std::endl << "Ihr Name ist: " << sVornameName << std::endl << std::endl << std::endl;

    {
        int iFeld[2] = {1, 2};
        cout << "iFeld[0] = " << iFeld[0] << std::endl;
        cout << "iFeld[1] = " << iFeld[1] << std::endl;

        int spielfeld[2][3] = {{1, 2, 3}, {4, 5, 6}};
        cout << spielfeld[0][0] << " " << spielfeld[0][1] << " " << spielfeld[0][2] << std::endl;
        cout << spielfeld[1][0] << " " << spielfeld[1][1] << " " << spielfeld[1][2] << std::endl;

        const int iZweite = 2;          // shadowed locale variable iZweite
        cout << iZweite << std::endl;   // Ausgabe: 2
    }
    cout << iZweite << std::endl;    // Ausgabe: vorher eingegebener Wert

    cout << "der ASCII Code von " << sVorname[0] << " ist " << (int)sVorname[0] << " und er steht an der " << (int)sVorname[0]%32 << ". Stelle im Alphabet." << std::endl; // Ausgabe: ASCII-Wert des ersten Zeichens des Vornamens
    cout << "der ASCII Code von " << sVorname[1] << " ist " << (int)sVorname[1] << " und er steht an der " << (int)sVorname[1]%32 << ". Stelle im Alphabet." << std::endl; // Ausgabe: ASCII-Wert des zweiten Zeichens des Vornamens

    return 0;
}
