#include <ctime>
#include <iostream>

int main() {
    std::time_t sada = std::time(nullptr);

    int sekunde = sada % 60;
    int minute = (sada / 60) % 60;
    int sati = (sada / 3600) % 24;

    std::cout << "UTC vrijeme iz Unix zapisa: "
              << sati << ':'
              << minute << ':'
              << sekunde << '\n';

    return 0;
}
