#include <iostream>

using namespace std;

// #define TABLICA
// #define TABELA
// #define PAROVI
#define INTERVALI
// #define AKUMULACIJA

int main() {


    #ifdef TABLICA

    // MARK: Tablica mnozenja
    /*
    Tablica mnozenja
    */
    for (int a = 1; a <= 10; a++) {
        
        cout << endl;
        cout << "====================================" << endl;
        cout << "==== Tablica mnozenja za broj " << a << " ===" << endl;
        cout << "====================================" << endl;
        for (int b = 1; b <= 10; b++) {
            cout << a << " * " << b << " = " << a*b << endl;
        }
        cout << "------------------------------------" << endl;
    }
    

    #endif
    #ifdef TABELA


    // MARK: Tabela
    /*
    Koordinate u tabeli
    */
    int n = 5, m = 7;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << "(" << i << ", " << j << ") ";
        }
        cout << endl;
    }


    #endif


























    #ifdef PAROVI


    // MARK: Neuredjeni parovi
    /*
    Ispisati skup svih neuredjenih parova ciji su elementi brojevi do n.
    Ne ispisivati jednake parove.

    Neuredjeni par je par brojeva takav da nam redoslijed nije bitan. 
    Zapisuje se ovako {a, b}.
    Posto nas redoslijed brojeva ne zanima, par {a, b} je jednak paru {b, a}.
    */
    int n = 5;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << "{" << i << ", " << j << "}, ";
        }
    }
    




    #endif
    #ifdef INTERVALI



    // MARK: Intervali
    /*
    Data je linija na kojoj imamo n tacaka. Svaka tacka je oznacena brojem od 0 do n - 1, redom.
    0   1   2   3   4
    |---|---|---|---|

    Duz je dio linije izmedju dvije tacke i imenujemo je oznakama tih tacaka. 
    npr. duz 1-2 je dio linije izmedju tacaka 1 i 2

    Ispisati imena svih duzi na ovoj liniji.
    1) u bilo kojem redoslijedu
    2) pocevsi od duzi koje pocinju manjim brojevima
    3) pocevsi od najkracih duzi
    */
    int n = 5;
    int broj_intervala = 0;
    for (int l = 0; l < n; l++) {
        for (int r = l + 1; r < n; r++) {
            cout << "" << l << " - " << r << endl;
            broj_intervala++;
        }
    }
    cout << "Broj intervala: " << broj_intervala << endl;


    for (int d = 1; d < n; d++) {
        for (int l = 0; l < n - d; l++) {
            int r = n - l;;
            cout << l << " - " << r << endl;
        }
    }


    #endif
    #ifdef AKUMULACIJA


















    // MARK: Akumulacija
    /*
    Za svaki broj a od 1 do n izracunati sumu brojeva od 1 do tog broja.
    BONUS: takodjer ispisati vrijednost izraza a * (a - 1) /2
    */
    int n = 8;
    for (int i = 1; i <= n; i++) {
        
        int suma = 0;
        for (int j = 1; j <= i; j++) {
            suma += j;
        }

        cout << "Suma brojeva od 1 do " << i << " je " << suma << endl;
        cout << "Vrijednost izraza je " << i * (i - 1) / 2 << endl;
    }
























    #endif


    cout << endl;
    return 0;
}