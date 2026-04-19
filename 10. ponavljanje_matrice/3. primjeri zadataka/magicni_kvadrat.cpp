#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cout << "Unijeti velicinu magicnog kvadrata: " << endl;
    cin >> n;
    cout << "Unijeti magicni kvadrat: " << endl;

    vector<vector<int> >  kvadrat(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> kvadrat[i][j]; 
        }
    }

    for (int i = 0; i < n; i++) {
        int suma_reda = 0;
        for (int j = 0; j < n; j++) {
            suma_reda += kvadrat[i][j];
        }
        cout << "Suma reda " << i << " je " << suma_reda << endl;
    }

    for (int j = 0; j < n; j++) {
        int suma_kolone = 0;
        for (int i = 0; i < n; i++) {
            suma_kolone += kvadrat[i][j];
        }
        cout << "Suma kolone " << j << " je " << suma_kolone << endl;
    }

    int suma_dijagonale = 0;
    for (int i = 0; i < n; i++) {
        suma_dijagonale += kvadrat[i][i];
    }
    cout << "Suma dijagonale je " << suma_dijagonale << endl;











    // Redovi i kolone, sa nizovima

    #ifdef SA_NIZOVIMA
    vector<int> sume_redova(n, 0), sume_kolona(n, 0);
    int suma_dijagonale = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sume_redova[i] += kvadrat[i][j];
            sume_kolona[j] += kvadrat[i][j];
            if (i == j) {
                suma_dijagonale += kvadrat[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "Suma reda " << i << " je " << sume_redova[i] << endl;
        cout << "Suma kolone " << i << " je " << sume_kolona[i] << endl;
    }
    cout << "Suma dijagonale je " << suma_dijagonale << endl;
    #endif

    return 0;
}
