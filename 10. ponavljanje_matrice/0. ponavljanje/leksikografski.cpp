#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    // ============ Leksikografsko poredjenje stringova ==================

    string prva_rijec, druga_rijec;
    cin >> prva_rijec >> druga_rijec;
    cout << "Uporedjuju se rijeci " << prva_rijec << " i " << druga_rijec << endl;

    #ifdef AUTOMATSKI

    if (prva_rijec > druga_rijec) {
        cout << "Rijec " << prva_rijec << " dolazi poslije rijeci " << druga_rijec << endl;
    } else if (prva_rijec < druga_rijec) {
        cout << "Rijec " << druga_rijec << " dolazi poslije rijeci " << prva_rijec << endl;
    } else {
        cout << "Rijeci " << prva_rijec << " i " << druga_rijec << " su iste" << endl;
    }

    #endif AUTOMATSKI































    // ====================================================================

    #define PJESKE
    #ifdef PJESKE


    prva_rijec = "drvo";
    druga_rijec = "drvosjeca";
    int prvo_slovo_razlike = -1;
    for (int i = 0; i < min(prva_rijec.length(), druga_rijec.length()); i++) {
        if (prva_rijec[i] == druga_rijec[i]) {
            continue;
        } else {
            prvo_slovo_razlike = i;
            break;
        }
    }

    if (prvo_slovo_razlike == -1) {
        if (prva_rijec.length() < druga_rijec.length()) {
            cout << "Rijec " << prva_rijec << " dolazi prije rijeci " << druga_rijec << endl;
        } else if (prva_rijec.length() > druga_rijec.length()) {
            cout << "Rijec " << prva_rijec << " dolazi poslije rijeci " << druga_rijec << endl;
        } else {
            cout << "Rijeci su iste" << endl;
        }
    } else if (prva_rijec[prvo_slovo_razlike] < druga_rijec[prvo_slovo_razlike]) {
        cout << "Rijec " << prva_rijec << " dolazi prije rijeci " << druga_rijec << endl;
    } else if (prva_rijec[prvo_slovo_razlike] > druga_rijec[prvo_slovo_razlike]) {
        cout << "Rijec " << prva_rijec << " dolazi poslije rijeci " << druga_rijec << endl;
    }

    #endif PJESKE












    

    #ifdef PJESKE_NAPREDNO
    
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

    #endif PJESKE_NAPREDNO


    return 0;
}
