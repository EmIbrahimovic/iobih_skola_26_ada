#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>
using namespace std;

const int REDOVI    = 20;
const int KOLONE    = 50;
const int GUSTOCA   = 65;  // % šansa da je ćelija drvo pri inicijalizaciji
const int SIRENJE   = 40;  // % šansa da se vatra širi na susjednu ćeliju
const int MAX_KORAKA = 80;
const int PAUZA_MS   = 250;

// Karakteri koji predstavljaju stanja ćelija
char PRAZNO     = '.';
char DRVO       = 'T';
char GORI       = '*';
char IZGORJELO  = 'x';

// ──────────────────────────────────────────────────────────────────────────

void ispisiKartu(vector<vector<char>> karta, int korak) {
    /**
     * Zanimljiva funkcija koja crta nasu kartu u boji i animira je.
     */

    cout << "\033[H"; // vrati kursor na vrh ekrana (za animaciju)
    cout << "=== Simulacija šumskog požara — Korak " << korak << " ===\n";
    cout << '+' << string(KOLONE, '-') << "+\n";
    for (int r = 0; r < REDOVI; r++) {
        cout << '|';
        for (int k = 0; k < KOLONE; k++) {
            char c = karta[r][k];
            if      (c == PRAZNO)    cout << "\033[2m.\033[0m";   // zatamnjeno
            else if (c == DRVO)      cout << "\033[32mT\033[0m";   // zeleno
            else if (c == GORI)      cout << "\033[91m*\033[0m";   // crveno
            else if (c == IZGORJELO) cout << "\033[90mx\033[0m";   // sivo
        }
        cout << "|\n";
    }
    cout << '+' << string(KOLONE, '-') << "+\n";

    int broj_stabala_ = 0, gori_ = 0, izgorjelo_ = 0;
    for (int r = 0; r < REDOVI; r++)
        for (int k = 0; k < KOLONE; k++) {
            if (karta[r][k] == DRVO)      broj_stabala_++;
            if (karta[r][k] == GORI)      gori_++;
            if (karta[r][k] == IZGORJELO) izgorjelo_++;
        }
    cout << "Broj stabala: " << broj_stabala_
         << "  \033[91mGori: " << gori_ << "\033[0m"
         << "  \033[90mIzgorjelo: " << izgorjelo_ << "\033[0m"
         << "    \n";
}

int main() {
    srand(time(0));

    // Zanimljiv video o ovom procesu
    // https://www.youtube.com/watch?v=HBluLfX2F_k&t=2068s

    // Postavi početno drveće
    vector<vector<char>> karta(REDOVI, vector<char>(KOLONE));
    vector<vector<char>> sljedeca(REDOVI, vector<char>(KOLONE));

    for (int r = 0; r < REDOVI; r++)
        for (int k = 0; k < KOLONE; k++)
            if (rand() % 100 < GUSTOCA)
                karta[r][k] = DRVO;
            else
                karta[r][k] = PRAZNO;

    // Postavi početnu vatru po želji
    karta[10][24] = GORI;
    karta[10][25] = GORI;
    karta[ 9][25] = GORI;

    // ── Simulacija ─────────────────────────────────────────────────────────
    cout << "\033[2J"; // očisti ekran jednom na početku

    for (int korak = 0; korak <= MAX_KORAKA; korak++) {
        ispisiKartu(karta, korak);

        // Provjeri da li ima još vatre
        bool imaVatre = false;
        for (int r = 0; r < REDOVI; r++)
            for (int k = 0; k < KOLONE; k++)
                if (karta[r][k] == GORI)
                    imaVatre = true;

        if (!imaVatre) {
            cout << "\nVatra ugašena nakon " << korak << " koraka.\n";
            return 0;
        }

        // Pauzira izvrsavanje programa kako bismo mogli vidjeti promjenu.
        // Promijeni PAUZA_MS da ubrzas ili usporis animaciju!
        this_thread::sleep_for(chrono::milliseconds(PAUZA_MS));

        // ── Izračunaj sljedeće stanje ──────────────────────────────────────
        sljedeca = karta;

        for (int r = 0; r < REDOVI; r++) {
            for (int k = 0; k < KOLONE; k++) {
                if (karta[r][k] != GORI) continue;

                sljedeca[r][k] = IZGORJELO;

                // Provjeri svih 8 susjednih ćelija
                for (int dr = -1; dr <= 1; dr++) {
                    for (int dk = -1; dk <= 1; dk++) {
                        if (dr == 0 && dk == 0) continue;
                        int nr = r + dr;
                        int nk = k + dk;
                        // Preskoci ako smo van granica karte
                        if (nr < 0 || nr >= REDOVI || nk < 0 || nk >= KOLONE) continue;
                        // Zapali susjedni drvo sa vjerovatnocom SIRENJE%
                        if (karta[nr][nk] == DRVO && rand() % 100 < SIRENJE)
                            sljedeca[nr][nk] = GORI;
                    }
                }
            }
        }

        karta = sljedeca;
    }

    ispisiKartu(karta, MAX_KORAKA);
    cout << "\nDostignut maksimalan broj koraka. Vatra još gori.\n";
    return 0;
}
