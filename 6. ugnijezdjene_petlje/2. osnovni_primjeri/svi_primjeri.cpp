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
    10x10
    a * b = ab
    a -> 1 2 3 4 .. 10
    b -> 1 2 3 4 .. 10


    Tablica mnozenja
    */
   // 4 * 1
   // 4 * 2
   // 4 * 3 
//    4 * 4
// ... 
//    4 * 10
    cout << "====================================" << endl;
    cout << "==== Tablica mnozenja za broj " << 4 << " ===" << endl;
    cout << "====================================" << endl;
    for (int b = 1; b <= 10; b++) {
        cout << 4 << " * " << b << " = " << 4*b << endl;
    }



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
    int n = 3;
    int suma = 0;
    for (int i = 0; i < n; i++) {

        for (int j = i; j < n; j++) {

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
    /*
    n = 3
    -> [0, 1, 2]
    {0, 0}, {0, 1}, {0, 2}, {1, 1}, {1, 2}, {2, 2}

    */

    int n = 5;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            cout << "{" << i << ", " << j << "}, ";
        }
        cout << endl;
    }
    




    #endif
    #ifdef INTERVALI



    // MARK: Duzi
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
    for (int l = 0; l <= n - 2; l++) {
        for (int d = l + 1; d <= n - 1; d++) {
            cout << l << " - " << d << endl;
        }
        cout << endl;
    }





    // cout << "Broj intervala: " << broj_intervala << endl;






    // for (int d = 1; d < n; d++) {
    //     for (int l = 0; l < n - d; l++) {
    //         int r = n - l;
    //         cout << l << " - " << r << endl;
    //     }
    // }


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