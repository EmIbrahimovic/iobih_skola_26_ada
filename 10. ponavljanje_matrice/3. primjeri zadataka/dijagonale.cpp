#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cout << "Unijeti velicinu kvadrata: " << endl;
    cin >> n;
    cout << "Unijeti kvadrat: " << endl;

    vector<vector<int> >  kvadrat(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> kvadrat[i][j]; 
        }
    }

    #define RJESENJE1
    #ifdef RJESENJE1

    int suma_dijagonale1 = 0, suma_dijagonale2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) {
                suma_dijagonale1 += kvadrat[i][j];
            }
            
            if (i + j == n - 1) {
                suma_dijagonale2 += kvadrat[i][j];
            }
        }
    }
    cout << abs(suma_dijagonale1 - suma_dijagonale2) << endl;


    #endif RJESENJE1


    #ifdef RJESENJE2

    int suma_dijagonale1 = 0, suma_dijagonale2 = 0;
    for (int i = 0; i < n; i++) {
        suma_dijagonale1 += kvadrat[i][i];
        suma_dijagonale2 += kvadrat[i][n - 1 - i];
    }
    cout << abs(suma_dijagonale1 - suma_dijagonale2) << endl;

    #endif RJESENJE2

    return 0;
}
