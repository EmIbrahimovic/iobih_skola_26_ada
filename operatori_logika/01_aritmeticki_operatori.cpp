#include <iostream>

int main() {
    std::cout << "=== Vjezbe: Aritmeticki operatori ===\n\n";

    // Zadatak 1: Cjelobrojno dijeljenje
    int a = 7;
    int b = 3;
    std::cout << "Zadatak 1:\n";
    std::cout << "7 / 3 = " << (a / b) << " (cjelobrojno dijeljenje)\n";
    std::cout << "7 / 3.0 = " << (a / 3.0) << " (decimalno dijeljenje)\n\n";

    // Zadatak 2: Modul i negativni brojevi
    int broj1 = -7;
    int broj2 = 3;
    std::cout << "Zadatak 2:\n";
    std::cout << "-7 % 3 = " << (broj1 % broj2) << "\n";
    std::cout << "Napomena: Kod negativnog prvog broja i rezultat moze biti negativan.\n\n";

    // Zadatak 3: Bool u aritmetici
    bool tacno = true;
    bool netacno = false;
    std::cout << "Zadatak 3:\n";
    std::cout << "true + true = " << (tacno + tacno) << "\n";
    std::cout << "true + false = " << (tacno + netacno) << "\n\n";

    // Zadatak 4: a++ i ++a
    int x = 5;
    int rezultat1 = x++;
    int y = 5;
    int rezultat2 = ++y;

    std::cout << "Zadatak 4:\n";
    std::cout << "Ako je x = 5, rezultat1 = x++ je " << rezultat1 << ", a novi x je " << x << "\n";
    std::cout << "Ako je y = 5, rezultat2 = ++y je " << rezultat2 << ", a novi y je " << y << "\n\n";

    // Zadatak 5: Skraceni operatori dodjele
    int stanje = 10;
    stanje += 4;
    stanje -= 2;
    stanje *= 3;
    std::cout << "Zadatak 5:\n";
    std::cout << "Nakon +=, -=, *= stanje je: " << stanje << "\n";

    return 0;
}
