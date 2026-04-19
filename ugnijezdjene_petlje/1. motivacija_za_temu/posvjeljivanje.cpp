#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"





















#include <iostream>
using namespace std;

int main() {

    // Ucitavamo sliku
    int sirina, visina, broj_kanala;
    unsigned char* slika = stbi_load("./1. motivacija_za_temu/slike/slika2.png", &sirina, &visina, &broj_kanala, 0);



    // Provjeravamo da li smo uspjesno ucitali sliku
    if (slika == NULL) {
        cout << "Nismo mogli ucitati slika.png" << endl;
        return 1;
    }

    cout << "Ucitali sliku: " << sirina << "x" << visina
         << " sa " << broj_kanala << " kanala" << endl;



    // ====== Idemo kroz sliku piksel po piksel mijenjamo R, G, B vrijednost ======
    // Prvo prolazimo kroz svaki red
    for (int red = 0; red < visina; red++) {

        // Zatim unutar svakog reda prolazimo kroz svaku kolonu
        for (int kolona = 0; kolona < sirina; kolona++) {
            

            // Racunamo redni broj piksela
            int pixel_index = (red * sirina + kolona) * broj_kanala;
            // Za dati red i datu kolonu, mijenjamo R, G, B vrijednosti piksela (ali ne i alfa)
            for (int c = 0; c < broj_kanala; c++) {
                // Preskacemo alfa kanal ako je prisutan
                if (c == 3) continue; 

                int vrijednost = slika[pixel_index + c];
                vrijednost = vrijednost + 100; // Povecaj vrijednost pixela 2 puta - povecavamo svjetlinu
                if (vrijednost > 255) vrijednost = 255; // Ako vrijednost postane veca od 255, smanjimo je

                // Postavljamo novu vrijednost piksela
                slika[pixel_index + c] = vrijednost;
            }
        }
    }


    // Sacuvamo promijenjenu sliku
    stbi_write_png("./1. motivacija_za_temu/slike/slika_svijetla.png", sirina, visina, broj_kanala, slika, sirina * broj_kanala);
    cout << "Slika spasena u slika_svijetla.png" << endl;



    // Oslobodimo memoriju koju drzimo od slike
    stbi_image_free(slika);
    return 0;
}
