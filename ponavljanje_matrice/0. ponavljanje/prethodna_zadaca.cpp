#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    #define RJESENJE1
    #ifdef RJESENJE1










    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || i == n - 1) cout << '*';
            else if (j == 0 || j == n - 1) cout << '*';
            else if (i == j) cout << '*';
            else if (i + j == n - 1) cout << '*';
            else cout << ' ';
        }
        cout << endl;
    }
    
    cout << endl;



    







    #endif


    #ifdef RJESENJE2








    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool zvjezdica = 0;
            if (i == 0 || i == n - 1) zvjezdica = 1;
            else if (j == 0 || j == n - 1) zvjezdica = 1;
            else if (i == j) zvjezdica = 1;
            else if (i + j == n - 1) zvjezdica = 1;
            
            if (zvjezdica) {
                cout << '*';
            }
            else {
                cout << ' ';
            }
        }
        cout << endl;
    }

    cout << endl;









    #endif

    #ifdef RJESENJE3







    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool zvjezdica = 0;
            zvjezdica |= (i == 0 || i == n - 1);
            zvjezdica |= (j == 0 || j == n - 1);
            zvjezdica |= (i == j);
            zvjezdica |= (i + j == n - 1);

            if (zvjezdica) {
                cout << '*';
            }
            else {
                cout << ' ';
            }
        }
        cout << endl;
    }










    #endif


    return 0;
}