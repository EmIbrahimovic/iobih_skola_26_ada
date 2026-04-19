#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    // ============ Leksikografsko poredjenje stringova ==================
    vector<string> rjecnik = {
        "ajvar",
        "avion",
        "drvo",
        "suncokret",
        "zub"
    };

    string prva_rijec = rjecnik[0], druga_rijec = rjecnik[4];
    cout << "Uporedjuju se rijeci " << prva_rijec << " i " << druga_rijec << endl;


    // ====================================================================
    
    /*
    Leksikografski redoslijed
    Leksikografski redoslijed je isto što i abecedni redoslijed u rječniku. Poredimo dva stringa znak po znak, s lijeva na desno:

    Nađi prvu poziciju na kojoj se stringovi razlikuju. Koji god string ima manji znak na toj poziciji — taj string je manji.
    Ako se jedan string završi prije nego nađemo razliku — kraći string je manji.
    Ako su stringovi identični — jednaki su.

    Primjeri:
    "abc" < "abd"   → razlikuju se na poziciji 2: 'c' < 'd'
    "abc" < "abcd"  → "abc" se ne razlikuje od "abcd" do 3. pozicije, ali je kraći
    "abc" == "abc"  → jednaki
    "b"   > "az"    → razlikuju se na poziciji 0: 'b' > 'a'
    */

    















    // ====================================================================


    if (prva_rijec > druga_rijec) {
        cout << "Rijec " << prva_rijec << " dolazi poslije rijeci " << druga_rijec << endl;
    } else if (prva_rijec < druga_rijec) {
        cout << "Rijec " << druga_rijec << " dolazi poslije rijeci " << prva_rijec << endl;
    } else {
        cout << "Rijeci " << prva_rijec << " i " << druga_rijec << " su iste" << endl;
    }





















    // ====================================================================

    #ifdef PJESKE





    
    int poredjenje = 0;
    for (int i = 0; i < min(prva_rijec.length(), druga_rijec.length()); i++) {
        if (prva_rijec[i] > druga_rijec[i]) {
            poredjenje = 1;
            break;
        } else if (prva_rijec[i] < druga_rijec[i]) {
            poredjenje = 2;
            break;
        }
    }
    if (!poredjenje && prva_rijec.length() > druga_rijec.length()) {
        poredjenje = 1;
    } else if (!poredjenje && prva_rijec.length() < druga_rijec.length()) {
        poredjenje = 2;
    }

    if (poredjenje == 0) {
        cout << "Rijeci " << prva_rijec << " i " << druga_rijec << " su iste" << endl;
    } else if (poredjenje == 1) { 
        cout << "Rijec " << prva_rijec << " dolazi poslije rijeci " << druga_rijec << endl;
    } else {
        cout << "Rijec " << prva_rijec << " dolazi poslije rijeci " << druga_rijec << endl;
    }




    #endif PJESKE


    return 0;
}
