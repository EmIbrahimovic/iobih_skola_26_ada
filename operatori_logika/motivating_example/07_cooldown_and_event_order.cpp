#include <ctime>
#include <iostream>

int main() {
    std::time_t zadnja_akcija = 0;
    std::time_t sada = std::time(nullptr);

    if (sada - zadnja_akcija < 10) {
        std::cout << "Polako!\n";
    } else {
        std::cout << "Akcija dozvoljena.\n";
        zadnja_akcija = sada;
    }

    std::time_t vrijeme_dogadjaja1 = sada - 5;
    std::time_t vrijeme_dogadjaja2 = sada;

    if (vrijeme_dogadjaja1 < vrijeme_dogadjaja2) {
        std::cout << "Dogadjaj 1 se desio prvi.\n";
    }

    return 0;
}
