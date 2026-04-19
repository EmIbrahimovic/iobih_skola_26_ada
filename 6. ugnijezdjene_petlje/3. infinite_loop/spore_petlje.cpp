#include <iostream>
#include <ctime>
#include <cmath>

using namespace std;

// #define VRIJEME
#define TIME_IT(label, code) \
    { \
        auto _start = clock(); \
        code; \
        auto _end = clock(); \
        auto _s = (_end - _start) * 1.0 / CLOCKS_PER_SEC; \
        std::cout << label << ": " << _s << " s\n"; \
    }
#define UGN
// #define PITAGORA

int main() {

    
    for (int i = 0; i < 1000000; i++) {}





















    // MARK: Vrijeme
    #ifdef VRIJEME


    float start_time = clock();




    // 10^6 = milion koraka
    for (int i = 0; i < 1000000; i++) {
        // nista
    }
    cout << "Gotovo" << endl;
    cout << "Prvoj petlji je trebalo: " << (clock() - start_time)/CLOCKS_PER_SEC << " s" << endl;

    start_time = clock();

    // 10^9 koraka = milijarda koraka
    for (long long i = 0; i < 1000000000; i++) {}
    cout << "Gotovo" << endl;
    cout << "Drugoj petlji je trebalo: " << (clock() - start_time)/CLOCKS_PER_SEC << " s" << endl;

    start_time = clock();

    // 10^10 koraka = 10 milijardi koraka
    for (long long i = 0; i < (long long)10000000000; i++) {}
    cout << "Gotovo" << endl;
    cout << "Trecoj petlji je trebalo: " << (clock() - start_time)/CLOCKS_PER_SEC << " s" << endl;



    #endif

































    #ifdef UGN

    // MARK: Ugnijezdjena
    float start_time = clock(); 




    int n = 100000; // 10^5, dakle 100 hiljada
    long long broj_izvrsavanja = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            broj_izvrsavanja++;
        }
    }
    cout << broj_izvrsavanja << endl;
    cout << (long long)100000*100000 << endl;

    cout << "Gotovo" << endl;
    cout << "Ugnijezdjenoj petlji je trebalo: " 
    << (clock() - start_time)/CLOCKS_PER_SEC 
    << " s" << endl;




    #endif


































    #ifdef PITAGORA
    // MARK: Pitagorine trojke
    /*
    Prebrojati sve trojke brojeva a, b, c manjih od n takve da vrijedi a^2 + b^2 = c^2.
    */
    TIME_IT("Prvoj nacinu je trebalo ", {
    int n = 5000;
    int broj_trojki = 0;
    for (int a = 1; a <= n; a++) {
        for (int b = a; b <= n; b++) {
            for (int c = b; c <= n; c++) {
                if (a*a + b*b == c*c) {
                    // cout << "a = " << a << "    b = " << b << "    c = " << c << endl;
                    broj_trojki++;
                } 
            }
        }
    }
    cout << broj_trojki << endl;
    })

    
    TIME_IT("Drugom nacinu je trebalo", {
    int broj_trojki = 0;
    int n = 5000;
    for (int a = 1; a <= n; a++) {
        for (int b = a; b <= n; b++) {
            int c_kvadrat = a*a + b*b;
            if (c_kvadrat > n*n) break;

            int c = 1;
            while (c * c < c_kvadrat) {
                c++;
            }

            if (c*c == c_kvadrat) {
                // cout << "a = " << a << "    b = " << b << "    c = " << c << endl;
                broj_trojki++;
            }
        }
    }
    cout << broj_trojki << endl;
    })

    
    TIME_IT("Trecem nacinu je trebalo", {
    int broj_trojki = 0;
    int n = 5000;
    for (int a = 1; a <= n; a++) {
        for (int b = a; b <= n; b++) {
            int c_kvadrat = a*a + b*b;
            if (c_kvadrat > n*n) break;

            int c_pokusaj = sqrt(c_kvadrat);
            if (c_pokusaj*c_pokusaj == c_kvadrat) {
                // cout << "a = " << a << "    b = " << b << "    c = " << c << endl;
                broj_trojki++;
            }
        }
    }
    cout << broj_trojki << endl;
    })

    #endif















    cout << endl;
    return 0;
}
