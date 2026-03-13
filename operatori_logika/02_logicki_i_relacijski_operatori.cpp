#include <iostream>

int main() {
    std::cout << "=== Vjezbe: Logicki i relacijski operatori ===\n\n";

    int lijevi = 3;
    int desni = 5;

    // Zadatak 1: Relacijski operatori
    std::cout << "Zadatak 1 (relacijski operatori):\n";
    std::cout << "3 == 5 -> " << (lijevi == desni) << "\n";
    std::cout << "3 != 5 -> " << (lijevi != desni) << "\n";
    std::cout << "3 < 5  -> " << (lijevi < desni) << "\n";
    std::cout << "3 > 5  -> " << (lijevi > desni) << "\n\n";

    // Zadatak 2: Logicki operatori
    bool uslov1 = true;
    bool uslov2 = false;
    std::cout << "Zadatak 2 (logicki operatori):\n";
    std::cout << "!true = " << (!uslov1) << "\n";
    std::cout << "true && false = " << (uslov1 && uslov2) << "\n";
    std::cout << "true || false = " << (uslov1 || uslov2) << "\n\n";

    // Zadatak 3: int kao logicka vrijednost
    int nenula = 42;
    int nula = 0;
    std::cout << "Zadatak 3 (int u logici):\n";
    std::cout << "Da li je 42 'true'? -> " << (nenula ? "da" : "ne") << "\n";
    std::cout << "Da li je 0 'true'?  -> " << (nula ? "da" : "ne") << "\n\n";

    // Zadatak 4: Short-circuiting
    int a = 0;
    int b = 10;
    std::cout << "Zadatak 4 (short-circuit):\n";
    if (a != 0 && b / a > 2) {
        std::cout << "Uslov je tacan.\n";
    } else {
        std::cout << "Drugi dio nije izvrsen jer je prvi dio false (izbjegnuto dijeljenje s nulom).\n";
    }

    return 0;
}
