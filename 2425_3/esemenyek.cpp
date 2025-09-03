#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;  // n: napok száma, m: rendelések száma, k: max rendelés naponta

    vector<map<int, vector<int>>> orders(n + 1); // orders[i]: map {határidő -> rendelés indexei} az i. napra
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        orders[a][b].push_back(i); // Rendelés hozzáadása a megfelelő naphoz és határidőhöz
    }

    int day = 1, kk = 0, idx = 1, ans = 0;   // day: aktuális nap, kk: naplózott rendelések száma, idx: aktuális nap index, ans: teljes kiszolgált rendelések
    vector<pair<int, int>> ansvec;           // Eredmények tárolása: {rendelés index, nap}

    while (day <= n) {
        if (orders[idx].size()) {  // Van rendelés az aktuális naphoz
            auto it = orders[idx].begin(); // Legkorábbi határidős rendelés
            if (it->first >= day) {       // Ha a rendelés még teljesíthető
                ansvec.push_back({it->second.back(), day}); // Hozzáadjuk az eredményekhez
                it->second.pop_back();     // Eltávolítjuk a rendelés indexét
                if (!it->second.size()) {
                    orders[idx].erase(it); // Ha üres a lista, töröljük a mapből
                }
                kk++;   // Napi rendelésszámláló növelése
                ans++;  // Teljesített rendelések száma
            } else {
                orders[idx].erase(it); // Ha lejárt a határidő, törlés
            }
        } else {
            idx++;          // Következő nap
            if (idx > day) { 
                day++;      // Ha elértük a következő napot, lépünk tovább
                kk = 0;     // Napi számláló visszaállítása
            }
        }
        if (kk == k) {     // Ha elértük a napi limitet
            kk = 0;        // Napi számláló nullázása
            day++;          // Következő nap
        }
    }

    cout << ans << endl;  // Teljesített rendelések száma
    for (auto& p : ansvec) {
        cout << p.first << " " << p.second << endl; // Index és nap kiírása
    }

    return 0;
}

/*
4 8 2
1 1
3 3
4 4
2 3
4 4
2 3
3 4
2 2
*/
