#include <iostream>

int main() {
    std::cout << "=== Vjezbe: Naredbe grananja (if-else i switch-case) ===\n\n";

    // Zadatak 1: if-else
    int broj = 7;
    if (broj % 2 == 0) {
        std::cout << "Zadatak 1: broj je paran.\n";
    } else {
        std::cout << "Zadatak 1: broj je neparan.\n";
    }

    // Zadatak 2: ternarni operator
    int a = 9;
    int b = 12;
    int maksimum = (a > b) ? a : b;
    std::cout << "Zadatak 2: veci broj je " << maksimum << "\n";

    // Zadatak 3: switch-case
    int izbor = 2;
    std::cout << "Zadatak 3: ";
    switch (izbor) {
        case 1:
            std::cout << "Odabrana je opcija 1.\n";
            break;
        case 2:
            std::cout << "Odabrana je opcija 2.\n";
            break;
        default:
            std::cout << "Odabrana je neka druga opcija.\n";
            break;
    }

    return 0;
}
