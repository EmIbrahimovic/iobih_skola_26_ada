#include <iostream>
#include <ctime>
#include <unistd.h>
// #include <windows.h>

using namespace std;

#define PRVI_PRIMJER
// #define DRUGI_PRIMJER
// #define TRECI_PRIMJER

int main() {



    #ifdef PRVI_PRIMJER


















    // MARK: odbrojavanje
    
    /*
    Napisati program koji odbrojava vrijeme od n sekundi
    n
    n - 1
    n - 2
    ...
    3
    2
    1
    Gotovo
    */
    int n = 10;
    for (int i = n; i >= 0; i++) {
        cout << "Preostalo je " << i << " sekundi." << endl;
        sleep(1);
    }
    cout << "Vrijeme je proslo!" << endl;























    #endif
    #ifdef DRUGI_PRIMJER

















    // MARK: Los primjer
    /*
    Nadji najvecu cifru n. Oduzi je. Ponovi, dok n ne postane 0. 
    */
    cin >> n;
    while (n != 0) {
        int largest = 0;
        int temp = n;

        while (temp > 0) {
            largest = max(largest, temp % 10);
            temp /= 10;
        }

        n -= largest;
        cout << n << endl;
    }

    cout << "Done" << endl;














    #endif
    #ifdef TRECI_PRIMJER





















    // MARK: overflow
    /*
    Overflow
    */
    cin >> n;

    for (int i = 1; i * i <= n; i++) {
        cout << i << endl;
    }



























    #endif

    return 0;
}
