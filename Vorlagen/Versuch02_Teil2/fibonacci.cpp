//////////////////////////////////////////////////////////////////////////////
// Hinweise: da beide Funktionen zur berechnung int nutzen funktioniren sie nur bis zur 46. Fibonacci-Zahl
//            ab der 47. Fibonacci-Zahl failen beide auf unterschiedliche weisen.
//            behoben werden könnte dies durch verwendung von längeren Datentypen wie z.B. long
//            ich will mich aber vorerst auf int beschränken
//            die Main funktion ist auch ineffizient, da für die jede höhere Fibonacci-Zahl alle vorherigen neu berechnet werden
//            Aber das Limit von 46 ist eh der limitierende Faktor, also wen juckts
//////////////////////////////////////////////////////////////////////////////



#include <iostream>

const double ratio = 1.61803398874989484820458683436563811772030917980576286213544862270526046281890; // goldener Schnitt

int iFibonacci(int n)
{
    int previousFib = 0;
    int currentFib = 1;
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int newFib = previousFib + currentFib ;
        previousFib = currentFib ;
        currentFib = newFib;
    }
    return previousFib;
}


int fib(int prev, int curr, int n)  // prev ist die vorherige Fibonacci-Zahl, curr ist die aktuelle Fibonacci-Zahl und n ist die Anzahl der Fibonacci-Zahlen, die noch berechnet werden müssen
{
    if (n <= 0) // Abbruchbedingung der Rekursion
    {
        return prev;    
    }
    else
    {
        return fib(curr, prev + curr, n - 1); // rekursiver Aufruf
    }
}
int slow_fib(int n){
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    return slow_fib(n-1) + slow_fib(n-2);


}
int rFibonacci(int n)    // for convenience
{
    return fib(0, 1, n);    // Rekursion starten (0 und 1 sind die ersten beiden Fibonacci-Zahlen)
}

int trick17(int n)  // Fibonacci-Zahlen ohne Rekursion berechnen
{
    return (int) (1 / std::sqrt(5) * (std::pow(ratio, n) - std::pow(1 - ratio, n))); // Formel für die n-te Fibonacci-Zahl
}


int main()
{

    int n;
    std::cout << "Wie viele Fibonacci Zahlen sollen berechnet werden: " << std::endl;
    std::cin >> n;
    std::cout << "welche Methode soll verwendet werden?" << std::endl << "1: rekursiv (direkt)" 
    << std::endl << "2: rekursiv (mit Hilfsfunktion)" << std::endl << "3: ohne Rekursion (trick17())" 
    << std::endl << "4: slow rekursiv" << std::endl << "5: Iterativ (iFibonacci())" << std::endl;
    int methode;
    std::cin >> methode;

    for(int i = 0; i <= n; i++)
    {
        switch (methode)
        {
        case 1:
            std::cout << "f(" << i << ") = " << fib(0, 1, i) << std::endl;    //direkt fib() nutzen
            break;
        case 2:
            std::cout << "f(" << i << ") = " << rFibonacci(i) << std::endl;    // fibonacci() benutzen
            break;
        case 3:
            std::cout << "t(" << i << ") = " << trick17(i) << std::endl;    //mit trick17()
            break;
        case 4:
            std::cout << "i(" << i << ") = " << slow_fib(i) << std::endl;    //mit iFibonacci()
            break;
        default:
            std::cout << "i(" << i << ") = " << iFibonacci(i) << std::endl;    //mit iFibonacci()
            break;
        }
    }

    return 0;
}
