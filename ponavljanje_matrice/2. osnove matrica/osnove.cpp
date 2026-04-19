#include <iostream>
#include <vector>

using namespace std;

int main() {

    // =================================================================================
    int prva_matrica[3][3] = {
        {3, 3, 3},
        {1, 2, 3},
        {4, 5, 6},
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << prva_matrica[i][j] << " ";
        }
        cout << endl;
    }

    int matrica_nula[3][4] = {};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrica_nula[i][j] << " ";
        }
        cout << endl;
    }

    // SLIDO
    int prazna_matrica[100][100];


    
    // =================================================================================

    int n = 5, m = 3;
    vector<int> prazan_niz(m); // quick pitanje
    vector<int> ispunjeni_niz(m, 0); // quick pitanje
    /**
     * Dijelovi komande:
     *  vector
     *  <int> = tip clanova
     *  ispunjeni_niz = ime varijable
     *  m = broj clanova
     *  0 = vrijednost svakog clana
     * 
     */

    vector<vector<int> > prva_vektor_matrica(n, vector<int>(m, 0));
    /**
     * Dijelovi komande:
     *  vector
     *  < vector<int> > = tip svakog clana
     *  prva_vektor_matrica = ime varijable
     *  n = broj clanova "vanjskog" vektora
     *  vector<int>(m, 0) = vrijenost svkakog clana = ispunjen niz od m nula
     */
    vector<vector<char> > matrica_charova(m, vector<char>(m, '.'));
    vector<string> matrica_charova(m); // Slido, kako ucinit da vrijednost ovoga bude ista kao vrijednost gornje linije (???)
    vector<vector<double> > matrica_decimalinih(n, vector<double>(m, 0));
    vector<vector<int> > matrica_prazna(n, vector<int>(m));


    // =================================================================================

























    cout << "Unesi dimenzije 1D niza (1 broj, n):" << endl;
    cin >> n;
    cout << "Unesi  1D niz:" << endl;
    vector<int> niz_1d(n);
    for (int i = 0; i < n; i++) {
        cin >> niz_1d[i];
    }

    cout << "Unesi dimenzije 2D niza (2 broja, n i m):" << endl;
    cin >> n >> m;
    cout << "Unesi 2D niz:" << endl;
    vector<vector<int> > niz_2d(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> niz_2d[i][j];
        }
    }
    // Primjer validnih unosa - format nije bitan


































    
    niz_2d.clear();



























    cout << "Unesi dimenzije 2D niza (2 broja, n i m):" << endl;
    cin >> n >> m;
    cout << "Unesi 2D niz:" << endl;
    // Alternativni nacin stvaranja matrice pomocu vektora.
    for (int i = 0; i < n; i++) {
        vector<int> red;
        for (int j = 0; j < m; j++) {
            int element;
            cin >> element;
            red.push_back(element);
        }
        niz_2d.push_back(red);
    }
    



    cout << endl;
    return 0;
}

