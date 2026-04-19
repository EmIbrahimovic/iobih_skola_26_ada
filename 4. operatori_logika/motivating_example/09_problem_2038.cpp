#include <iostream>

int main() {
    std::cout << "=== Vjezba: Problem 2038 ===\n\n";

    int maksimum = 2147483647;
    std::cout << "Maksimalna vrijednost 32-bitnog signed int-a: " << maksimum << "\n";
    std::cout << "Kada uradimo maksimum + 1 dobijamo: " << maksimum + 1 << "\n\n";

    std::cout << "Objasnjenje:\n";
    std::cout << "Na starim 32-bitnim sistemima time_t je 32-bitni integer.\n";
    std::cout << "Kad predje 2.147.483.647 sekundi (19. januar 2038),\n";
    std::cout << "vrijednost preliva i vrijeme postaje pogresno (negativno).\n";

    return 0;
}
