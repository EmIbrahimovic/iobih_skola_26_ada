#include <ctime>
#include <iostream>

int main() {
    std::time_t sada = std::time(nullptr);
    std::time_t sutra = sada + 60 * 60 * 24;

    std::cout << "Trenutno Unix vrijeme: " << sada << '\n';
    std::cout << "Unix vrijeme za 24 sata: " << sutra << "\n\n";

    std::time_t pocetak = std::time(nullptr);

    // Pravimo se da nesto traje...
    for (volatile int i = 0; i < 100000000; ++i) {
    }

    std::time_t kraj = std::time(nullptr);

    double sekunde = std::difftime(kraj, pocetak);
    std::cout << "Proslo vrijeme: " << sekunde << " sekundi\n\n";

    std::cout << "Zasto je ovo vazno:\n";
    std::cout << "- Koristi se za mjerenje performansi\n";
    std::cout << "- Koristi se za tajmere u igrama\n";
    std::cout << "- Koristi se skoro svuda\n";

    return 0;
}
