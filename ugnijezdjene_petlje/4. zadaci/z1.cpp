#include <iostream>

using namespace std;

int main() {

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a = 0;
        cin >> a;
        
        a += 2;
        cout << "Vas broj nije " << a << endl;
    }

    return 0;
}
