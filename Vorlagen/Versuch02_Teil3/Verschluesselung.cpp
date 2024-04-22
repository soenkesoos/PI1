///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

string verschluesseln(const char schluessel[2][26], string wort)
{
	transform(wort.begin(), wort.end(), wort.begin(), ::toupper);
	for (char& c : wort)	// für jeden char im string
	{
		for (int i = 0; i < 26; i++)	// für jeden Buchstaben im Schluessel...
		{
			if (schluessel[0][i] == c)	// ...wird nach einem match gesucht
			{
				c = schluessel[1][i];	// und der verschlüsselte Buchstabe ersetzt den ursprünglichen
				break;
			}
		}
	}

	return wort;
}

string entschluesseln(const char schluessel[2][26], string wort)
{
	transform(wort.begin(), wort.end(), wort.begin(), ::toupper);
	for (char& c : wort)	// für jeden char im string
	{
		for (int i = 0; i < 26; i++)	// für jeden Buchstaben im Schluessel...
		{
			if (schluessel[1][i] == c)	// ...wird nach einem match gesucht
			{
				c = schluessel[0][i];	// und der entschlüsselte Buchstabe ersetzt den ursprünglichen
				break;
			}
		}
	}

	return wort;
}

int main()
{
	// Hier folgt Ihr Code
	string wort;
	cin >> wort;
	// verschlüsselungsarray eine richtige Lookuptable wäre besser, wie z.B. eine Hashmap oder da wir hier meist nur mit Ascii chars arbeiten werden einfach ein eindimensionales Array
	char schluessel[2][26] = {
    {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'},
    {'Z', 'Y', 'X', 'W', 'V', 'U', 'T', 'S', 'R', 'Q', 'P', 'O', 'N', 'M', 'L', 'K', 'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'}
	};
	
	cout << wort << " --> " << verschluesseln(schluessel, wort) << " --> " << entschluesseln(schluessel, verschluesseln(schluessel, wort)) << endl;

	return 0;
}
