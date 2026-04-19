#include <cmath>
#include <iostream>

int main() {
    std::cout << "=== Vjezbe: Oprez kod uslova ===\n\n";

    // Zadatak 1: = i ==
    int a = 2;
    if (a = 5) {
        std::cout << "Zadatak 1: if (a = 5) je usao u blok jer se vrsi dodjela, a ne poredjenje.\n";
    }

    // Zadatak 2: Lancano poredjenje
    int x = 20;
    std::cout << "Zadatak 2:\n";
    std::cout << "Izraz (3 < x < 10) za x=20 daje: " << (3 < x < 10) << "\n";
    std::cout << "Ispravno je pisati: (3 < x && x < 10) -> " << ((3 < x) && (x < 10)) << "\n\n";

    // Zadatak 3: Poredjenje float brojeva
    float broj_a = 3 * (1.0f / 3.0f);
    float broj_b = 1.0f;
    std::cout << "Zadatak 3:\n";
    std::cout << "broj_a == broj_b -> " << (broj_a == broj_b) << "\n";
    std::cout << "Bolje: fabs(broj_a - broj_b) < 0.0001 -> "
              << (std::fabs(broj_a - broj_b) < 0.0001f) << "\n\n";

    // Zadatak 4: & i &&
    std::cout << "Zadatak 4:\n";
    std::cout << "(2 & 4)  -> " << (2 & 4) << " (bitovni operator)\n";
    std::cout << "(2 && 4) -> " << (2 && 4) << " (logicki operator)\n";

    return 0;
}
