#include <ctime>
#include <iostream>

int main() {
    std::cout << "=== Vjezba: Poredjenje dogadjaja u vremenu ===\n\n";

    std::time_t trenutno_vrijeme = std::time(nullptr);
    std::time_t vrijeme_dogadjaja1 = trenutno_vrijeme - 120;
    std::time_t vrijeme_dogadjaja2 = trenutno_vrijeme - 20;
    std::time_t vrijeme_buduceg_dogadjaja = trenutno_vrijeme + 60;

    if (vrijeme_dogadjaja1 < vrijeme_dogadjaja2) {
        std::cout << "Dogadjaj 1 se desio prije dogadjaja 2.\n";
    }

    if (vrijeme_buduceg_dogadjaja > trenutno_vrijeme) {
        std::cout << "Dogadjaj je u buducnosti.\n";
    } else {
        std::cout << "Dogadjaj je u proslosti.\n";
    }

    return 0;
}
