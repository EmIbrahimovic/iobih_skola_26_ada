#include <ctime>
#include <iostream>

int main() {
    std::time_t sada = std::time(nullptr);

    if ((sada % 86400) == 0) {
        std::cout << "Tacno je ponoc po UTC vremenu!\n";
    } else {
        std::cout << "Trenutno nije ponoc po UTC vremenu.\n";
    }

    return 0;
}
