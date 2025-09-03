#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;

int main() {
    ios::sync_with_stdio(false); cin.tie(0); // Gyorsabb I/O

    int N, K, M;
    cin >> N >> K >> M;  // N: szakácsok száma, K: maximális szakácsszám, M: maximálsi ügyesség különbség
    vector<pii> US(N);   // Párok tárolása: (U, S)

    for (int i = 0; i < N; i++) {
        int U, S;
        cin >> U >> S;
        US[i] = {U, S};   // Beolvasott értékek tárolása
    }

    sort(US.begin(), US.end()); // Sorbarendezés U érték szerint

    int r = 0;
    ll ans = 0, ans2 = 0; // ans: maximális összeg, ans2: aktuális összeg

    for (int l = 0; l < N; l++) {
        // Jobb pointer mozgatása, amíg feltételek teljesülnek
        while (r < N && US[r].first - US[l].first <= M && r - l < K) {
            r++;
            ans2 += US[r].second; // Aktuális összeg növelése
        }

        ans = max(ans, ans2);      // Frissítjük a maximális összeget
        ans2 -= US[l].second;      // Bal oldali érték eltávolítása a csúszó ablakból
    }

    cout << ans << endl; // Eredmény kiírása

    return 0;
}

/*
10 3 2
8 2
11 1
12 6
3 1
1 4
2 7
6 3
7 2
4 8
5 1
*/
