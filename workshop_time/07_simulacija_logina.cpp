#include <ctime>
#include <iostream>

int main() {
    std::cout << "=== Vjezba: Simulacija logina (zakljucavanje pokusaja) ===\n\n";

    std::time_t vrijeme_zadnjeg_pokusaja = 0;
    std::time_t trenutno_vrijeme = std::time(nullptr);

    // Zadatak: dozvoli pokusaj logina tek nakon 10 sekundi
    if (trenutno_vrijeme - vrijeme_zadnjeg_pokusaja < 10) {
        std::cout << "Prebrzo pokusavas. Sacekaj jos malo.\n";
    } else {
        std::cout << "Pokusaj logina je dozvoljen.\n";
        vrijeme_zadnjeg_pokusaja = trenutno_vrijeme;
    }

    return 0;
}
