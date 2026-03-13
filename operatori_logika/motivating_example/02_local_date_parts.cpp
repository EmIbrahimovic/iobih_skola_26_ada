#include <ctime>
#include <iostream>

int main() {
    std::time_t sada = std::time(nullptr);
    std::tm* lokalno = std::localtime(&sada);

    std::cout << "Godina: " << 1900 + lokalno->tm_year << '\n';
    std::cout << "Mjesec: " << 1 + lokalno->tm_mon << '\n';
    std::cout << "Dan: " << lokalno->tm_mday << '\n';

    return 0;
}
