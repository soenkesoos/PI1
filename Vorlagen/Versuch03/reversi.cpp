/**
 * Praktikum Informatik 1
 *
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Reversi
 */

/**
 * @mainpage Reversi
 *
 * Dokumentation des Spiels Reversi im Rahmen des Praktikums Informatik 1.
 *
 */

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "reversiKI.h"

/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
    {
        for (int i = 0; i < GROESSE_X; i++)
        {
            spielfeld[j][i] = 0;
        }
    }
    spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
    spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
    spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
    spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}

/**
 * @brief Ausgabe des Spielfelds auf der Konsole
 *
 * Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
 * Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
 *
 *  @param spielfeld  Spielfeld, das ausgeben wird
 */
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    // Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char)i) << " | ";

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
            case 0:
                std::cout << "   ";
                break;
            case 1:
                std::cout << " X ";
                break;
            case 2:
                std::cout << " O ";
                break;
            default:
                std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                std::cout << "Abbruch .... " << std::endl;
                exit(0);
                break;
            }
            std::cout << "|";
        }; // for i
        std::cout << std::endl;
    } // for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }
        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
 * @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
 *
 * @param posX Index fuer die Spalte
 * @param posY Index fuer die Zeile
 * @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
 */
bool aufSpielfeld(const int posX, const int posY)
{
    if ((posX >= 0) && (posX < GROESSE_X) && (posY >= 0) && (posY < GROESSE_Y))
    {
        return true;
    }
    return false;
}

/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       //               if aktuellerSpieler == 2 -> gegner = 1

    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        return false;
    }
    if (!aufSpielfeld(posX, posY)) // ist das Feld auf dem Spielfeld?
    {
        return false;
    }

    // Alle Richtungen ueberpruefen bis ein "Grund" gefunden wird, weshalb der Zug gueltig ist
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            if (i == 0 && j == 0)
                continue; // keine Richtung
            int distance = 1;
            while (aufSpielfeld(posX + i * distance, posY + j * distance) && (spielfeld[posY + j * distance][posX + i * distance] == gegner))
            {
                distance++;
            }
            if (aufSpielfeld(posX + i * distance, posY + j * distance) && (spielfeld[posY + j * distance][posX + i * distance] == aktuellerSpieler) && (distance >= 2))
                return true;
        }
    }
    return false;
}

/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler;

    // Alle Richtungen bearbeiten
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // aehnlich wie die Funktion zugGueltig(), aber stellen Sie sicher, das alle gegnerischen Steine in
            // allen Richtungen in Ihre eigenen Steine umgewandelt werden
            //
            // Hier erfolgt jetzt Ihre Implementierung ...

            if (i == 0 && j == 0)
                continue; // keine Richtung
            int distance = 1;
            while (aufSpielfeld(posX + i * distance, posY + j * distance) && spielfeld[posY + j * distance][posX + i * distance] == gegner)
            {
                distance++;
            }
            if (aufSpielfeld(posX + i * distance, posY + j * distance) && (spielfeld[posY + j * distance][posX + i * distance] == aktuellerSpieler) && (distance >= 2))
            {
                for (int k = 0; k < distance; k++)
                {
                    spielfeld[posY + j * k][posX + i * k] = aktuellerSpieler;
                }
            }
        }
    }
}

/**
 * @brief Funktion, die die Anzahl der moeglichen Zuege berechnet
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return Anzahl der moeglichen Zuege
 */
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    // Hier erfolgt jetzt Ihre Implementierung ...

    // probiert auf jedem Feld, ob ein Zug moeglich ist
    int counter = 0;
    for (int j = 0; j < GROESSE_Y; j++)
    {
        for (int i = 0; i < GROESSE_X; i++)
        {
            if (zugGueltig(spielfeld, aktuellerSpieler, i, j))
            {
                counter++;
            }
        }
    }

    return counter;
}

/**
 * @brief Funktion, die den naechsten Zug eines menschlichen Spielers einliest
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return true, wenn ein Zug moeglich ist, sonst false
 */
bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl
                  << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): ";
        std::cin >> eingabe;
        posX = (int)eingabe[0] % 32 - 1;
        posY = (int)eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            // accept turn;
            break;
        }
        else
        {
            std::cout << std::endl
                      << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl
              << "Spieler " << aktuellerSpieler << " setzt auf " << (char)(posX + 65) << (posY + 1) << std::endl;

    return true;
}

/**
 * @brief Funktion, die das Spiel durchfuehrt
 *
 * @param spielerTyp Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
 */
void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    // Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    int runden = 0;
    int rundenOffset = 4; // Offset fuer die Anzahl der Runden
    int turnsSkipped = 0; // Anzahl der nacheinander Uebersprungenen Zuege (max 2 moeglich)
    zeigeSpielfeld(spielfeld);

    while (runden - rundenOffset < GROESSE_X * GROESSE_Y && turnsSkipped < 2)
    {

        runden++;
        if (spielerTyp[aktuellerSpieler - 1] == MENSCH)
        {
            menschlicherZug(spielfeld, aktuellerSpieler);
        }
        else
        {
            computerZug(spielfeld, aktuellerSpieler);
        }
        std::cout << "Runden : " << runden << std::endl;
        zeigeSpielfeld(spielfeld);

        aktuellerSpieler = 3 - aktuellerSpieler;
        if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
        {
            turnsSkipped++;
            rundenOffset++;
        }
        else
        {
            turnsSkipped = 0;
        }
    }
    std::cout << std::endl;
    switch (gewinner(spielfeld))
    {
    case 0:
        std::cout << "Unentschieden!" << std::endl;
        break;
    case 1:
        std::cout << "Spieler 1 gewinnt!" << std::endl;
        break;
    case 2:
        std::cout << "Spieler 2 gewinnt!" << std::endl;
        break;
    default:
        std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
        std::cout << "Abbruch .... " << std::endl;
        exit(0);
        break;
    }
    std::cout << std::endl;
}

/**
 * @brief Funktion, die den Spielertyp auswaehlt
 *
 * @param spielerTyp Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
 */
void selectGameType(int spielerTyp[2])
{
    std::string eingabe;
    std::cout << "Spieler 1: Mensch(1) oder Computer(2)? ";
    std::cin >> eingabe;
    if (eingabe == "1")
    {
        spielerTyp[0] = MENSCH;
    }
    else
    {
        spielerTyp[0] = COMPUTER;
    }

    std::cout << "Spieler 2: Mensch(1) oder Computer(2)? ";
    std::cin >> eingabe;
    if (eingabe == "1")
    {
        spielerTyp[1] = MENSCH;
    }
    else
    {
        spielerTyp[1] = COMPUTER;
    }
}

/**
 * @brief Funktion, die den Benutzer fragt, ob er nochmal spielen moechte
 *
 * @return true, wenn der Benutzer nochmal spielen moechte, sonst false
 */
bool erneutSpielen()
{
    std::string eingabe;
    std::cout << "Nochmal spielen? (j/n) ";
    std::cin >> eingabe;
    if (eingabe == "j")
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    if (TEST == 1)
    {
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis == true)
        {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        }
        else
        {
            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl
                  << std::endl;
    }

    // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
    // implementiert haben (waeren sonst doppelt)
    /*int spielfeld[GROESSE_Y][GROESSE_X];

    initialisiereSpielfeld(spielfeld);

    zeigeSpielfeld(spielfeld);*/

    bool spielenBool = true;
    while (spielenBool)
    {
        int spielerTyp[2] = {MENSCH, COMPUTER}; // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
        selectGameType(spielerTyp);
        spielen(spielerTyp);
        spielenBool = erneutSpielen();
    }

    // Hier erfolgt jetzt Ihre Implementierung ...

    return 0;
}
