#include <ctime>
#include <iostream>

int main() {
    std::cout << "=== Vjezbe: Unix vrijeme ===\n\n";

    // Zadatak 1: trenutno Unix vrijeme i minuta unaprijed
    std::time_t trenutno_vrijeme = std::time(nullptr);
    std::time_t za_jednu_minutu = trenutno_vrijeme + 60;
    std::cout << "Trenutno Unix vrijeme: " << trenutno_vrijeme << "\n";
    std::cout << "Unix vrijeme za jednu minutu: " << za_jednu_minutu << "\n\n";

    // Zadatak 2: pretvaranje Unix vremena u lokalno vrijeme
    std::tm* lokalno = std::localtime(&trenutno_vrijeme);
    std::cout << "Lokalni datum i vrijeme: "
              << (1900 + lokalno->tm_year) << "-"
              << (1 + lokalno->tm_mon) << "-"
              << lokalno->tm_mday << " "
              << lokalno->tm_hour << ":"
              << lokalno->tm_min << ":"
              << lokalno->tm_sec << "\n\n";

    // Zadatak 3: mjerenje trajanja
    std::time_t pocetak = std::time(nullptr);
    for (volatile int i = 0; i < 100000000; ++i) {
    }
    std::time_t kraj = std::time(nullptr);
    std::cout << "Proslo sekundi: " << std::difftime(kraj, pocetak) << "\n";

    return 0;
}
