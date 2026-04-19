#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

    cout << "Upisi velicinu tabele: " << endl;
    int n, m;
    cin >> n >> m;

    cout << "Upisi tabelu: " << endl;
    vector<vector<char> > tabela(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tabela[i][j];
        }
    }

    
    cout << "Upisi poziciju macka cicka: " << endl;
    int r, k;
    cin >> r >> k;

    bool ima_tacka = 0;
    if (tabela[r - 1][k - 1] == '.') ima_tacka = 1;
    if (tabela[r - 1][k] == '.') ima_tacka = 1;
    if (tabela[r - 1][k + 1] == '.') ima_tacka = 1;
    if (tabela[r][k - 1] == '.') ima_tacka = 1;
    if (tabela[r][k + 1] == '.') ima_tacka = 1;
    if (tabela[r + 1][k - 1] == '.') ima_tacka = 1;
    if (tabela[r + 1][k] == '.') ima_tacka = 1;
    if (tabela[r + 1][k + 1] == '.') ima_tacka = 1;

    if (ima_tacka) {
        cout << "Cicko nije zatocen :)" << endl;
    } else {
        cout << "Cicko je zatocen :(" << endl;
    }


    #define RJESENJE_PETLJA
    #ifdef RJESENJE_PETLJA

    for (int red_susjeda = r-1; red_susjeda <= r+1; red_susjeda++) {
        for (int kolona_susjeda = k - 1; kolona_susjeda <= k + 1; kolona_susjeda++) {
            if (red_susjeda == r && kolona_susjeda == k) continue;

            if (red_susjeda < 0 || red_susjeda >= n || kolona_susjeda < 0 || kolona_susjeda >= m) continue;

            if (tabela[red_susjeda][kolona_susjeda] == '.') 
                ima_tacka = 1;
        }
    }

    #endif

    return 0;
}
