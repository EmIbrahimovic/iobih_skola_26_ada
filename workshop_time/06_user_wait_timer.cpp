#include <ctime>
#include <iostream>

int main() {
    std::time_t pocetak = std::time(nullptr);

    std::cout << "Pritisni Enter kada budes spreman/spremna...\n";
    std::cin.get();

    std::time_t kraj = std::time(nullptr);

    std::cout << "Cekao/Cekala si " << (kraj - pocetak) << " sekundi.\n";
    return 0;
}
