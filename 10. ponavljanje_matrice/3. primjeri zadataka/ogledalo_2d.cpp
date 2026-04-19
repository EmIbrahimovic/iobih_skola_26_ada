#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n, m;
    cout << "Unijeti velicinu 2d niza: " << endl;
    cin >> n, m;
    cout << "Unijeti 2d niz: " << endl;

    vector<vector<int> > niz(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> niz[i][j]; 
        }
    }
    
    vector<vector<int> > izvrnuti_niz(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            izvrnuti_niz[i][j] = niz[i][n - j - 1];
        }
    }

    cout << "Izvrnuti niz" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << izvrnuti_niz[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Spojeni" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << niz[i][j] << " ";
        }
        for (int j = 0; j < m; j++) {
            cout << izvrnuti_niz[i][j] << " ";
        }
        cout << endl;
    }


    // ====================================================================

    #ifdef DRUGI_NACIN
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp = niz[i][j];
            niz[i][j] = niz[i][n - j - 1];
            niz[i][n - j - 1] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << niz[i][j] << " ";
        }
        cout << endl;
    }
    #endif

    return 0;
}
