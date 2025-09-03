#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); // Gyors I/O

    int n, m;
    cin >> n >> m; // n: célpozíciók száma, m: ugrások száma

    vector<int> ugrasok(n, -1); // ugrasok[i]: minimum ugrások száma az i-edik pozícióig
    ugrasok[0] = 0;             // Kiinduló pozícióhoz 0 ugrás szükséges

    vector<pair<int, int>> honnan(n); // honnan[i]: {hányadik ugrás, mekkora lépés} a pozíció eléréséhez

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= m; j++) {
            int x;
            cin >> x; // j-edik ugrás hossza az i-edik pozícióban
            if (i - x >= 0 && ugrasok[i - x] >= 0) { // Ha elérhető az előző pozíció
                if (ugrasok[i] == -1 || ugrasok[i] > ugrasok[i - x] + 1) {
                    ugrasok[i] = ugrasok[i - x] + 1;    // Frissítjük a minimum ugrásszámot
                    honnan[i] = {j, x};                // Mentjük a választott ugrást
                }
            }
        }
    }

    cout << ugrasok[n - 1] << endl; // Minimális ugrások száma a célhoz

    if (ugrasok[n - 1] != -1) {
        int idx = n - 1;
        for (int x = 0; x < ugrasok[n - 1]; x++) {
            cout << honnan[idx].first << " ";  // Kiírjuk a választott ugrás indexét
            idx -= honnan[idx].second;         // Visszalépünk az előző pozícióra
        }
        cout << endl;
    }

    return 0;
}
/*
5 5
0 0 0 0 0
0 5 0 1 2
0 0 0 0 0
0 0 0 0 0
0 3 0 2 1
*/
