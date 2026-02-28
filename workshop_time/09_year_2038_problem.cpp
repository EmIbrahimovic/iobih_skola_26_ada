#include <iostream>

int main() {
    int maksimum = 2147483647;
    std::cout << "Maksimalni 32-bitni signed int: " << maksimum << '\n';
    std::cout << "maksimum + 1 daje: " << maksimum + 1 << "\n\n";

    std::cout << "Boom — negativan broj.\n\n";

    std::cout << "Objasnjenje:\n";
    std::cout << "Stari sistemi su cuvali Unix vrijeme u 32-bitnom signed int-u.\n";
    std::cout << "Kada vrijednost predje 2.147.483.647 sekundi, dolazi do overflow-a i broj postaje negativan.\n";
    std::cout << "To je problem godine 2038 na starim sistemima.\n";

    return 0;
}
