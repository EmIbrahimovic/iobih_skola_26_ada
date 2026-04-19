#include <iostream>

int main() {
    std::cout << "=== Vjezbe: Evaluacija izraza i redoslijed operacija ===\n\n";

    // Zadatak 1
    int x = 5;
    bool rezultat = x + 3 > 7 && x % 2 == 1;
    std::cout << "Zadatak 1:\n";
    std::cout << "x + 3 > 7 && x % 2 == 1 -> " << rezultat << "\n\n";

    // Zadatak 2: implicitna konverzija
    int broj = 5;
    bool logicka = broj;
    std::cout << "Zadatak 2:\n";
    std::cout << "int 5 kao bool je: " << logicka << "\n\n";

    // Zadatak 3: 'fun fact' izraz
    int a = 10;
    int b = 20;
    b += a -= 6;
    std::cout << "Zadatak 3:\n";
    std::cout << "Nakon b += a -= 6; dobijamo a=" << a << ", b=" << b << "\n";

    return 0;
}
