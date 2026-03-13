#include <iostream>

bool jePrestupna(int godina) {
    if (godina % 400 == 0) return true;
    if (godina % 100 == 0) return false;
    return godina % 4 == 0;
}

int main() {
    int godina = 2024;

    if (jePrestupna(godina)) {
        std::cout << godina << " je prestupna godina.\n";
    } else {
        std::cout << godina << " nije prestupna godina.\n";
    }

    return 0;
}
