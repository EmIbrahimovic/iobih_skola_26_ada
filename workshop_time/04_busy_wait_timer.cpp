#include <ctime>
#include <iostream>

int main() {
    std::time_t kraj = std::time(nullptr) + 10;

    while (std::time(nullptr) < kraj) {
        std::cout << "Cekam...\n";
    }

    std::cout << "Gotovo!\n";
    return 0;
}
